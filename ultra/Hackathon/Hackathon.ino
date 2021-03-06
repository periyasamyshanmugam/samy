#include<Servo.h>
#define WATERPIN 2
#define READSOILPIN A0
#define MAXDRYNESS 900
#define LEDS 3
#define ANS 4
Servo myservo;
const int trigPin = 10;
const int echoPin = 9;
int buz=8;
int ledPin=13;
int state=0;
int flag=0;
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(7);
  pinMode(READSOILPIN, INPUT);
  pinMode(WATERPIN, OUTPUT);
  pinMode(LEDS, OUTPUT);
pinMode(ANS, OUTPUT);
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  long duration, inches, cm;
  int SensorValue = analogRead(READSOILPIN);
  if (Serial.available()>0)
{
  state=Serial.read();
  flag=0;
  
}
if(state=='0'){
  digitalWrite(ledPin,LOW);
if(flag==0)
{
  Serial.println("LED:OFF");
  flag=1;
  
}
}
else if(state=='1')
{
  digitalWrite(ledPin,HIGH);
  if(flag==0)
  {
    Serial.println("LED :ON");
    flag=1;
  }
  }
  for(pos = 40; pos < 140; pos += 1) // goes from 0 degrees to 180 degrees 
  { // in steps of 1 degree 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(150); // waits 15ms for the servo to reach the position 
  } 
  for(pos = 140; pos>=40; pos-=1) // goes from 180 degrees to 0 degrees 
  { 
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(150); // waits 15ms for the servo to reach the position 
  } 
 pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(50);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  pinMode(buz, OUTPUT);
  if(inches>0&&inches<8)
  {
    digitalWrite(buz, HIGH);
  }
  else
  {
    digitalWrite(buz, LOW);
  }
  
  if(SensorValue >= MAXDRYNESS)
  {
  Serial.println("soil dry start watering...");
  digitalWrite(LEDS,HIGH);
  digitalWrite(ANS,HIGH);
  }
   else 
   {
      Serial.println("Moisture level is good. you can stop watering...");
      digitalWrite(LEDS,LOW);
      digitalWrite(ANS,HIGH);
   }
   
  
}
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

