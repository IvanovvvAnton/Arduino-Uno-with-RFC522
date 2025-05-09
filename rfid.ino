#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Пин сброса
#define SS_PIN          10         // Пин выбора устройства SPI

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Создание экземпляра MFRC522

void setup() {
    Serial.begin(9600);        // Инициализация последовательной связи
    while (!Serial);           // Ожидание открытия последовательного порта (для ATMEGA32U4)
    SPI.begin();               // Инициализация SPI
    mfrc522.PCD_Init();        // Инициализация MFRC522
    delay(4);                  // Небольшая задержка для стабильности
}

void loop() {
    // Проверяем, есть ли новая карта в зоне действия
    if (mfrc522.PICC_IsNewCardPresent()) {

        // Читаем UID карты
        if (mfrc522.PICC_ReadCardSerial()) {

            // Вывод UID в 16-ричном формате без пробелов
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                if (mfrc522.uid.uidByte[i] < 0x10) Serial.print("0"); // Добавляем ведущий ноль, если необходимо
                Serial.print(mfrc522.uid.uidByte[i], HEX);
            }
            Serial.println();
        }

        mfrc522.PICC_HaltA(); // Останавливаем работу с картой
    }
    // Нет необходимости в задержке или дополнительной логике
}
