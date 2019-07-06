#define clk 2 /*Clock pin encoder is connected to pin 2 of Arduino*/ 
#define dta 3 /*Data pin encoder is connected to pin 3 of Arduino*/ 
#define led 13 /*Using on board Led connected to Pin 13 of Arduino for indication purpose*/
#include <EEPROM.h>

int laststate;
int currentstate;
int counter = 0;
int lastcounter = 0;

void setup() {
pinMode(clk,INPUT);
pinMode(dta,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
laststate = digitalRead(dta);
digitalWrite(led, LOW);
lastcounter = EEPROM.read(0);
counter = lastcounter;
}

void loop() {
  currentstate = digitalRead(dta);
  digitalWrite(led, currentstate);
  if(currentstate != laststate)
  {
    if(currentstate != digitalRead(clk))
    {
      counter++;
      if(counter >32)
      {
        counter=32;
      }
      Serial.print("count: ");
      Serial.println(counter);
     }
     else
     {
      counter--;
      if(counter <0)
      {
      counter = 0;
      }
     Serial.print("count: ");
     Serial.println(counter);
     }
     
  }
EEPROM.write(0,counter); /*Storing last encoder vlue to internal EEPROM memory and will retrived in next power up*/
laststate = currentstate;
}
