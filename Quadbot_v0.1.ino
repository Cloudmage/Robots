/////////////////////////////////////////////////////////////////////////
///                                                                   ///
/// This code has been  derived the code from lumi's "chopstick jr"   ///
/// on letmakerobots.com http://letsmakerobots.com/node/29708         ///
///                                                                   ///
/// by Max Hemingway, April 2017                                      ///
/// https://maxhemingway.com/                                         ///
///                                                                   ///
/// This code is in the public domain                                 ///
///                                                                   ///
/////////////////////////////////////////////////////////////////////////

#include <Servo.h>
// Names for the Servos
/*
 * hip1 = front right hip
 * knee1 = front right knee
 * hip2 = front left hip
 * knee2 = front left knee
 * hip3 = rear left hip
 * knee3 = rear left knee
 * hip4 = rear right hip
 * knee4 = rear right knee
 */
Servo hip1;
Servo knee1;
Servo hip2;
Servo knee2;
Servo hip3;
Servo knee3;
Servo hip4;
Servo knee4;
// Define the SR04 Sensor pins
#define trigPin 11
#define echoPin 10
/// set variables needed for some tasks
int b;
int x;
int w;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;
int back;
int pos;
int sensor = A0;
int distance;
///end of variables
void setup() {
  pinMode(13, OUTPUT);  // LED pin
 /// assign servos to pins and center servos
  hip1.attach(2);
  hip1.write(90);
  knee1.attach(3);
  knee1.write(90);
  hip2.attach(4);
  hip2.write(90);
  knee2.attach(5);
  knee2.write(90);
  hip3.attach(6);
  hip3.write(90);
  knee3.attach(7);
  knee3.write(90);
  hip4.attach(8);
  hip4.write(90);
  knee4.attach(9);
  knee4.write(90);
  //
  //digitalRead(sensor);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
//////////////////////////////////////
void idle() // this is the delay between the steps -> walking speed
 {
  delay(200);  // if set to a bigger number (more delay between the steps -> slower walking) you will see the walking pattern more clearly
 }
////////////////////////////////////// 
void test() /* just for debugging -> if need a delay between the subroutines 
               you can let the LED blink as an indicator that something is still running  */
{
    for(b = 0; b < 3; b++) // this let the LED blink 5 times 
    {
      digitalWrite(13, HIGH);   // turn the LED on
      delay(300);               // wait for .5 second
      digitalWrite(13, LOW);    // turn the LED off
      delay(300);
    }  
}
//////////////////////////////////////
void standup()
{
  up2 = 90;
  up3 = 90;
  hip1.write(70);
  hip2.write(80);
  hip3.write(80);
  hip4.write(70);
  for(up = 90; up < 170; up++)
  {
    knee1.write(up);
    up2 = up2 - 1;
    knee2.write(up2);
    delay(20);
  }
  
  for(up = 90; up < 0; up++)
  {
    knee3.write(up);
    up3 = up3 + 40;
    knee4.write(up3);
    delay(15);
  }
}
//////////////////////////////////////
void sleep()
{
  // hips
  hip1.write(70);
  hip2.write(90);
  hip3.write(70);
  hip4.write(90);
  // knees
  knee1.write(0);
  knee2.write(180);
  knee3.write(0);
  knee4.write(180);
}
//////////////////////////////////////
void stand()
{
  hip1.write(70);
  knee1.write(170);
    delay(20);
  hip2.write(80);
  knee2.write(20);
    delay(20);
  hip3.write(80);
  knee3.write(170);
    delay(20);
  hip4.write(70);
  knee4.write(20); 
    delay(20);
}
//////////////////////////////////////
void forward()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee3.write(140);  // lower the diagonal opposite leg a bit to keep the balance
  knee1.write(140);
  idle();
  hip1.write(45);
  hip4.write(90);
  idle();
  knee1.write(170);
  knee3.write(170);  // put the diagonal opposite leg down to keep the balance
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee1.write(140);  // lower the diagonal opposite leg a bit to keep the balance
  knee3.write(140); 
  idle();
  hip3.write(120);
  hip1.write(110);
  idle();
  knee3.write(170);
  knee3.write(170);  // put the diagonal opposite leg down to keep the balance
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee4.write(50);  // lower the diagonal opposite leg a bit to keep the balance
  knee2.write(50);
  idle();
  hip2.write(110);
  hip3.write(60);
  idle();
  knee2.write(20);
  knee4.write(20);  // put the diagonal opposite leg down to keep the balance
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee 
  knee2.write(50);  // lower the diagonal opposite leg a bit to keep the balance 
  knee4.write(50); 
  idle();
  hip4.write(30);
  hip2.write(50);
  idle();
  knee4.write(20);
  knee2.write(20);  // put the diagonal opposite leg down to keep the balance
  idle();
}
/////////////////////////////////////
void rightturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee1.write(150);
  idle();
  hip1.write(30);
  hip4.write(90);
  idle();
  knee1.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee3.write(150); 
  idle();
  hip3.write(130);
  hip1.write(100);
  idle();
  knee3.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee2.write(40);
  idle();
  hip2.write(130);
  hip3.write(50);
  idle();
  knee2.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee  
  knee4.write(40); 
  idle();
  hip4.write(70);
  hip2.write(50);
  idle();
  knee4.write(20);
  idle();
}
/////////////////////////////////////
void leftturn()
{
  // lift front right knee, move front right hip forward and rear right hip backward, lower front right knee
  knee1.write(150);
  idle();
  hip1.write(30);
  hip4.write(100);
  idle();
  knee1.write(170);
  // lift rear left knee, move rear left hip forward and front right hip backward, lower rear left knee 
  knee3.write(150); 
  idle();
  hip3.write(90);
  hip1.write(120);
  idle();
  knee3.write(170);
  // lift front left knee, move front left hip forward and rear left hip backward, lower front left knee
  knee2.write(40);
  idle();
  hip2.write(90);
  hip3.write(60);
  idle();
  knee2.write(20);
  // lift rear right knee, move rear right hip forward and front left hip backward, lower rear right knee  
  knee4.write(40); 
  idle();
  hip4.write(30);
  hip2.write(80);
  idle();
  knee4.write(20);
  idle();
}
/////////////////////////////////////
void backward()
{
// lift front right knee, move front right hip backward and rear right hip forward, lower front right knee
  knee1.write(150);
  idle();
  hip1.write(100);
  hip4.write(50);
  idle();
  knee1.write(170);
  // lift rear left knee, move rear left hip backward and front right hip forward, lower rear left knee 
  knee3.write(150); 
  idle();
  hip3.write(60);
  hip1.write(45);
  idle();
  knee3.write(170);
  // lift front left knee, move front left hip backward and rear left hip forward, lower front left knee
  knee2.write(40);
  idle();
  hip2.write(70);
  hip3.write(120);
  idle();
  knee2.write(20);
  // lift rear right knee, move rear right hip backward and front left hip forward, lower rear right knee  
  knee4.write(40); 
  idle();
  hip4.write(110);
  hip2.write(110);
  idle();
  knee4.write(20);
  idle();
}
/////////////////////////////////////
void laydown() // lay down
{
  hip1.write(70);
  hip2.write(80); 
  for (down = 170; down > 90; down = down - 1){
      knee1.write(down);
      down2 = 190 - down;
      knee2.write(down2);
      delay(15);
   } 
  delay(1000);
  hip3.write(80);
  hip4.write(70);
  for (down = 170; down > 90; down = down - 1){
      knee3.write(down);
      down2 = 190 - down;
      knee4.write(down2);
      delay(15);
  }
}
/////////////////////////////////////
void gym() // ok, this is not very serious but I needed to cheer me up a bit ;-) just see...
{
  int y;
  hip1.write(70);
  knee3.write(130);
  delay(200);
  knee2.write(40);
  hip2.write(110);
  knee2.write(20);
    delay(20);
  knee1.write(60);
    delay(20);
  hip3.write(120);
      delay(20);
  hip4.write(70);
  knee4.write(20); 
    delay(20);   
}
/////////////////////////////////////
void wink()
{
  for (b = 0; b < 3; b++){
  for (w = 60; w < 20; w = w -1)
  {
    knee1.write(w);
    delay(10);
  }
    for (w = 20; w < 60; w++)
  {
    knee1.write(w);
    delay(10);
  }
    delay(200);
  }
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void loop()
{
        stand();
        delay(1000);
}
