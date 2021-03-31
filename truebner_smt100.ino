#include <Arduino.h>
#include <SensorModbusMaster.h>

#define RS485_1_DE_RE 10
#define RS485_1_Serial Serial1
#define RS485_1_BAUDRATE 9600

#define SMT100_NODEID 0x00

modbusMaster modbus;

void setup() {
  Serial.begin(115200);
  Serial.println("STARTUP");

  pinMode(RS485_1_DE_RE, OUTPUT);
  digitalWrite(RS485_1_DE_RE, 0);
  RS485_1_Serial.begin(RS485_1_BAUDRATE, SERIAL_8E1); // RS485 - setup for modbus

  modbus.begin(SMT100_NODEID, &RS485_1_Serial, RS485_1_DE_RE);

  // modbus.setDebugStream(&Serial);

}

void loop() {
  float temp = (float(modbus.int16FromRegister(0x03, 0x0000, bigEndian)) / 100.0) - 100;
  float moisture = float(modbus.int16FromRegister(0x03, 0x0001, bigEndian)) / 100.0;
  float permittivity = float(modbus.int16FromRegister(0x03, 0x0002, bigEndian)) / 100.0;

  Serial.print("Temperature: "); Serial.println(temp);
  Serial.print("Moisture: "); Serial.println(moisture);
  Serial.print("Permittivity: "); Serial.println(permittivity);
  delay(2000);


  /* This example reads all three registers in a single command:


    bool success = modbus.getRegisters(0x04, 0x00, 3);
    if (success)
    {
      temp = (float(modbus.uint16FromFrame(bigEndian, 3)) / 100.0) - 100;
      // ^ The first data value is at position 3 in the modbus response frame
      // 0 = modbus address, 1 = modbus method, 2 = # registers returned, 3 = 1st value returned
      moisture = float(modbus.int16FromFrame(bigEndian, 5)) / 100.0;
      // ^ The next data value is at position 5 since each register occupies 2 places
      permittivity = float(modbus.uint16FromFrame(bigEndian, 7)) / 100.0;
    }

    Serial.print("Temperature: "); Serial.println(temp);
    Serial.print("Moisture: "); Serial.println(moisture);
    Serial.print("Permittivity: "); Serial.println(permittivity);

  */

}
