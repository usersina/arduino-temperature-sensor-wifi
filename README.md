# ESP8266 Temperature Sensor Firebase

This projects demonstrates reading data from a temperature sensor and sending in to Firebase for real-time monitoring.

## Getting Started

This project uses the open source [PlatformIO IDE](https://platformio.org/) built on top of [Microsoft's Visual Studio Code.](https://code.visualstudio.com/)

### Prerequisites

- [NodeMCU ESP8266](https://components101.com/development-boards/nodemcu-esp8266-pinout-features-and-datasheet)
- [DS18B20 Temperature sensor](https://components101.com/sensors/ds18b20-temperature-sensor)
- Breadboard and jumper wires
- A computer with [PlatformIO IDE](https://platformio.org/platformio-ide) installed

In addition to the hardware requirements, you also need to setup a [Firebase Realtime Database](https://firebase.google.com/docs/database), with [Anonymous User Authentication](https://firebase.google.com/docs/auth) enabled.

### Installation

1. Clone this repository to your local machine.
2. Open the project in PlatformIO IDE.
3. Install the necessary libraries mentioned in the `platformio.ini` file.
4. Copy the `./src/secrets.h.example` to a `./src/secrets.h` file and update it.

### Running the Project

1. Connect the temperature sensor to the board as per the circuit diagram provided.
2. Connect the board to your computer.
3. Upload the code to the board using the PlatformIO IDE.
4. Open the serial monitor to view the temperature data as it's being sent.

### Circuit Diagram

todo

## Resources

- [Arduino core for ESP8266 WiFi chip](https://github.com/esp8266/Arduino)
- [99-platformio-udev.rules](https://docs.platformio.org/en/latest/core/installation/udev-rules.html)
- [Restarting udev on Arch Linux](https://bbs.archlinux.org/viewtopic.php?id=146369)
- [ESP01 code upload works with Arduino IDE but not with PIO](https://community.platformio.org/t/esp01-code-upload-works-with-arduino-ide-but-not-with-pio/25893)
- [NodeMCU ESP8266](https://components101.com/development-boards/nodemcu-esp8266-pinout-features-and-datasheet)
- [Timeout error when connecting ESP8266 to Arduino](https://arduino.stackexchange.com/questions/67664/timeout-error-when-connecting-esp8266-to-arduino-uno)
- [Esp8266 gibberish serial monitor output](https://community.platformio.org/t/esp8266-gibberish-serial-monitor-output/30027)
- [How To Program An ESP8266 With the Arduino IDE (video)](https://youtu.be/AFUAMVFzpWw)
- [How to Setup and Program NodeMCU ESP8266–Complete Guide (video)](https://youtu.be/YN522_npNqs?list=PL4pptAPY2kIckUNYqpLpKE5qQISi1KvfS)
- [How To Setup And Connect The NodeMCU ESP8266 12-E Development Board To Your Computer and Wifi (video)](https://www.youtube.com/watch?v=la-yGpXZ6sU)
- [Introduction to NodeMCU ESP8266 WiFi Development board with HTTP Client example- Robojax (video)](https://www.youtube.com/watch?v=pLvqh57T3s4)
- [05 Firebase Realtime Database + ESP32 | How to save sensor data & read data to control devices?](https://youtu.be/aO92B-K4TnQ)
