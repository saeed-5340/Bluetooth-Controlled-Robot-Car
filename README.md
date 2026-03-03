# Bluetooth Controlled Robot Car

This repository contains the Arduino code for a simple **Bluetooth-controlled robot car**. The robot uses an Arduino board, an L298N-based motor driver (Adafruit Motor Shield compatible), and a Bluetooth module (HC-05/HC-06) to receive commands from a smartphone or computer. It can move forward, backward, turn left/right, and perform diagonal movements.

## 📋 Overview

The robot is controlled wirelessly via Bluetooth serial communication. A smartphone app (like "Arduino Bluetooth RC Car" or any serial terminal) sends single-character commands to the robot. The Arduino interprets these commands and drives two DC motors accordingly using the `AFMotor` library.

## 🛠️ Components Required

| Component                   | Quantity |
|-----------------------------|----------|
| Arduino Uno (or compatible) | 1        |
| Motor Driver Shield (L293D based, e.g., Adafruit Motor Shield v1) or L298N module with AFMotor compatible wiring | 1 |
| HC-05 / HC-06 Bluetooth Module | 1    |
| DC Motors with Wheels       | 2        |
| Robot Chassis               | 1        |
| Power Supply (Battery)      | 1        |
| Jumper Wires                | many     |

> **Note:** The code uses the `AFMotor` library, which is designed for Adafruit Motor Shields. If you are using a different motor driver, you may need to adapt the code.

## 🔌 Pin Connections

### Motor Driver (AFMotor compatible)
The motors are connected to the shield's **M3** and **M4** outputs (as defined in the code):
- Motor 3 → left motor (or right, depending on your wiring)
- Motor 4 → right motor (or left)

Adjust the motor numbers in the code if your wiring differs.

### Bluetooth Module (HC-05/HC-06)
The Bluetooth module is connected to the Arduino’s analog pins **A0** and **A1** using software serial:

| Bluetooth Pin | Arduino Pin |
|---------------|-------------|
| TX            | A0 (RX)     |
| RX            | A1 (TX)     |
| VCC           | 5V          |
| GND           | GND         |

**⚠️ Important:**  
- HC-05/HC-06 modules typically operate at 3.3V logic levels. While many are 5V tolerant on the RX pin, the TX pin outputs 3.3V which is safe for Arduino (5V logic sees 3.3V as HIGH). However, to be safe, you can use a voltage divider on the RX line (from Arduino TX to Bluetooth RX).  
- If you use an HC-05 in master/slave mode, ensure it is configured correctly (default baud rate 9600).

## 💻 Installation

1. **Install Arduino IDE** (if not already installed).
2. **Install the AFMotor library**:
   - Open Arduino IDE, go to **Sketch → Include Library → Manage Libraries**.
   - Search for "AFMotor" and install the Adafruit Motor Shield library.
3. **Clone or download this repository**.
4. **Open the `.ino` file** in Arduino IDE.
5. **Select your board and port** (e.g., Arduino Uno).
6. **Upload the code** to your Arduino.

## 📱 Usage

1. **Power up the robot** (connect the battery).
2. **Pair your smartphone/computer** with the Bluetooth module.  
   - Default PIN is usually `1234` or `0000`.
3. **Open a Bluetooth Serial app** (e.g., "Serial Bluetooth Terminal" on Android) and connect to the paired device.
4. **Send single-character commands** from the app to control the robot.

### Commands List

| Command | Action                     |
|---------|----------------------------|
| `F`     | Move forward               |
| `B`     | Move backward              |
| `L`     | Turn left (pivot)          |
| `R`     | Turn right (pivot)         |
| `I`     | Forward right (diagonal)   |
| `G`     | Forward left (diagonal)    |
| `H`     | Backward left (reverse diagonal) |
| `J`     | Backward right (reverse diagonal) |

> Each movement lasts for a short delay (20 ms) and then motors are released (stopped). This creates a "pulse" of motion. For continuous movement, you may want to modify the code to keep motors running until a stop command is received.

## 🧠 Code Explanation

- The code uses `SoftwareSerial` on pins A0 (RX) and A1 (TX) to communicate with the Bluetooth module.
- Two motors are controlled via the `AF_DCMotor` objects `motor3` and `motor4` (connected to channels 3 and 4 of the motor shield).
- In `loop()`, the program checks if a character is available from Bluetooth. If yes, it reads the character and calls the corresponding movement function.
- Each movement function sets the motor direction, applies a small delay, and then releases the motors (`run(RELEASE)`). This gives a short burst of motion. For smoother control, you can modify the functions to keep motors running and add a separate stop command.

## ⚠️ Troubleshooting

- **No response to commands:**  
  - Check Bluetooth pairing and baud rate (9600).  
  - Verify wiring, especially TX/RX connections.  
  - Ensure motors are properly connected to the motor driver and powered.
- **Motors run erratically:**  
  - Check power supply voltage (motors may need more current).  
  - Try increasing the delay in movement functions.
- **Bluetooth module not detected:**  
  - Ensure it is powered with 3.6V–6V.  
  - Use a voltage regulator if necessary.
