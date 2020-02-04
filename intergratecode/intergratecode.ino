 #include "cactus_io_DHT22.h"
 #include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 
 #define analog_MQ137 A3
 #define analog_MG811 A2
 #define analog_MQ136 A1
 #define DHT22_PIN 2 
  
 DHT22 dht(DHT22_PIN);
 LiquidCrystal_I2C lcd(0x27, 16, 2);
  
  void setup()
  {
  lcd.begin();
  lcd.backlight();
  dht.begin();

  pinMode(analog_MQ137, INPUT);
  pinMode(analog_MG811, INPUT);
  pinMode(analog_MQ136, INPUT);
  }
  
  void loop()
  {
  dht.readHumidity();
  dht.readTemperature();
  
  if (isnan(dht.humidity) || isnan(dht.temperature_C)) 
  {
  return;
  }
  
  int x,y,z;
  x=analogRead(analog_MQ137);
  y=analogRead(analog_MG811);
  z=analogRead(analog_MQ136);


  lcd.setCursor(0,0);
  lcd.print("Humidity(%) : ");
  lcd.print(dht.humidity);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp(*C) : ");
  lcd.print(dht.temperature_C);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp(*F) : "); 
  lcd.print(dht.temperature_F);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("mq137 : "); 
  lcd.print(x);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("mg811 : "); 
  lcd.print(y);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("mq136 : "); 
  lcd.print(z);
  delay(1000);
  lcd.clear();

}



  
