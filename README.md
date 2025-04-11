# 🍦 Automated Ice Cream Cone Crimping Machine

An innovative home garage automation project that transforms a manual ice cream cone crimping machine into a fully automated system using Arduino, IR sensors, relays, and a mechanical winch setup. Built for efficiency, precision, and hands-free operation.

---

## 📽️ Project Type  
**DIY Home Automation | Arduino | Electromechanical System**

---

## 📍 Location  
**Personal Garage – Converted into a Smart Automation Studio**

---

## ⚙️ System Overview

This project automates a **manual cone crimping machine** (originally by *Maru Machinery*) through sensor-based detection and electromechanical actuation. A seamless integration of:

- **IR Proximity Sensors**  
- **Arduino Microcontroller**  
- **DC Motor with Relay Control**  
- **AC Winch Motor for Crimping Lever**  
- **Reed Switch for Position Feedback**  
- **Mechanical Spring-based Reset**

---

## 🔁 Workflow

1. **Cone Detection**  
   - An IR sensor detects a cone drop in the slot.
2. **Disc Slot Rotation**  
   - A 12V DC motor rotates the disc via a belt-pulley system.
3. **Crimp Zone Detection**  
   - Another IR sensor senses arrival at the crimping position.
4. **Crimp Actuation**  
   - Arduino triggers a relay cascade to power an AC winch motor.
   - The winch pulls a rope linked to the crimp lever.
5. **Crimp Completion Detection**  
   - A reed switch senses spring tension and halts the system.
6. **Auto Reset**  
   - Spring action resets the lever; a metal ejector slams the crimped cone to the next slot.

---

## 🧠 Tech Stack

- **Microcontroller:** Arduino Nano  
- **Sensors:** IR Proximity, Reed Switch  
- **Actuators:** 12V DC Motor, AC Motor via 30A Relay  
- **Control System:** 2-level Relay Cascade (Low to High Power)  
- **Mechanical:** Pulley, Spring, Winch, Rope, Lever

---

## 💻 Arduino Code

> **📌 Section Placeholder**  
> Full code with inline explanation will be provided and explained in the documentary video.  
> (Insert Arduino code with `// Detailed comments` once final)

---

## 🏠 Setup Requirements

- 12V DC Motor  
- AC Winch Motor  
- Flyback Diodes  
- Relay Modules (12V and 30A)  
- IR Sensors  
- Reed Switch  
- Crimping Machine (Manual)  
- Rope, Pulley, Spring, Metal Strips  
- Power Supply (DC and AC)

---

## 🎬 Video Documentary

The system will be presented in a **English** documenting:

- Design philosophy  
- Technical implementation  
- Code walkthrough  
- Real-world testing  
- DIY garage setup aesthetics

---

## 👤 Creator

**Shaikh Zaka Tabish**  
Engineer | Innovator | Automation Enthusiast  
_Focused on sophisticated, simple, short, sweet problem-solving._

---

## 🧭 License

This project is licensed under the [MIT License](./LICENSE) – open for improvement and non-commercial adaptation.


