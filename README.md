# TinyML-realTimeMachineStateDetectionSystem
 A project that uses an ESP32 with TensorFlow Lite Micro for sensor fusion. The project analyzes input values, performs sensor fusion, and indicates the machine's status using LEDs.

## Overview

The ESP32 Sensor Fusion Project is designed to monitor and analyze machine status using sensor data processed by TensorFlow Lite Micro on the ESP32 platform. The project combines edge computing capabilities with machine learning to provide real-time insights into the health of a machine.

### Key Features:

1. **TensorFlow Integration:** Utilizes TensorFlow Lite Micro in the form of EloquentTinyML.h library to run a machine learning model on the ESP32 for sensor fusion and analysis.

2. **LED Indicators:** Employs two LEDs, a green LED indicating normal machine operation and a red LED signaling recovery or abnormal conditions.

3. **Customizable Model:** The project is flexible and allows users to train their own TensorFlow models to adapt to specific machine environments and requirements.

### How It Works:

- The ESP32 reads a string of 50 comma-separated sensor values from the serial port.
- The TensorFlow Lite Micro model processes the input data, performing sensor fusion and analysis.
- Based on the analysis, the system determines whether the machine is operating normally (green LED) or requires attention (red LED).
- Users can train their own models and adjust parameters for customization.

### Use Cases:

- Predictive Maintenance: Detect potential issues before they lead to machine failure.
- Condition Monitoring: Continuously monitor the state of the machine to ensure optimal performance.
- Edge AI in Industrial IoT: Implement machine learning at the edge for real-time decision-making.

This project aims to showcase the capabilities of the ESP32 and TensorFlow Lite Micro in the context of sensor fusion, enabling users to build intelligent and responsive systems for various applications.

# Hardware and Software Stack

- `ESP32` : The Microcontoller board used is ESP32-Wrover Module.
- LEDs and Wires
- `Tensorflow` : Used for model creation.
- `tinymlgen` : A python library that is used to convert the generated model file into a hex array.
- `EloquentTinyML.h` : An arduino library that is used for interfacing the ESP32 with the hex array generated previously.


# Working Demo
https://github.com/MuhmmadAbrar/TinyML-realTimeMachineStateDetectionSystem/assets/88892675/9b5b2ecf-0419-4bcb-8cc6-26d3c93b34f3

