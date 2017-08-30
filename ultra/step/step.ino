#include<Servo.h>
Servo myservo;
int pos; // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(7); // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  for(pos = 40; pos < 140; pos += 1) // goes from 0 degrees to 180 degrees 
  { // in steps of 1 degree 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(50); // waits 15ms for the servo to reach the position 
  } 
  for(pos = 140; pos>=40; pos-=1) // goes from 180 degrees to 0 degrees 
  { 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(50); // waits 15ms for the servo to reach the position 
  } 
}
