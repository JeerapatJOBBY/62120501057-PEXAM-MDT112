#include <TinyStepper_28BYJ_48.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

const int LED_PIN = 13;
const int MOTOR_IN1_PIN = 11;
const int MOTOR_IN2_PIN = 10;
const int MOTOR_IN3_PIN = 6;
const int MOTOR_IN4_PIN = 5;
const int STEPS_PER_REVOLUTION = 2048;
    
TinyStepper_28BYJ_48 stepper;

int MILLTIME =0;
long lasttimeStrateChange = 0;
void setup(){
    
    long cuurrentTime = millis();

    pinMode(2,INPUT_PULLUP);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
    stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN);

    tone(8,800,400);// 1.

    Serial.println("Hello MDT!!");// 2.

    stepper.setSpeedInStepsPerSecond(256);
    stepper.setAccelerationInStepsPerSecondPerSecond(512);

    if (MILLTIME == 0 && cuurrentTime - lasttimeStrateChange >= 800)
    {
    stepper.moveRelativeInSteps(512);
    Serial.println("Step CW 90  Degrees");
    MILLTIME =1;
    }//3

    









}

void loop(){

}