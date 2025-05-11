# Arduino-Uno-with-RFC522

## 📋 Table of Contents
1. [Appointment](#-appointment)
2. [Equipment](#%EF%B8%8F-equipment)
3. [Software part](#%EF%B8%8F-the-software-part)
   - [Firmware logic](#-firmware-logic)
4. [UID reading code](#-uid-reading-code)
5. [Hardware connection diagram](#-hardware-connection-diagram)
   - [Connecting RC522](#connecting-rc522-pins-to-arduino-uno)
   - [Features of the scheme](#-features-of-the-scheme)
6. [Test results](#-test-results)
   - [Testing methodology](#-testing-methodology)
   - [Results obtained](#-the-results-obtained)
   - [Example](#-example)
   - [Reliability and stability](#-reliability-and-stability)
7. [MIFARE Classic Cards](#-rfid-cards-used)
   - [General information](#-general-information-about-mifare-classic-cards)
   - [Functional features](#%EF%B8%8Ffunctional-features)
   - [Disadvantages and protective measures](%EF%B8%8F-disadvantages-and-protective-measures)
8. [Conclusion](#-conclusion-1)
9. [Authors](#authors)

The combination of the Arduino Uno and the RC522 RFID reader is widely used to implement user identification functions in access control and management systems (ACS). This solution allows you to organize a reliable and inexpensive way to read RFID cards used when entering and exiting secure premises.

## 📌 Appointment
The RFID reader in the ACS system performs a key function - user identification at the stage of access to the object. When a contactless RFID card is held up to the reader, a unique identifier (UID) is read, which is then used to determine whether the user is registered in the system and whether he has the right to enter or exit.

The system implements two reader operation modes:

1 Entrance control is used to record the moment the user enters the room.

2 Exit control — determines the moment of exit from the room.

Each RFID RC522 device is connected to its own Arduino Uno board, which provides independent signal processing at the input and output. After reading the UID, the data is sent to the microcontroller, where it is analyzed for presence in the database. If the user is successfully recognized, his unique ID is determined, and the direction of passage (entrance/exit) is recorded, which is marked with a special status parameter (1 — entrance, 0 — exit).

It is important to note that RFID identification is not the only access factor in this ACS. The system uses two-factor authentication, in which the RFID card is the first factor, and biometric identity verification (for example, face recognition) is the second. This significantly improves security and eliminates the possibility of unauthorized access to a lost or copied card.

The RFID reader can also be supplemented with user feedback — through an audible signal or information display on the display. This simplifies interaction and informs the user about the status of his access attempt (success/failure).

## ⚙️ Equipment

As part of the implementation of the prototype access control system, a bundle of Arduino Uno and an RFID reader RC522 based on the MFRC522 chip was selected. This choice is due to several factors at once:

✅ Accessibility and low cost

Both components are inexpensive and easily available both in local electronics stores and on international online platforms. This makes them ideal for projects with a limited budget, educational or research purposes.

✅ Support for common standards

The RC522 RFID module operates at a frequency of 13.56 MHz and supports the MIFARE standard, which is one of the most common in the field of contactless cards. This ensures compatibility with most existing RFID cards used, for example, in public transport, banking systems, employee passes, etc.

✅ Compact and easy integration

The RC522 is a compact module that can be easily integrated into end—device enclosures. Its size and shape are ideal for installation in access control terminal enclosures, wall panels or turnstiles.

✅ Easy to connect

The RC522 module uses the SPI (Serial Peripheral Interface) interface, which is supported by all popular Arduino boards, including the Arduino Uno. The connection is carried out using 7 wires (VCC, GND, RST, IRQ, MISO, MOSI, SCK, SDA), which allows you to quickly assemble a working circuit without using additional components.

✅ A well - developed community and ready - made libraries

To work with the RC522 module, there is a widely used MFRC522 library that allows you to read UID cards, perform basic operations, and easily integrate the reader into any Arduino project. This saves time on development and debugging, as well as reduces the requirements for the developer's level of training.

✅ Arduino IDE support

The Arduino Uno is programmed through the official Arduino IDE, which is intuitive and supports many ready-made examples and libraries. This allows you to quickly start developing, adapting, and testing, and also makes the project accessible to the community and novice developers.

## 🖥️ The software part

The Arduino IDE, the official development environment for Arduino, is used to write and download the firmware. The project uses the MFRC522 library, which provides access to all the functions of reading the UID and controlling the RFID module.

Libraries used:
```
#include <SPI.h>
#include <MFRC522.h>
```
The project uses the MFRC522 library, which provides a user-friendly interface for working with the RC522 RFID reader. It allows you to:

1 Initialize the module;

2 Read the card's UID;

3 Handle repeated attempts;

4 Perform basic authentication with the card (if necessary).

Additionally, the SPI.h library can be used, which is included in the standard delivery of the Arduino IDE and is necessary for operation via the SPI interface.

### 🧠 Firmware logic

The program loaded into the Arduino Uno implements the following functionality:

1 Initialization of the RC522 module.

2 Waiting for the RFID card to be attached.

3 When reading a card, it receives its UID (unique identifier).

4 Converting a UID to a readable format (for example, hexadecimal).

5 UID output via Serial port (Serial) — for subsequent processing on the server/PC side.

Optional: sending the UID via UART, HTTP request, or MQTT (in the extended version).



## 💻 UID reading code:

[The code is located in the rfid_reader.ino file, see RFID Reader Code](rfid.ino)

The function of the code is to read the UID when attaching an RFID card and send it as a message via the Serial interface (Serial) or over the network (when extended via a Wi-Fi module).

## 🧩 Hardware connection diagram

To connect the RC522 RFID reader to the Arduino Uno board, the SPI (Serial Peripheral Interface) interface is used. This is one of the fastest and most widely used methods of data exchange between the microcontroller and peripheral devices. It is ideal for tasks where high speed and stability of data transmission are required, which is critical for access control systems.

### 🔌Connecting RC522 pins to Arduino Uno

| RC522 Pin | Destination | Arduino Uno Pin |
|-------------|-------------------------------|------------------|
| VCC | Power Supply (3.3V) | 3.3V |
| GND | Earth | GND |
| RST | Reset | D9 |
| SDA (SS) | Device Selection (Slave)      | D10              |
| MOSI | Data transfer to RC522 | D11 |
| MISO | Receiving data from RC522 | D12 |
| SCK | Clocking | D13 |

📍 Important: The RC522 module is powered strictly from 3.3 V, connecting to 5 V may disable it.

### 🔧 Features of the scheme

- Two RFID readers: The system uses two RC522S — one is installed at the input, the other at the output. This allows you to accurately track the user's direction of movement (entry/exit).

- PC connection: The Arduino Uno is connected to the computer via a USB cable (USB-B connector). This is necessary both for the firmware of the microcontroller and for transmitting the read data to the ACS system in real time via the serial port (COM).
    
![image](https://github.com/user-attachments/assets/20491cf3-c25a-4a96-a0f4-c177b13775b9)

💡 It is recommended to use breadboard and jumper wires to simplify assembly and debugging.

## 🧪 Test results

The RC522 RFID reader connected to the Arduino Uno was tested to verify the stability of reading UID RFID cards, the response rate, the correctness of data transmission, and the overall operability of the module as part of the access control and management system (ACS).

### 📋 Testing methodology

1 Connect the RC522 to the Arduino Uno via the SPI interface according to the connection diagram.

2 Downloading the firmware to the Arduino Uno via the Arduino IDE.

3 Opening the port monitor in the Arduino IDE to monitor the reading results.

4 Sequential application of various RFID cards of the Mifare Classic standard.

5 Fixing the time between the application and the appearance of data in the Serial Monitor.

6 Checking the correctness of the UID format and resistance to repeated reading.

7 Error simulation: incomplete application, quick card change, card deletion before the reading is completed.

### 📈 The results obtained

1 Success of reading the UID: All tested RFID cards were successfully read. The UID was displayed in a 4-byte 16-bit format.

2 Average response time: The delay between applying the card and the data appearing in the Serial Monitor was ~200-300 ms.

3 Repeat reading speed: Repeated reading of the same card is possible with an interval of 1-1.5 seconds, due to the need to physically remove the card from the reader.

4 Error handling: If the card was not fully attached, the reader returned an empty response or an incorrect GUID, but a second attempt resulted in a correct reading. This behavior is acceptable and is taken into account in the logic of the ACS.

5 Operation of two readers: Testing of two Arduino Uno with RC522 showed that the system correctly distinguishes between input and output by port assignment and device status. The data from both readers is processed independently.

The result of reading the UID is displayed in 16-bit format on the serial monitor (or on the web interface if connected via a web server). 

### 📷 Example:

![image](https://github.com/user-attachments/assets/0756613a-2374-47b3-b2d8-9acc4565bad7)

### 🛠 Reliability and stability
- The RC522 module has demonstrated stable performance during long-term tests (more than 200 readings in a row).

- There were no errors in data exchange with the Arduino Uno.

- The range of the reader is up to 5 cm, which corresponds to the technical specifications.
    
## 💳 RFID cards used

The developed access control and management system (ACS) uses RFID cards of the MIFARE Classic 1K standard. This is one of the most common types of contactless smart cards operating at a frequency of 13.56 MHz, which fully complies with the RC522 reader standard.

### 📋 General Information about MIFARE Classic Cards

| **Parameter**              | **Value**                              |
|---------------------------|----------------------------------------|
| Card Type                 | MIFARE Classic 1K                      |
| Operating Frequency       | 13.56 MHz                              |
| Memory Size               | 1024 bytes (1 KB)                      |
| Number of Sectors         | 16 (4 blocks each)                     |
| UID Size                  | 4 bytes                                |
| Read Range                | Up to 10 cm (RC522 – up to 5 cm)       |
| Response Time             | Less than 0.1 seconds                  |
| Power Supply              | Passive (powered by the reader field) |

### ⚙️Functional features:

- The ability to record and modify data. (The cards allow you to store identification information, access parameters, number of passes, etc., which makes them universal for ACS, transport, accounting and payment).

- Low cost. (MIFARE Classic is an affordable and mass—produced solution that reduces system implementation costs).

- Reliability and durability. (The cards are resistant to external influences and are designed for tens of thousands of read operations).

### ⚠️ Disadvantages and protective measures:

- Limited range (up to 10 cm). (This is rather an advantage for ACS, as it reduces the risk of being read by unauthorized devices. The RC522 used has a radius of up to 5 cm, which makes the system even more secure).

- Vulnerability to cloning. (MIFARE Classic cards are subject to a number of vulnerabilities, including the ability to clone UIDS. In our system, this risk is offset by the use of the second authentication factor, biometric recognition, which makes card forgery useless).

#### 📦 Form factors of the cards used:

Classic plastic cards (ID-1, bank card size), if necessary, it can be replaced with key rings or bracelets with a MIFARE chip.

#### ✅ Advantages:
- The ability to record and modify data
- Durability
- Resistance to mechanical damage
- Availability and low price

#### ⚠️ Flaws:
- Small range (up to 10 cm)
- Vulnerability to cloning

 ❗️ The security is compensated by the second phase, biometric authentication, which eliminates unauthorized access during card cloning.

## 🧷 Conclusion

The use of the RC522 RFID reader based on the Arduino Uno microcontroller in the access control and management system (ACS) is a successful combination of affordable equipment, extensive capabilities and ease of integration. Thanks to its operation at 13.56 MHz and support for the MIFARE Classic standard, the RC522 easily interacts with the most common types of RFID cards, providing reliable and stable reading of the unique identifier (UID).

The use of two readers in the system — for the input and output groups — allows not only to record the fact of access itself, but also to track the direction of the user's movement, which increases the transparency and security of the entire ACS.

The tests performed confirmed the stable operation of the equipment, the short response time and the resistance to errors during reading. The MIFARE Classic RFID cards used, despite known vulnerabilities (for example, the possibility of cloning), provide an acceptable level of security provided that two-factor authentication is implemented in this system using biometric identity verification.

Another important aspect is the choice of software — the Arduino IDE, due to its simplicity, a variety of supported libraries and an active community of developers, provides all the necessary tools for configuring and debugging the interaction of Arduino with the RFID module.

Thus, the implemented solution demonstrates that a fully functional and flexibly scalable access control system that meets modern security requirements can be built on the basis of inexpensive and widely available components. This makes this architecture promising for implementation both in educational institutions and office premises, as well as in small businesses and local corporate networks.

# Authors
If you have any questions, you can ask them to us by writing to us at email:
- ivanovvvvvvvanton3829@gmail.com
