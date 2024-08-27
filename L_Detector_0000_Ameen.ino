#include <Wire.h>
#include <MAX30105.h>

MAX30105 particleSensor;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  //digitalWrite(2, HIGH);
  delay(500);
  //digitalWrite(3, HIGH);
  delay(500);
  //digitalWrite(4, HIGH);
  delay(500);

  // Initialize the MAX30102 sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) // Use default I2C port, 400kHz speed
  {
    Serial.println("Could not find a valid MAX30102 sensor, check wiring!");
    while (1);
  }

  particleSensor.setup(); // Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); // Adjust the LED brightness
  particleSensor.setPulseAmplitudeGreen(0);   // Turn off Green LED
}

void loop()
{
  // Read heart rate and SpO2 values
 
    int hr = particleSensor.getIR()/1000;
    int spo2 = (particleSensor.getRed()/1000)*3.4;

    // Your existing code for LED control based on analogRead(A0)
    if (analogRead(A0) > 60) //red
    {
      digitalWrite(4, HIGH);
    }
    else
    {
      digitalWrite(4, LOW);
    }

    if (analogRead(A0) > 45)//yellow
    {
      digitalWrite(3, HIGH);
    }
    else
    {
      digitalWrite(3, LOW);
    }
    if (analogRead(A0) > 20)//green
    {
      digitalWrite(2, HIGH);
    }
    else
    {
      digitalWrite(2, LOW);
    }
    
    //

    if (hr > 85)  // hr red
    {
      digitalWrite(4, HIGH); 
    }
    else
    {
      digitalWrite(4, LOW);
    }
    
    if (hr > 80 && hr <84) //hr yellow
    {
      digitalWrite(3, HIGH);
    }
    else
    {
      digitalWrite(3, LOW);
    }
    // Print values to Serial Monitor
    Serial.print("Heart rate: ");
    Serial.print(hr);
    Serial.print(" bpm\t");

    Serial.print("SpO2: ");
    Serial.print(spo2);
    Serial.println(" %");

    // Add code here to plot the values on a graph (using a plotting library or tool)
  

  // Your existing code for printing analogRead(A0)
  Serial.println(analogRead(A0));
  delay(20);
}
