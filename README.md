# Voice-Controlled LED using HC-05 & Arduino

## 📌 Overview
This project allows users to control LEDs using **voice commands** via the **HC-05 Bluetooth module** and an **Arduino board**. By sending commands through a Bluetooth terminal app, users can turn LEDs ON or OFF using simple voice inputs.

## 🛠️ Components Required
- Arduino Uno/Nano
- HC-05 Bluetooth Module
- LEDs (Red, Yellow, Green)
- Resistors (220Ω for each LED)
- Jumper Wires
- Android phone with a Bluetooth Terminal app

## 🔧 Circuit Diagram
- **HC-05 to Arduino:**
  - VCC → 5V
  - GND → GND
  - TX → RX (Pin 0)
  - RX → TX (Pin 1)
- **LED Connections:**
  - Green LED → Pin 3
  - Yellow LED → Pin 4
  - Red LED → Pin 5

## 💻 Code
```cpp
int Green = 3;
int Yellow = 4;
int Red = 5;

void setup() {
  Serial.begin(9600);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT);

  // Ensure all LEDs are off initially
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String voice = Serial.readString();
    voice.trim();
    voice.toLowerCase();

    Serial.println("Command Received: " + voice);

    if (voice == "green") {
      digitalWrite(Green, HIGH);
    } else if (voice == "green off") {
      digitalWrite(Green, LOW);
    } else if (voice == "yellow") {
      digitalWrite(Yellow, HIGH);
    } else if (voice == "yellow off") {
      digitalWrite(Yellow, LOW);
    } else if (voice == "red") {
      digitalWrite(Red, HIGH);
    } else if (voice == "red off") {
      digitalWrite(Red, LOW);
    } else {
      Serial.println("Unknown Command!");
    }
  }
}
```

## 📱 How to Use
1. Upload the provided code to your **Arduino**.
2. Pair your **HC-05 module** with your Android phone.
3. Install a **Bluetooth Terminal App** (e.g., "Serial Bluetooth Terminal").
4. Connect to the HC-05 module.
5. Send commands like:
   - `green` → Turns on the Green LED
   - `green off` → Turns off the Green LED
   - `yellow` → Turns on the Yellow LED
   - `yellow off` → Turns off the Yellow LED
   - `red` → Turns on the Red LED
   - `red off` → Turns off the Red LED

## 🚀 Applications
- Home Automation
- Smart Lighting Systems
- IoT-Based Projects

## 📌 Author
**Anant Sharma**  
Check out my other projects on GitHub!

## 📜 License
This project is open-source and free to use.

