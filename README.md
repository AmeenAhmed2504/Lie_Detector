Arduino Pins:

A0: Analog input for reading the analog sensor value (e.g., from a potentiometer)
2, 3, 4: Digital outputs for controlling LEDs (e.g., red, yellow, green)
MAX30105 Sensor:

SDA: Connect to the Arduino's SDA pin (usually pin 4)
SCL: Connect to the Arduino's SCL pin (usually pin 5)
VCC: Connect to the Arduino's 5V pin
GND: Connect to the Arduino's GND pin
Additional Components (optional):

LEDs: Connect red, yellow, and green LEDs to pins 2, 3, and 4, respectively, with appropriate resistors to limit current.
Potentiometer: Connect a potentiometer to pin A0 to adjust the analog input value.
Note: The code assumes that you are using a standard Arduino Uno board with the I2C pins configured as SDA on pin 4 and SCL on pin 5. If you are using a different board or have different pin assignments, adjust the connections accordingly.
