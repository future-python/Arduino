#include <LiquidCrystal.h>

LiquidCrystal l(4,5,6,8,9,10,11); //LiquidCrystal(rs, rw, enable, d4, d5, d6, d7), Four Wire LCD connection
void setup() {
  l.begin(16,2); //16 X 2 LCD been used
  Serial.begin(9600);
}

void loop() {
  Serial.print("Enter the string that needs to be printed on LCD\n");
  l.setCursor(0,0);//cursor is set to first column, first row on LCD
  l.print("***SERIAL LCD***");
  while(Serial.available() == 0)
  { }
  if(Serial.available())
  {
    delay(100);
    //Loop to clear second row of the LCD
    for(int i = 0; i < 16; i++)
    {
      l.setCursor(i,1);
      l.print(" ");
    }
    l.setCursor(0,1);//cursor is set to first column, second row on LCD
   while(Serial.available() > 0)
   {
    //To avoid null character from serial been printed on to the LCD, if statement is used. 
     if(Serial.available()>1)
     {
     l.write(Serial.read());
     }
     else
     {
      Serial.read();
     }
   }
  }
 
}
