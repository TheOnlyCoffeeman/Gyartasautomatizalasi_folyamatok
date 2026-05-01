# Gyartasautomatizalasi_folyamatok – Servo Control with Node-RED and Arduino

This project demonstrates a simple manufacturing automation control system where two servo motors are controlled through a **Node-RED dashboard** communicating with an **Arduino microcontroller via serial communication**.

The system provides a graphical interface where users can adjust servo angles using sliders and send commands to the Arduino, which then moves the servos accordingly.

---

## Project Purpose

The goal of this project is to demonstrate:

- Visual control using **Node-RED**
- **Serial communication** between a PC and an Arduino
- Control of multiple **servo motors**
- A basic **automation control interface**

This setup can serve as a starting point for robotics, manufacturing automation, or educational automation projects.

---

## Project Structure

```
.
├── flows.json      # Node-RED flow configuration
├── servo.ino       # Arduino code controlling the servos
└── README.md
```

---

## Hardware Requirements

- Arduino (Uno / Nano or compatible)
- 2 × Servo motors
- USB connection to the computer
- Proper power supply for the servos

### Pin Configuration

| Servo | Arduino Pin |
|------|-------------|
| Servo 1 | D8 |
| Servo 2 | D9 |

---

## Software Requirements

- Arduino IDE
- Node-RED
- Node-RED Dashboard
- Serial communication via USB

---

## Arduino Program

The Arduino code performs the following tasks:

1. Initializes the servo motors  
2. Sets a default **home position**  
3. Receives angle commands via the **serial port**  
4. Moves the servos to the requested positions  
5. Sends the current positions back to Node-RED  

### Command Format

Commands are sent as a comma-separated string:

```
angle1,angle2
```

Example:

```
45,120
```

Meaning:

- Servo 1 → 45°
- Servo 2 → 120°

---

## Node-RED Flow

The Node-RED flow provides a **web dashboard interface** to control the system.

### Dashboard Components

- Servo 1 slider  
- Servo 2 slider  
- Send button  
- Home position button  
- Servo position gauges  

### Control Logic

1. The user sets the servo angles using sliders  
2. The **Send** button transmits the angles to the Arduino  
3. Node-RED communicates with the Arduino through the serial port  
4. The Arduino moves the servos  
5. The current positions are sent back and displayed on the dashboard  

---

## Installation

### 1. Upload the Arduino Code

1. Open `servo.ino` in **Arduino IDE**  
2. Connect your Arduino to the computer  
3. Select the correct **board** and **serial port**  
4. Upload the program  

---

### 2. Import the Node-RED Flow

In Node-RED:

```
Menu → Import → flows.json
```

This will create the dashboard interface.

---

### 3. Configure the Serial Port

Set the correct serial port in the Node-RED flow.

Example:

Linux / macOS

```
/dev/ttyACM0
```

Windows

```
COM3
```

Baud rate:

```
115200
```

---

## Dashboard Usage

The Node-RED dashboard is available at:

```
http://localhost:1880/ui
```

From the dashboard you can:

- Move the servo motors
- Monitor their current positions
- Reset them to the home position

---

## Home Position

The **Home Position** button moves both servos to:

```
90°, 90°
```

This represents the neutral starting position of the system.

---

## Possible Improvements

- SCARA robot arm control  
- Kinematics calculations  
- Automated motion sequences  
- Full manufacturing cycle control  
- MQTT / IoT integration  
- Sensor or camera integration  

---

## License

Educational / demonstration project.

---

## Author

TheOnlyCoffeeman