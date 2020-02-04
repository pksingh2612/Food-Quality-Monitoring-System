// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

//LCD
//5V     <—————>    Vcc

//GND   <—————>    GND

//A4     <—————>    SDA

//A5     <—————>    SCL

#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
 #define analog_MQ137 A3
 #define analog_MG811 A2
 #define analog_MQ136 A1
 
 #define analog_LDR A0
 
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

  //I2C pins declaration
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  
 int ledPin1 = 13; // red light
 int ledPin2 = 12; // green light
 
 
  void setup()
  {
  Serial.begin(9600);
 
  lcd.begin();//Initializing display
  lcd.backlight();//To Power ON the back light
  
  //dht.begin();

  pinMode(analog_MQ137, INPUT);
  pinMode(analog_MG811, INPUT);
  pinMode(analog_MQ136, INPUT);
  pinMode(analog_LDR,INPUT);
  
  pinMode(ledPin1, OUTPUT);//when not cont.
  pinMode(ledPin2, OUTPUT);//cont.
  }
  
  void loop()
  {
   // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }

  //gas sensor
  int x,y,z,ldr;
  x=analogRead(analog_MQ137);
  y=analogRead(analog_MG811);
  z=analogRead(analog_MQ136);
  ldr=analogRead(analog_LDR);

lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("Humidity(%) : "); //You can write 16 Characters per line .
lcd.print((int)humidity);
delay(1000);//Delay used to give a dynamic effect
lcd.clear();//Clean the screen
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("Temp(*C) : "); //You can write 16 Characters per line .
lcd.print((int)temperature);
delay(1000);//Delay used to give a dynamic effect
delay(1000);//Delay used to give a dynamic effect

lcd.clear();//Clean the screen
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("LDR value : "); //You can write 16 Characters per line .
lcd.print(ldr);
delay(1000);//Delay used to give a dynamic effect

lcd.clear();//Clean the screen
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("mq137 : "); //You can write 16 Characters per line .
lcd.print(x);
delay(1000);//Delay used to give a dynamic effect
lcd.clear();//Clean the screen
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("mg811 : "); //You can write 16 Characters per line .
lcd.print(y);
delay(1000);//Delay used to give a dynamic effect
lcd.clear();//Clean the screen
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("mq136 : "); //You can write 16 Characters per line .
lcd.print(z);
delay(1000);//Delay used to give a dynamic effect
lcd.clear();//Clean the screen
digitalWrite(ledPin2,LOW);
delay(10);
digitalWrite(ledPin1,HIGH);
if (z>250 && x>350 && y>450)
{
digitalWrite(ledPin1,LOW);
digitalWrite(ledPin2,HIGH);
delay(10);
lcd.print("Food Containmented");
}
digitalWrite(ledPin2,LOW);

delay(1000);//Delay used to give a dynamic effect
lcd.clear();
float v=temperature;
float s=((v*9)/5)+32;

Serial.print("Humidity");Serial.print(",");Serial.print("Temperature(*C)");Serial.print(",");Serial.print("Temperature(*F)");Serial.print(",");Serial.print("LDR value");Serial.print(",");Serial.print("mq137");Serial.print(",");Serial.print("mg811");Serial.print(",");Serial.println("mq136");
Serial.print((int)humidity);Serial.print(",");Serial.print(v);Serial.print(",");Serial.print(s);Serial.print(",");Serial.print(ldr);Serial.print(",");Serial.print(x);Serial.print(",");Serial.print(y);Serial.print(",");Serial.println(z);
}



  
