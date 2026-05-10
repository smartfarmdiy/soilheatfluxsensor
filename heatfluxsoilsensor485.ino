#include <ModbusMaster.h>

#define RXD2 16
#define TXD2 17
#define MAX485_DE_RE 4

ModbusMaster node;

void preTransmission() {
  digitalWrite(MAX485_DE_RE, HIGH);   // ส่งข้อมูล
}

void postTransmission() {
  digitalWrite(MAX485_DE_RE, LOW);    // รับข้อมูล
}

void setup() {
  Serial.begin(115200);

  pinMode(MAX485_DE_RE, OUTPUT);
  digitalWrite(MAX485_DE_RE, LOW);

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  node.begin(1, Serial2); // Slave ID = 1
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  Serial.println("Start Modbus RS485 Soil Heat Flux Sensor");
}

void loop() {
  uint8_t result;

  // ตัวอย่างอ่าน Holding Register address 0x0000 จำนวน 2 register
  // ต้องแก้ register ตามคู่มือ sensor
  result = node.readHoldingRegisters(0x0000, 2);

  if (result == node.ku8MBSuccess) {
    uint16_t raw1 = node.getResponseBuffer(0);
    uint16_t raw2 = node.getResponseBuffer(1);

    Serial.print("Register 0: ");
    Serial.println(raw1);

    Serial.print("Register 1: ");
    Serial.println(raw2);

    // ตัวอย่างแปลงค่า ถ้า sensor ใช้ scale 0.1
    float heatFlux = raw1 / 10.0;

    Serial.print("Heat Flux: ");
    Serial.print(heatFlux);
    Serial.println(" W/m2");
  } else {
    Serial.print("Modbus Error: ");
    Serial.println(result);
  }

  delay(2000);
}