#define servo 10
#define sensor 9
#include <Servo.h>
int pos;
Servo myservo;  // create servo object to control a servo

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int flag = 0;
  pos = 180;
  myservo.write(pos);
  Serial.println(digitalRead(sensor));
  if (digitalRead(sensor) == 0) flag = 1; 
  if (flag == 1) 
  {
    delay(4000);
    for ( pos = 180; pos >= 90; pos -= 1)
    {
      myservo.write(pos);
      Serial.println(pos);
      delay(15);
    }
    delay(9000);
    for ( pos = 90; pos <= 180; pos += 1)
    {
      myservo.write(pos);
      Serial.println(pos);
      delay(15);
    }
  }
  
    
}
