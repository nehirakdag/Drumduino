/* Knock Sensor

   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "knock" to the serial port, and toggles the LED on pin 13.

   The circuit:
    * + connection of the piezo attached to analog in 0
    * - connection of the piezo attached to ground
    * 1-megohm resistor attached from analog in 0 to ground

   http://www.arduino.cc/en/Tutorial/Knock

   created 25 Mar 2007
   by David Cuartielles <http://www.0j0.org>
   modified 30 Aug 2011
   by Tom Igoe

   This example code is in the public domain.

 */


// these constants won't change:
const int ledPin = 13;      // led connected to digital pin 13
const int sensor0 = A0; // the piezo is connected to analog pin 0
const int sensor1 = A1; // the piezo is connected to analog pin 0
const int sensor2 = A2; // the piezo is connected to analog pin 0
const int sensor3 = A3; // the piezo is connected to analog pin 0
const int sensor4 = A4; // the piezo is connected to analog pin 0
const int sensor5 = A5; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int read0 = 0;      // variable to store the value read from the sensor pin
int read1 = 0;
int read2 = 0;
int read3 = 0;
int read4 = 0;
int read5 = 0;
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  read0 = analogRead(sensor0);
  read1 = analogRead(sensor1);
  read2 = analogRead(sensor2);
  read3 = analogRead(sensor3);
  read4 = analogRead(sensor4);
  read5 = analogRead(sensor5);
  
  Serial.print("Sensors:\t");
  Serial.print(read0);
  
  Serial.print("\t");
  Serial.print(read1);
  
  Serial.print("\t");
  Serial.print(read2);
  
  Serial.print("\t");
  Serial.print(read3);
  
  Serial.print("\t");
  Serial.print(read4);
  
  Serial.print("\t");
  Serial.println(read5);
  
  delay(100);  // delay to avoid overloading the serial port buffer
}
