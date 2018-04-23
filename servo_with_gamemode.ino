#include <Servo.h>

// call the all of LDR
int ldr0 = 0;
int ldr1 = 1;
int ldr2 = 2;
int ldr3 = 3;

// call all of servo
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

// call all of button
const int  button_start_game = 5;
const int  button_stop_all = 7;

//state of button
int start_game = 0;

void setup()
{
  // call port servo
  servo0.attach(8);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  
  // set Default servo
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  
  // set button as input
  pinMode(button_start_game, INPUT);
  pinMode(button_stop_all, INPUT);
}
/*============================================================================*/
void loop()
{
  // when you press button [set the button]
  if (digitalRead(button_start_game) == HIGH){
    if (start_game == 0){
      start_game = 1;
    }
  }

  //this button can stop all mode
  if (digitalRead(button_stop_all) == HIGH){
    if (start_game == 1){
      start_game = 0;
    }
  }
  
  //mode game
  if (start_game == 1){
    game_mode();
  }
  else if (wait_mode == 1){
    start_game = 0;
    wait_mode();
  }
}
/*===========================================================================*/

// Game Mode
void game_mode()
{
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  if (analogRead(ldr0) > 500){
    servo0.write(78);
    delay(150);
    servo0.write(65);
    delay(150);
    /*if (analogRead(ldr0) <= 400){
      servo0.write(110);
      delay(200);
    }*/
  }
  
  else if  (analogRead(ldr1) > 500){
    servo1.write(57);
    delay(150);
    servo1.write(68);
    delay(150);
    /*if (analogRead(ldr1) <= 400){
      servo1.write(68);
      delay(200);
    }*/
  }
  
  else if (analogRead(ldr2) > 500){
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

