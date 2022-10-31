#include <Arduino.h>
//Declaring all variables as integers
int Z=0,Y=0,X=0,W=0;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  A=(!W);
  B=(!W&&X) || (W&&!X&&!Z);
  C=(!W&&Y) || (W&&X&&!Y) || (W&&!X&&Y);
  D = (!W&&Z) || (W&&X&&Y);
   W=A;
  X=B;
  Y=C;
  Z=D;
disp_7447(D,C,B,A);  
delay(1000);
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
