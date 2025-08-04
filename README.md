# PC-Based Data Acquisition System with Fault Alerts
An embedded system project using LPC2148 that monitors temperature via LM35 sensor, timestamps data using RTC, logs it to a PC via UART, and provides real-time fault alerts if temperature exceeds a threshold.

## 🔍 Overview

This project implements a PC-based data acquisition system using the **LPC2148 microcontroller**. It continuously monitors temperature using the **LM35 sensor**, timestamps readings via the on-chip **RTC**, and sends the data to a PC using **UART communication**. When the temperature exceeds a defined threshold (e.g., 45°C), the system triggers a fault alert via an **LED or buzzer** and logs the alert.

---

## 🧩 Features

- 📡 Real-time temperature monitoring using **LM35**
- ⏰ Timestamping using **RTC**
- 📟 Real-time data display on **16x2 LCD**
- ⌨️ Time editing through **keypad** and **external interrupt**
- 🖥️ Data logging via **UART** to Serial Terminal
- 🚨 Fault alert with **LED/Buzzer**
- ✅ Clear display formatting for normal and alert messages

---



## 🔧 Requirements

### Hardware

- LPC2148 Microcontroller
- LM35 Temperature Sensor
- 16x2 LCD Display
- 4x4 Keypad
- Push Button (for interrupt)
- LED or Buzzer (for alert)
- MAX232 (for UART communication)

### Software

- Embedded C
- Keil µVision (Compiler)
- Flash Magic (Flashing Tool)
- Serial Terminal (e.g., Tera Term / RealTerm / PuTTY)

---

## 🔁 Workflow

1. **System Initialization**: UART, RTC, ADC, LCD, Keypad, and external interrupt setup.
2. **Monitoring**: Temperature is read via ADC and timestamped.
3. **Data Logging**: Formatted output sent to PC and displayed on LCD.
4. **Fault Detection**: If temperature > 45°C, triggers alert and logs as `[ALERT]`.
5. **Time Editing Mode**: Activated via external interrupt. User can edit time using the keypad.

---
