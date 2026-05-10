Heat Flux Soil Sensor (Modbus RS485)

<img width="5504" height="3072" alt="heatfluxsensor_slide_1" src="https://github.com/user-attachments/assets/1c5bd571-a0f2-4b81-8cb7-5e22e431c98a" />


เซ็นเซอร์มี 2 ด้าน ด้านสีเขียว กับด้านสีส้ม การติดตั้ง จะต้องวางด้านสีเขียวไว้ด้านบน ด้านสีส้มไว้ด้านล่าง เท่านั้น จึงจะได้ประสิทธิภาพการวัดที่แม่นยำและถูกต้อง

The sensor has two sides, a green side and an orange side. During installation, the green side must be placed upwards and the orange side downwards for accurate and precise measurements.

Here is specification part:
power supply
5-30V DC
Maximum energy consumption.
0.3W (24V DC power supply)
Operating temperature
-40 *C + 60 *C
Measurement range
-2000~2000 watts/sq.m
Accuracy
±5% (@±200 watts/sq.m.)
Protection level
IP68
Sealing materials
Black fire-resistant epoxy resin
Cable length
The default length is 2 meters; other lengths can be customized.
Output signal
RS485 (ModBus protocol)


<img width="622" height="319" alt="dg" src="https://github.com/user-attachments/assets/bcea88a0-92fb-4525-a787-20c683529e4e" />

<img width="750" height="750" alt="4 - 09-05-2026 13-31-47" src="https://github.com/user-attachments/assets/ade9b6ce-bc27-40fe-8ee9-9a6b270d5f82" />
<img width="750" height="734" alt="2" src="https://github.com/user-attachments/assets/77d8aa68-9f68-43ef-ac79-a3501704d197" />

<img width="750" height="922" alt="448" src="https://github.com/user-attachments/assets/09e7e245-f369-4aa9-be57-356a8851bd90" />

<img width="750" height="400" alt="8784" src="https://github.com/user-attachments/assets/8476cbf5-48b0-4777-bfd6-8178f833f8e2" />

From the connection diagram in the reference information, the wiring method between the ESP32 board, MAX485 module, and the soil heat flux sensor can be summarized as follows:

1. Connection between the ESP32 board and the MAX485 module
Power supply:
Connect the VIN pin of the ESP32 to the VCC pin of the MAX485 (red wire) to receive power.
Connect the GND pin of the ESP32 to the GND pin of the MAX485 (black wire).
Data signal wire: (Data/Control):
1. Connect pin D4 of the ESP32 to the DI (Data In) pin of the MAX485 (light blue wire).
2. Connect pin RX2 of the ESP32 to the DE (Data Enable) pin of the MAX485 (blue wire).
3. Connect pin TX2 of the ESP32 to the RE (Receive Enable) pin of the MAX485 (pink wire).
4. Connect pin D5 of the ESP32 to the RO (Receive Out) pin of the MAX485 (purple wire).
2. Connecting the MAX485 module to the sensor:
Connect signal A on the green terminal block of the MAX485 to signal A of the sensor (orange wire).
5. Connect signal B of the MAX485 to signal B of the sensor (green wire).
6. Powering the sensor:
The sensor requires an external 5-30V DC power supply.
Connect a separate power wire to the sensor. Connect the brown and black wires (in the image) to an external power supply with the specified voltage level.




