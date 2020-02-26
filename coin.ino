#include <CapacitiveSensor.h>



#include <Wire.h>

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F,16,2);



CapacitiveSensor capSensor  = CapacitiveSensor(4, 2);

CapacitiveSensor capSensor2 = CapacitiveSensor(4, 5);

CapacitiveSensor capSensor5 = CapacitiveSensor(4, 6);

CapacitiveSensor capSensor10 = CapacitiveSensor(4, 7);



int ms_time   = 800;

int threshold = 640;

const int ledPin = 13;

bool led_state = LOW;

bool pass = false;



int count_c1 = 0;

int count_c2 = 0;

int count_c5 = 0;

int count_c10 = 0;

int sum       = 0;



unsigned long ms1=0;

unsigned long ms2=0;

unsigned long ms5=0;

unsigned long ms10=0;



void setup()

{

  lcd.init();                      // initialize the lcd



  // Print a message to the LCD.

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("1  2  5  10  sum");



  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  delay(50);

}



void loop()

{



   checkCoin1();

   checkCoin2();

   checkCoin5();

   checkCoin10();



   lcd.setCursor(0,1);

   lcd.print( count_c1);



   lcd.setCursor(3,1);

   lcd.print( count_c2);



   lcd.setCursor(6,1);

   lcd.print( count_c5);



   lcd.setCursor(9,1);

   lcd.print( count_c10);



   lcd.setCursor(13,1);

   lcd.print( sum);

}

void checkCoin1()

{

  long sensorValue = capSensor.capacitiveSensor(30);





  Serial.println(sensorValue);



  if (sensorValue > threshold)

  {

    if( ms1 == 0){

      ms1 = millis();

      count_c1++;

      sum = sum + 1;

    }

      digitalWrite(ledPin, HIGH);

   

  }else{

      digitalWrite(ledPin, LOW);

  }



  if( ms1 != 0){

      if( (millis() - ms1) > ms_time){

         ms1 = 0;

      }

  }

}

void checkCoin2()

{

  long sensorValue = capSensor2.capacitiveSensor(30);





  Serial.println(sensorValue);



  if (sensorValue > threshold)

  {

    if( ms2 == 0){

      ms2 = millis();

      count_c2++;

      sum = sum + 2;

    }

      digitalWrite(ledPin, HIGH);

   

  }else{

      digitalWrite(ledPin, LOW);

  }



  if( ms2 != 0){

      if( (millis() - ms2) > ms_time){

         ms2 = 0;

      }

  }

}



void checkCoin5()

{

  long sensorValue = capSensor5.capacitiveSensor(30);





  Serial.println(sensorValue);



  if (sensorValue > threshold)

  {

    if( ms5 == 0){

      ms5 = millis();

      count_c5++;

      sum = sum + 5;

    }

      digitalWrite(ledPin, HIGH);

   

  }else{

      digitalWrite(ledPin, LOW);

  }



  if( ms5 != 0){

      if( (millis() - ms5) > ms_time){

         ms5 = 0;

      }

  }

}

void checkCoin10()

{

  long sensorValue = capSensor10.capacitiveSensor(30);





  Serial.println(sensorValue);



  if (sensorValue > threshold)

  {

    if( ms10 == 0){

      ms10 = millis();

      count_c10++;

      sum = sum + 10;

    }

      digitalWrite(ledPin, HIGH);

   

  }else{

      digitalWrite(ledPin, LOW);

  }



  if( ms10 != 0){

      if( (millis() - ms10) > ms_time){

         ms10 = 0;

      }

  }

}
