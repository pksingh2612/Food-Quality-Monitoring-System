// mq136 and mg811 and mq137
// VCC - +5V
// GND
// AO - A5
// DO - 4
int analog_MQ136=A5;  //MQ136 Hydrogen Sulfide sensor
//const int digital_pin=4;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(analog_MQ136, INPUT);
//  pinMode(digital_pin,INPUT); 
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int x;

  x=analogRead(analog_MQ136);  //read the sensor
//x=digitalRead(digital_pin);

  //Serial.print("mq136:");
  Serial.println(x);//1 when connet to DO and // 136 ....126... 112.. when connect to A5(mq136)
  // for mg811 // 0 when connet to DO and // 19.. 20.. when connect to A5.
  // for mq137 // 1 when connect to DO and // 284.. when connect to A5.
  
  delay(1000);
}

// for mq811 the min value 250 and max value 1000  threshold min value=250;
