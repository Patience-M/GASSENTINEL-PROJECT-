README

A HOME-BASED GAS LEAK DETECTION AND MITIGATION SYSTEM (GASSENTINEL)

Project Overview

GasSentinel is a smart home-based gas leak detection and mitigation system designed to enhance household safety by providing real-time detection of Liquefied Petroleum Gas (LPG) leaks. The system continuously monitors gas concentration levels and automatically initiates safety measures when a leak is detected, helping to prevent fires, explosions, and health hazards.

Objectives

- Detect LPG gas leaks in real time.
- Alert users through audible and visual alarms.
- Automatically mitigate gas leaks by activating safety mechanisms.
- Improve household safety using affordable and reliable technology.
- Reduce the risk of property damage and loss of life caused by gas leaks.

Features

- Real-time LPG gas monitoring.
- Automatic gas leak detection.
- Audible buzzer alarm.
- Visual LED warning indicators.
- Automatic activation of an exhaust fan and gas shut-off mechanism.
- LCD display for system status.
- Low-cost and energy-efficient design.

Hardware Components

- Arduino Uno
- MQ-2 Gas Sensor
- Servo Motor
- Exhaust Fan
- Buzzer
- LEDs
- 16×2 LCD Display (I2C)
- Breadboard
- Jumper Wires
- Power Supply

Software Requirements

- Arduino IDE
- C/C++ Programming Language
- Required Arduino Libraries:
  - Wire.h
  - LiquidCrystal_I2C.h
  - Servo.h

System Operation

1. The MQ-2 sensor continuously monitors LPG concentration.
2. When gas levels exceed the predefined threshold, the Arduino processes the sensor data.
3. The buzzer and warning LEDs are activated to alert occupants.
4. The servo motor automatically closes the gas valve.
5. The exhaust fan turns on to improve ventilation.
6. The LCD displays the current system status and gas leak warning.

Installation

1. Assemble the hardware components according to the circuit diagram.
2. Install the Arduino IDE.
3. Install the required Arduino libraries.
4. Upload the GasSentinel program to the Arduino Uno.
5. Power the system and verify proper operation.

Testing

The system should be tested by exposing the MQ-2 sensor to a controlled LPG source. Verify that:

- Gas is detected correctly.
- The buzzer sounds.
- Warning LEDs illuminate.
- The servo closes the gas valve.
- The exhaust fan activates.
- The LCD displays the appropriate warning message.

Project Structure

- "/Source_Code" – Arduino program files.
- "/Circuit_Diagram" – System wiring diagrams.
- "/Documentation" – Project report and related documentation.
- "/Images" – System photographs and screenshots.
- "/Libraries" – Required Arduino libraries (if included).

Future Improvements

- Integration with IoT for remote monitoring.
- SMS and mobile application notifications.
- Cloud-based data logging.
- Battery backup for power outages.
- Mobile dashboard for real-time system monitoring.

Authors

This project was developed as part of an academic research project titled:

A Home-Based Gas Leak Detection and Mitigation System (GasSentinel).

License

This project is intended for academic and research purposes. Users are free to study, modify, and improve the system with appropriate acknowledgment of the original work.

Acknowledgement

We sincerely thank our supervisors, lecturers, colleagues, and all individuals who provided guidance, technical support, and encouragement throughout the development of the GasSentinel project. Above all, we thank the Almighty God for His grace, wisdom, and strength that made the successful completion of this project possible.
