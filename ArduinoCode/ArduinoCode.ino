// pin assignments
const int sensorAPin    = 2;  // sensor A input (using internal pull-up)
const int sensorBPin    = 3;  // sensor B input (using internal pull-up)
const int motorPin      = 4;  // motor control output
const int crimpMotorPin = 5;  //crimping mchanism motor pin.
const int tensionPin    = 6;  // tension limiter switch break (High whent it is sctive).

// define motor states based on inverted logic
const int MOTOR_ON  = LOW;   // motor turns on when the pin is LOW
const int MOTOR_OFF = HIGH;  // motor turns off when pin is HIGH

// some variables to store previous states
bool prevA = false;
bool prevB = false;
bool prevMotor = false;

void setup() {
  Serial.begin(9600);
  
 // use internal pull-up resistors for stable sensor readings
  pinMode(sensorAPin, INPUT_PULLUP);
  pinMode(sensorBPin, INPUT_PULLUP);
  pinMode(tensionPin, INPUT_PULLUP);
  
// Set motor pins as outputs and ensure they're off initially
  pinMode(motorPin, OUTPUT);
  pinMode(crimpMotorPin, OUTPUT);
  digitalWrite(motorPin, MOTOR_OFF);
  digitalWrite(crimpMotorPin, MOTOR_OFF);
}

void I() {
  digitalWrite(motorPin, MOTOR_ON);
}

void O() {
  digitalWrite(motorPin, MOTOR_OFF);
}

bool A() {
  return digitalRead(sensorAPin) == LOW;
}

bool B() {
  return digitalRead(sensorBPin) == LOW;
}

bool Crimp() {
  delay(100);
  if (digitalRead(motorPin) != MOTOR_ON) {
    digitalWrite(crimpMotorPin, MOTOR_ON);
   
    while (digitalRead(tensionPin) == LOW);
    digitalWrite(crimpMotorPin, MOTOR_OFF);
   
  }
  delay(200);
  return true;
  
}

void printStatus(bool a, bool b, bool motor) {
  if (a != prevA || b != prevB || motor != prevMotor) {
    Serial.print("Sensor A: ");
    Serial.print(a ? "ACTIVE" : "INACTIVE");
    Serial.print(" | Sensor B: ");
    Serial.print(b ? "ACTIVE" : "INACTIVE");
    Serial.print(" | Motor: ");
    Serial.println(motor ? "ON" : "OFF");

    prevA = a;
    prevB = b;
    prevMotor = motor;
  }
}

void loop() {
  bool a = A();
  bool b = B();
  bool motor = digitalRead(motorPin) == MOTOR_ON;

  if (a && !b) {
    I();
    printStatus(a, b, true);
    while (!B());
  } 
  else if (!a && b) {
    O();
    Crimp();
    printStatus(a, b, false);
    while (!A());
  } 
  else if (!a && !b) {
    O();
    printStatus(a, b, false);
    while (A());
  } 
  else if (a && b) {
    I();
    printStatus(a, b, true);
    while (B());
    while (!B());
  }

  printStatus(A(), B(), digitalRead(motorPin) == MOTOR_ON);
}