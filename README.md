# Arduino-Uno-with-RFC522

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

The code is located in the rfid_reader.ino file, see RFID Reader Code

The function of the code is to read the UID when attaching an RFID card and send it as a message via the Serial interface (Serial) or over the network (when extended via a Wi-Fi module).

## 🧩 Hardware connection diagram
![image](https://github.com/user-attachments/assets/20491cf3-c25a-4a96-a0f4-c177b13775b9)

One reader works as an input, the other as an output. The Arduino Uno connects to a PC via USB via the USB-B connector, requires the installation of the CH340 driver.

## 🧪 Test results

The result of reading the UID is displayed in 16-bit format on the serial monitor (or on the web interface if connected via a web server). 
Example:

![image](https://github.com/user-attachments/assets/0756613a-2374-47b3-b2d8-9acc4565bad7)

## 💳 RFID cards used

The project uses Mifare Classic smart cards, which are affordable and widespread.:

✅ Advantages:
- The ability to record and modify data
- Durability
- Resistance to mechanical damage
- Availability and low price

⚠️ Flaws:
- Small range (up to 10 cm)
- Vulnerability to cloning

 ❗️ The security is compensated by the second phase, biometric authentication, which eliminates unauthorized access during card cloning.

## 🧷 Conclusion

The RC522 RFID module in conjunction with the Arduino Uno provides a reliable and inexpensive solution for implementing the identification phase in the ACS. Due to the availability of components and ease of programming, this solution can be easily adapted to various use cases, including educational, research and industrial projects.

# Authors
If you have any questions, you can ask them to us by writing to us at email:
- ivanovvvvvvvanton3829@gmail.com
