#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
//#include <TMRpcm.h>           //  also need to include this library...
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

int prevans=0;
int k=0;
int flag=0;
int ans=0;
char str[4];
int count = 0;
int num1,num2;
const int aPin[] ={ A0,A1,A2,A3,A6}; 
int sensorValue = 0; 
int answer()
{
  switch(str[1])
  {
    case '+': return num1+num2;
    case '-': return num1-num2;
    case '*': return num1*num2;
    case '/': return num1/num2;
  }
}
int power(int b, int e)
{
  int val=1;
  for(int z=0;z<e;z++)
  val*=b;
  return val;
}
void setup() {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
    
}
int sensor()
{
  int a,sensorValue;
  a=0;
  for(int i=0;i<5;i++)
{
  sensorValue = analogRead(aPin[i]);
  if(sensorValue<500)
  a+=power(2,i);
}
if(a)
return a;
else
sensor();
}

void loop() {
  // put your main code here, to run repeatedly:
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("first Number:");
display.display();
num1 = sensor();
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println(num1);
display.display();
delay(500);
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Second Number:");
num2=sensor();
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println(num2);
delay(1000);
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Ans");
display.println(num1+num2);
display.display();
delay(1000);

}
