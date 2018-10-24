/* Libraries used for Hardware*/
#include <Adafruit_GFX.h>   //Core graphics library
#include <RGBmatrixPanel.h> //Hardware-specific library
#include <Wire.h>           //include Wire.h library
#include "RTClib.h"         //include Adafruit RTC library

/* User defined Libraries*/
#include "Time.h"
#include "Button.h"

/* Arduino Mega Port Definitions for Display*/
#define CLK 11              // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

/* Arduino Mega Port Definitions for Buttons*/
#define Up 4
#define Down 5
#define Left 6
#define Right 7

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);  //Make a RGBMatrixPanel matrix object
RTC_DS3231 rtc;                                       //Make a RTC DS3231 object

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};  //necessary for the date display



void setup() {
  /* Initializing the matrix display*/
  matrix.begin();

  /*initializing the Real Time Clock*/
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  //Setup of time if RTC lost power or time is not set
  if (rtc.lostPower()) {
   //Sets the code compilation time to RTC DS3231
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  /* Initializing the button ports on the Arduino */
  pinMode(Up, INPUT);
  pinMode(Down, INPUT);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);

  dateDisplay();
}

void loop() {
  int buttonValue = 0;
  buttonValue = buttonPress();

}
