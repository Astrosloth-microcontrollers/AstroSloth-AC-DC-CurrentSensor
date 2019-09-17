/*******************************************************************************
  Title: Astrosloth AC/DC Hall Effect Current Sensor
  Version: 1.00
  Date: 08-19-2019
  Author: Astrosloth

  Brief
  =====
  Measuring Current Using Broadcom ACHS-7122 (20A module).
  Wire to module 5V, Ground and Analog out

*******************************************************************************/
const int analogIn = A0;
int mVperAmp = 100; // sensitivity in mV/A use 185 for 10A Module, 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; // VCC/2 as the wave centers around this point
double Voltage = 0;
double Amps = 0;

void setup(){ 
 Serial.begin(9600);
}

void loop(){
 
 RawValue = analogRead(analogIn);
 Voltage = (RawValue / 1024.0) * 5000; // Gets you the value in mV
 Amps = ((Voltage - ACSoffset) / mVperAmp); //subtract from the offset then divide by sensitivity
 
 
 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage); // display voltage
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(Amps); // display amps
 delay(2000); 
 
}
