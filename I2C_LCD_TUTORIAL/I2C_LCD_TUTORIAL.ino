//5V     <—————>    Vcc

//GND   <—————>    GND

//A4     <—————>    SDA

//A5     <—————>    SCL


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
lcd.begin();//Initializing display
lcd.backlight();//To Power ON the back light
//lcd.backlight();// To Power OFF the back light
}
void loop() 
{
//Write your code
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print(" Tech Maker "); //You can write 16 Characters per line .
delay(1000);//Delay used to give a dynamic effect
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("Like | Share");
delay(8000); 
lcd.clear();//Clean the screen
lcd.setCursor(0,0); 
lcd.print(" SUBSCRIBE ");
lcd.setCursor(0,1);
lcd.print(" TECH MAKER ");
delay(8000); 
}
