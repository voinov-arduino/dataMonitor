// Created by Voinov
// For art-object

#include <iarduino_RTC.h>
#include <DHT.h> // termo
#include <Adafruit_Sensor.h>
#include <Wire.h>

DHT dht(2,DHT11);
iarduino_RTC time(RTC_DS1302,6,4,5);
uint8_t moving = 10; 
int humans = 0;

void setup() {
    delay(300);1
    Serial.begin(9600);
    time.begin();
    dht.begin();
    pinMode(A1, INPUT);
    pinMode(moving, OUTPUT);
    pinMode(7, INPUT);
}

void loop(){
    if(millis()%1000==0){ // если прошла 1 секунда
      //Serial.println(time.gettime("d-m-Y, H:i:s, D")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
    }
    int h = dht.readHumidity();
    String DayTimePrinting;
    int t = dht.readTemperature();
     bool Detection = digitalRead(7);
     if(Detection == HIGH){
     int movings = 0;
     moving++;
     }
     if(Detection == LOW){
      if(moving > 0){
        humans++;
        moving = 0;
      }
     Serial.write("Температура: "+ (String)t + " Влажность: " + (String)h + " Человек: " + (String)humans + " " + (String)time.gettime("d-m-Y, H:i:s, D")); 
}
}
