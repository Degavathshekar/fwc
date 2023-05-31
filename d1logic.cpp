#include<Arduino.h>
int Q0,Q1,Q2;
int D0,D1,D2,d1;
void setup(){
pinMode(LED_BUILTIN,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,INPUT);
pinMode(9,OUTPUT);

Q0 = LOW;
Q1 = LOW;
Q2 = LOW;
}
void updateInputs(){
D0 = Q0;
D1 = Q2^Q1;
D2 = Q1^Q0;
d1 = Q2^Q0;
}
void nextState(){
D2 = (Q2 && Q0)  || (Q1 && Q0);
D1 = (!Q2 && Q0) ||(Q1 && !Q0);
D0 = (!Q2 && !Q1)||(Q2 && Q0);
d1 = (!Q2 && Q0) ||(Q1 && !Q0);
}
void loop(){
digitalWrite(LED_BUILTIN,HIGH);
delay(2000);
Q0 = digitalRead(2);
Q1 = digitalRead(3);
Q2 = digitalRead(4);
D0 = (!Q2 && !Q1)||(Q2 && Q1);
D1 = (!Q2 && Q0) ||(Q1 && !Q0);
D2 = (Q2 && Q0)  || (Q1 && !Q0);
d1 = (!Q2 && Q0) ||(Q1 && !Q0);

digitalWrite(LED_BUILTIN,LOW);
delay(2000);
digitalWrite(5,D0);
digitalWrite(6,D1);
digitalWrite(7,D2);
digitalWrite(9,d1);


nextState();
updateInputs();

}


