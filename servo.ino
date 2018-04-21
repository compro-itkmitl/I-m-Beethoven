#include <Servo.h>
int ldr0 = 0;             /* set 4 LDR sensor */
int ldr1 = 1;
int ldr2 = 2;
int ldr3 = 3;
 
Servo servo0;             /* set 4 motor */
Servo servo1;
Servo servo2;
Servo servo3;
 
void setup()
{
  servo0.attach(8);       /* set motor to input 8-11 */
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(9600);
  /*servo0.write(80);
  servo1.write(90);
  servo2.write(80);
  servo3.write(90);*/
}
 
void loop()
{
  
  /*servo0.write(110);
  delay(300);
  servo0.write(133);
  delay(300);
  servo0.write(110);
  servo1.write(68);
  delay(300);
  servo1.write(57);
  delay(300);
  servo1.write(68);
  servo2.write(100);
  delay(300);
  servo2.write(117);
  delay(300);
  servo2.write(100);
  servo3.write(90);
  delay(300);
  servo3.write(72);
  delay(300);
  servo3.write(90);*/
  servo0.write(65);                    /* original degree when ready state */
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  if (analogRead(ldr0) > 400){         /* ldr check light intensity */
    servo0.write(78);                  /* motor push stick down to press phone screen */
    delay(150);
    servo0.write(65);                  /* then return to the ready state */
    delay(150);
    /*if (analogRead(ldr0) <= 400){
      servo0.write(110);
      delay(200);
    }*/
  }
  
  else if  (analogRead(ldr1) > 400){
    servo1.write(57);
    delay(150);
    servo1.write(68);
    delay(150);
    /*if (analogRead(ldr1) <= 400){
      servo1.write(68);
      delay(200);
    }*/
  }
  
  else if (analogRead(ldr2) > 440){
    servo2.write(117);
    delay(150);
    servo2.write(100);
    delay(150);
    /*if (analogRead(ldr2) <= 440){
      servo2.write(100);
      delay(200);
    }*/
  }
  else if (analogRead(ldr3) > 500){
    servo3.write(72);
    delay(150);
    servo3.write(90);
    delay(150);
    /*if (analogRead(ldr3) <= 500){
      servo3.write(90);
      delay(200);
    }*/
  }
}
