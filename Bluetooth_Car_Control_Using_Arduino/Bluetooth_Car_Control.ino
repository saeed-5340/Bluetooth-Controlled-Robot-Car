#include<AFMotor.h>
#include<SoftwareSerial.h>
SoftwareSerial pin(A0, A1);
char ch;
AF_DCMotor motor3(3), motor4(4);
void setup() {
  motor4.setSpeed(200);
  motor3.setSpeed(200);
  pin.begin(9600);
  Serial.begin(9600);
  Serial.println("MOTORRRRR car!!!!!!");

}

void loop() {

  if (pin.available())
  {
    ch = pin.read();
  }

  if (ch == 'F')forward();
  else if (ch == 'B') backward();
  else if (ch == 'L') left();
  else if (ch == 'R') right();
  else if (ch == 'I')
  {
    forwardright();
    motor4.setSpeed(150);
    motor3.setSpeed(200);
  }
  else if (ch == 'G' )
  {
    forwardleft();
    motor4.setSpeed(150);
    motor3.setSpeed(200);
  }
  else if (ch == 'H')
  {
    leftback();
    motor4.setSpeed(150);
    motor3.setSpeed(200);
  }
  else if (ch == 'J')
  {
    rightback();
    motor4.setSpeed(150);
    motor3.setSpeed(200);
  }

}
void forward()
{
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(20);
  // motor4.setSpeed(200);
  motor4.run(RELEASE);
  motor3.run(RELEASE);

}
void backward()
{
  motor4.run(BACKWARD);
  motor3.run(BACKWARD);
  delay(20);
  motor4.run(RELEASE);
  motor3.run(RELEASE);

}
void left()
{
  motor3.run(FORWARD);
  motor4.run(RELEASE);
  delay(20);
  motor3.run(RELEASE);

}
void right()
{
  motor3.run(RELEASE);
  motor4.run(FORWARD);
  delay(20);
  motor4.run(RELEASE);
}
void forwardright()
{
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor4.setSpeed(200);
  motor3.setSpeed(100);
  delay(20);
  motor4.run(RELEASE);
  motor3.run(RELEASE);
}
void forwardleft()
{
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor4.setSpeed(100);
  motor3.setSpeed(200);
  delay(20);
  motor4.run(RELEASE);
  motor3.run(RELEASE);
}
void leftback()
{
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor4.setSpeed(100);
  motor3.setSpeed(200);
  delay(20);
  motor4.run(RELEASE);
  motor3.run(RELEASE);
}
void rightback()
{
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor4.setSpeed(200);
  motor3.setSpeed(100);
  delay(20);
  motor4.run(RELEASE);
  motor3.run(RELEASE);
}
