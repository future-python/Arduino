#define enclk 2
#define endta 3
#define mute A0
#include <LiquidCrystal.h>

int a = 0;
int currentstate;
int laststate;
int counter = 0;
int lastcount = 0;
LiquidCrystal l(4,5,6,8,9,10,11);

byte level0[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte level1[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F};
byte level2[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F};
byte level3[] = {0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F};
byte level4[] = {0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F};
byte level5[] = {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F};
byte level6[] = {0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
byte level7[] = {0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
byte level8[] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
byte arrow[] = {0x17,0x1B,0x1D,0x00,0x00,0x1D,0x1B,0x17};
  
void setup() {

pinMode(enclk,INPUT);
pinMode(endta,INPUT);
pinMode(mute,OUTPUT);
Serial.begin(9600);

l.createChar(0,level0);
l.createChar(1,level1);
l.createChar(2,level2);
l.createChar(3,level3);
l.createChar(4,level4);
l.createChar(5,level5);
l.createChar(6,level6);
l.createChar(7,level7);
l.createChar(8,level8);
l.createChar(a,arrow);
l.begin(16,2);
bootani();
}

void loop() {
    l.setCursor(0,1);
    l.write(byte(a));
    l.print("Input Select");
  //a = encoder();
  //Serial.print(a);
  //vol_lcd(a);  
}

void vol_lcd(int vol_count)
{
 if (vol_count > 0 && vol_count <= 2)
 {
  l.setCursor(3,1);
  l.write(byte(1));
  l.print(" ");
  l.print(" ");
  l.print(" ");
  l.print(" ");
  l.print(" ");
  l.print(" ");
  l.print(" ");
 }
 else if(vol_count > 2 && vol_count <= 4)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   
 }
 else if(vol_count > 4 && vol_count <= 6)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   
 }
 else if(vol_count > 6 && vol_count <= 8)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.write(byte(4));
   l.print(" ");
   l.print(" ");
   l.print(" ");
   l.print(" ");
   
 }
 else if(vol_count > 8 && vol_count <= 10)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.write(byte(4));
   l.write(byte(5));
   l.print(" ");
   l.print(" ");
   l.print(" ");
   
 }
 else if(vol_count > 10 && vol_count <= 12)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.write(byte(4));
   l.write(byte(5));
   l.write(byte(6));
   l.print(" ");
   l.print(" ");
   
 }
 else if(vol_count > 12 && vol_count <= 14)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.write(byte(4));
   l.write(byte(5));
   l.write(byte(6));
   l.write(byte(7));
   l.print(" ");
   
 }
 else if(vol_count > 14 && vol_count <= 16)
 {
   l.setCursor(3,1);
   l.write(byte(1));
   l.write(byte(2));
   l.write(byte(3));
   l.write(byte(4));
   l.write(byte(5));
   l.write(byte(6));
   l.write(byte(7));
   l.write(byte(8));
   
 }
 
}

int encoder()
{
  currentstate = digitalRead(endta);
  if(currentstate != laststate)
  {
    if(currentstate != digitalRead(enclk))
    {
      counter++;
      if(counter>16)
      {
        counter=16;
      }
      Serial.print("count:");
      Serial.println(counter);
    }
    else
    {
      counter--;
      if(counter<0)
      {
        counter = 0;
      }
      Serial.print("count:");
      Serial.println(counter);
    }
  }
laststate = currentstate;
return counter; 
}

void bootani()
{
  l.setCursor(2,0);
  l.print("Music System");
  for(int i=0;i<=16;i++)
  {
  l.setCursor(i,1);
  l.write(byte(a));
  delay(100);
  };
}
