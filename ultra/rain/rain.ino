#include<Servo.h>
Servo myservo;
int pos;
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
  myservo.attach(7);
}
void loop() {
  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Heavy Rain");
     for(pos = 40; pos < 140; pos += 1) // goes from 0 degrees to 180 degrees 
  { // in steps of 1 degree 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(50); // waits 15ms for the servo to reach the position 
  } 
    break;
 case 1:    // Sensor getting wet
    //Serial.println("Rain Warning");
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    for(pos = 140; pos>=40; pos-=1) // goes from 180 degrees to 0 degrees 
  { 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(50); // waits 15ms for the servo to reach the position 
  } 
    break;
  }
  delay(10000);  // delay between reads
}

