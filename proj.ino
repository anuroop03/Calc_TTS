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

const int aPin[] ={ A0,A1,A2,A3,A6}; 
int sensorValue = 0; 

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

int ans=0;
int opp1=0;
int opp2=0;
int op;
void loop() {
  // put your main code here, to run repeatedly:
String an;
ans = 0;
display.clearDisplay();
for(int i=0;i<5;i++)
{
  sensorValue = analogRead(aPin[i]);
  if(sensorValue<500)
  ans+=power(2,i);
}
if(ans<10)
{
  an=ans;
  opp1=ans;
         
  }

else
switch(ans)
{
  case 10: an='+';
           break;
  case 11: an='-';
           break;
  case 12: an='*';
           break;
  case 13: an='/';
           break;
  case 14: an="sin()";
           break;
  case 15: an="cos()";
           break;
  case 16: an="tan()";
           break;
  default: an= ans;            
}
display.setTextSize(4);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println(an);
display.display();
delay(1000);
op=ans;
opp2=0;
if(op>9&&opp1);
{
  switch(op)
  {
    case 10:
    case 11:
    case 12:
    case 13:for(int i=0;i<5;i++)
           {
            sensorValue = analogRead(aPin[i]);
            if(sensorValue<500)
            ans+=power(2,i);
           }
           if(ans<10)
           opp2=ans;
           break;
  case 14: display.println(sin(opp1));
           break;
  case 15: display.println(cos(opp1));
           break;
  case 16: display.println(tan(opp1));                   
  }     
  if(opp2)
  {
    if(op==10)
    display.println(opp1+opp2);
    
    if(op==11)
    display.println(opp1-opp2);
  
  }
//display.display();
}
}
