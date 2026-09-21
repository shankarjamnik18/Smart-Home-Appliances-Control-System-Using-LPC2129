# 🏠 Smart Home Appliance Control System Using LPC2129

## 📌 Project Overview

The **Smart Home Appliance Control System** is an ARM7-based embedded project developed using the **LPC2129 microcontroller** and **Embedded C**. The system provides two methods of controlling home appliances: **UART-based control** and **GPIO push-button control**.

LEDs are used as indicators to represent different home appliances. A mode-selection switch allows the user to switch between UART and manual GPIO control.

The complete system was designed and tested using **Proteus simulation**.

## 🎯 Objectives

* Control home appliances using an LPC2129 microcontroller.
* Implement UART communication for remote command-based control.
* Implement GPIO-based manual appliance control.
* Use UART interrupt-based reception.
* Provide LED indicators for appliance status.
* Understand register-level programming on the ARM7 LPC2129.
* Simulate and test the complete system using Proteus.

## ⚙️ Main Features

* **LPC2129 ARM7TDMI-S microcontroller**
* **UART0 communication at 9600 baud**
* **UART receive interrupt**
* **GPIO-based push-button control**
* **Mode selection between UART and GPIO**
* **Three LED indicators**
* **Software debouncing using delay**
* **Register-level Embedded C programming**
* **Proteus simulation**
  
## 🔄 System Working

The system has two operating modes:

### 1. UART Mode

Initially, the system operates in UART mode.

The user sends commands through the UART terminal:

| Command | Operation |
| ------- | --------- |
| `a`     | LED1 OFF  |
| `b`     | LED1 ON   |
| `c`     | LED2 OFF  |
| `d`     | LED2 ON   |

UART reception is handled using the **UART0 interrupt**. When a character is received, the UART interrupt service routine reads the data from `U0RBR` and performs the corresponding LED operation.

### 2. GPIO Mode

Pressing **SW3** changes the system to GPIO mode.

In GPIO mode:

| Switch | Operation                     |
| ------ | ----------------------------- |
| SW1    | Toggle LED1                   |
| SW2    | Toggle LED2                   |
| SW3    | Switch between UART/GPIO mode |

**LED3** indicates the GPIO operating mode.

## 🧠 Operating Logic

                 ┌─────────────────────┐
                 │      LPC2129        │
                 │      ARM7 MCU       │
                 └──────────┬──────────┘
                            │
                 ┌──────────┴──────────┐
                 │                     │
              UART Mode            GPIO Mode
                 │                     │
          UART Virtual Terminal    Push Buttons
                 │                     │
             Commands             SW1 / SW2
          a / b / c / d               │
                 │                     │
                 └──────────┬──────────┘
                            │
                     LED Indicators
                      LED1 / LED2
                            │
                    Home Appliances
                       Indicators

## 🔌 Pin Configuration

### UART

| LPC2129 Pin | Function |
| ----------- | -------- |
| P0.0        | TXD0     |
| P0.1        | RXD0     |

### Switches

| Pin   | Function             |
| ----- | -------------------- |
| P0.14 | SW1                  |
| P0.15 | SW2                  |
| P0.16 | SW3 / Mode Selection |

### LEDs

| Pin   | Function              |
| ----- | --------------------- |
| P0.17 | LED1                  |
| P0.18 | LED2                  |
| P0.19 | LED3 / Mode Indicator |

## 🛠️ Technologies Used

* **Microcontroller:** LPC2129
* **Architecture:** ARM7TDMI-S
* **Programming Language:** Embedded C
* **Communication:** UART
* **I/O:** GPIO
* **Interrupt:** UART0 Receive Interrupt
* **IDE:** Keil µVision
* **Simulation:** Proteus
* **UART Baud Rate:** 9600 bps

## 🧰 Software & Tools
Keil µVision
Proteus
Embedded C
LPC2129
UART Virtual Terminal

## 🧪 Proteus Simulation

The project was simulated in **Proteus** using:

* LPC2129 microcontroller
* LEDs
* Push buttons
* UART Virtual Terminal
* Crystal oscillator
* Resistors
* Power supply connections

The Proteus simulation demonstrates both **UART-based appliance control** and **manual GPIO-based control**.

## 💡 Applications

This project demonstrates the basic concept of:

* Smart home appliance control
* Microcontroller-based automation
* Serial command-based control
* Manual appliance control
* Embedded system interfacing

In a practical system, the LED indicators can be replaced by suitable **relay driver circuits** to control actual appliances safely.

## 📚 Key Learning

Through this project, I gained practical experience in:

* LPC2129 ARM7 microcontroller programming
* UART communication
* UART interrupt handling
* GPIO programming
* Register-level programming
* Switch debouncing
* LED control
* Embedded C
* Proteus simulation
* Embedded system debugging

## 🚀 Future Improvements

The project can be extended by adding:

* Relay-based control for real appliances
* LCD status display
* Bluetooth or Wi-Fi connectivity
* Mobile application control
* ESP8266/ESP32 connectivity
* Password-based access
* Multiple appliance control
* IoT-based remote monitoring

## 👨‍💻 Project Summary

**Smart Home Appliance Control System Using LPC2129** demonstrates how an ARM7 microcontroller can be used to implement a simple home automation system with **UART communication, GPIO control, interrupts, and LED-based appliance indication**.

The project combines **Embedded C programming and Proteus simulation** to demonstrate practical embedded-system design and control.

### 🔖 Keywords

`LPC2129` `ARM7` `Embedded C` `UART` `GPIO` `Interrupt` `Proteus` `Keil` `Home Automation` `Smart Home` `Microcontroller` `Embedded Systems`
