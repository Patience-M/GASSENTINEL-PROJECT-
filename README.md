# GasSentinel
### Home-Based Gas Leak Detection and Mitigation System

GasSentinel is an IoT-based smart home safety system designed to detect Liquefied Petroleum Gas (LPG) leaks in real time and automatically respond before a disaster occurs. The system not only alerts users but also actively mitigates gas leaks by shutting off the gas supply, activating ventilation, and sending emergency SMS notifications.

---

## Overview

Gas leaks are among the leading causes of household fires and explosions. Traditional gas detectors only notify users after a leak has occurred, requiring human intervention.

GasSentinel provides a proactive solution by continuously monitoring gas concentrations and automatically initiating safety measures whenever dangerous gas levels are detected.


## Features

- 🔥 Real-time LPG leak detection
- 🚨 Audible buzzer alarm
- 💡 LED visual warning indicators
- 🔒 Automatic gas shut-off using a servo motor
- 🌬️ Automatic exhaust fan activation
- 📱 GSM-based SMS notifications
- ⚡ Fast response time (<3 seconds)
- 🏠 Designed for residential environments
- 💰 Low-cost and scalable solution

---

## Hardware Components

- Arduino Uno
- MQ-2 Gas Sensor
- GSM Module (SIM800L/SIM900)
- Servo Motor
- Exhaust Fan
- Buzzer
- LEDs
- Relay Module
- Power Supply

---

## Software Used

- Arduino IDE
- Wokwi Simulator
- C/C++
- Embedded Systems Programming

---

## System Workflow

1. MQ-2 sensor continuously monitors LPG concentration.
2. Arduino processes sensor readings.
3. Warning gas levels trigger:
   - LED indicators
   - Buzzer alarm
4. Dangerous gas levels trigger:
   - Automatic gas shut-off
   - Exhaust fan activation
   - SMS notification to the homeowner

### Requirements

- Arduino IDE
- Arduino Uno
- MQ-2 Gas Sensor
- GSM Module
- Servo Motor
- Required electronic components

### Installation

1. Clone the repository.

```bash
git clone https://github.com/yourusername/GasSentinel.git
```

2. Open the Arduino project in Arduino IDE.

3. Install the required libraries.

4. Connect the hardware according to the circuit diagram.

5. Upload the code to the Arduino Uno.

6. Test the system using LPG or the Wokwi simulator.

---

## Testing

The system has been tested for:

- Gas detection accuracy
- Response time
- Automatic mitigation
- SMS notification
- Hardware reliability

---

## Project Objectives

- Detect LPG leaks in real time.
- Automatically shut off the gas supply.
- Activate ventilation.
- Notify homeowners via SMS.
- Improve household safety using affordable IoT technology.

---

## Applications

- Homes
- Apartments
- Student hostels
- Restaurants
- Small businesses
- Kitchens

---

## Future Improvements

- Mobile application
- Wi-Fi/Cloud monitoring
- Machine learning for false alarm reduction
- Battery backup
- Mobile dashboard
- Multiple gas sensor support

---

## 👨‍💻 Authors

**Mukisa Patience**

**Aywee Innocent**

Department of Computer Science

Gulu University

---

## 🙏 Acknowledgements

Special thanks to:

- Gulu University
- Department of Computer Science
- Project Supervisor Mr Abandu Jackson 
- Everyone who supported the development and testing of GasSentinel.

---

⭐ If you found this project useful, please consider giving it a **Star** on GitHub!
