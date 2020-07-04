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
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

int Time = 1;
long lasttimeStrateChange = 0;
bool laststate = true;
int Timetopush,TimeAWS7 = 0;

void setup(){
    pinMode(2,INPUT_PULLUP);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
    stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN);
}
int MILLTIME =0;

void loop(){
    long cuurrentTime = millis();
if (Time == 1)
{
    tone(8,800,400);// 1.

    Serial.println("Hello MDT!!");// 2.

    stepper.setSpeedInStepsPerSecond(256);
    stepper.setAccelerationInStepsPerSecondPerSecond(512);

    if (MILLTIME == 0 && cuurrentTime - lasttimeStrateChange >= 800)
    {
    stepper.moveRelativeInSteps(512);
    Serial.println("Step CW 90  Degrees");
    lasttimeStrateChange = cuurrentTime;
    MILLTIME =1;
    }//3

    if (MILLTIME == 1 && cuurrentTime - lasttimeStrateChange >= 800)
    {
    stepper.moveRelativeInSteps(-1024);
    Serial.println("Step CCW 180  Degrees");
    lasttimeStrateChange = cuurrentTime;
    MILLTIME =2;
    }//4

    if (MILLTIME == 2 && cuurrentTime - lasttimeStrateChange >= 1000) {
    oled.clearDisplay();
    oled.setCursor(32,15);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);
    oled.print("Hello MDT!!");
    oled.display();
    lasttimeStrateChange = cuurrentTime;
    MILLTIME=3;
    }//5

    if (MILLTIME == 3 && cuurrentTime - lasttimeStrateChange >= 10) {
    oled.clearDisplay();
    oled.display();
    lasttimeStrateChange = cuurrentTime;
    MILLTIME=4;
    }//5

    if (MILLTIME == 4 && cuurrentTime - lasttimeStrateChange >= 350) {
    tone(8,500,200);
    lasttimeStrateChange = cuurrentTime;
    MILLTIME=5;
    Time =2;
    }//6

}
if (Time == 2 ) 
{
    bool currentSteate = digitalRead(2);
    if(laststate > currentSteate)
    {
        Timetopush++;
        TimeAWS7++;
    }
    laststate = currentSteate;
    delay(50);

    if(Timetopush == 1 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 2 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 3 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 4 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 5 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 6 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    if(Timetopush == 7 && TimeAWS7 == 1)
    {
        stepper.setSpeedInStepsPerSecond(256);
        stepper.setAccelerationInStepsPerSecondPerSecond(512);
        stepper.moveRelativeInSteps(512);

        TimeAWS7 =0;
    }
    

    

    
}

}