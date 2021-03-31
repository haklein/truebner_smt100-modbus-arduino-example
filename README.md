# truebner_smt100-modbus-arduino-example
Small arduino sketch to read out the Truebner SMT100 soil mositure sensor via modbus RTU. This has been tested on a MEGA2560 with a dedicated HardwareSerial. The RS485 tranceiver being used is a MAX485 on a "rs485 ttl module" (can be found pretty much everywhere). Wiring:

TX1 - DI
RX1 - RO
GPIO10 - DE & RE

