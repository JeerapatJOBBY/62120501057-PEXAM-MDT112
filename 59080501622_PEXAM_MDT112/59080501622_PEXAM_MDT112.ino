#include <TinyStepper_28BYJ_48.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

void setup(){
    pinMode(2,INPUT_PULLUP);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
}

void loop(){

}