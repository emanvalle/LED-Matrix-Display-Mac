/*
  Time.h - Library for time functions on Matrix Display.
  Created by Eric E. Valle, October 20, 2018.
  Not yet released into the public domain.
*/
#ifndef Time_h
#define Time_h

int getHourStandard()
{
 DateTime now = rtc.now();
 int hourClock = now.hour();
 if (hourClock > 12)
 {
  hourClock = hourClock - 12;
 }
 return hourClock;
}

int getHourMilitary()
{
 DateTime now = rtc.now();
 int hourClock = now.hour();
 return hourClock;
}

int getMinute()
{
 DateTime now = rtc.now();
 int minClock = now.minute();
 return minClock;
}

int getSecond()
{
 DateTime now = rtc.now();
 int secClock = now.second();
 return secClock;
}

void timer(int number)
{
  matrix.fillRect(1, 9, 31, 15, matrix.Color333(0, 0, 0));
  int timerTempSec = 59;
  int timerTempMin = 0;
  matrix.setTextSize(1);
  matrix.setCursor(13, 8);
  matrix.print(':');
  matrix.setCursor(2, 7);
  matrix.setTextColor(matrix.Color333(7,7,7));
  switch (number) {
    case 15:
      timerTempMin = 14;
      for (int i = 15; i >= 0; i--)//minutes countdown
      { 
        matrix.print(i);
        for (int j = 59; i >= 0; j--)//seconds countdown
        {
          matrix.setCursor(
          matrix.print(j);
          delay(500);
          matrix.drawLine(15, 10, 15, 15, matrix.Color333(0, 0, 0));
          delay(500);
          newTimerSecOne();
          if ((j/10) != (timerTempSec/10))
            newTimerSecTen();
          timerTempSec = j;
          matrix.setCursor(13, 8);
          matrix.print(':');
        }
        newTimerMinOne();
        if ((i/10) != (timerTempMin/10))
          newTimerMinTen();
        timerTempSec = j;
      }
    case 30:
      timerTempMin = 30;
      for (int i = 30; i >= 0; i--)//minutes countdown
      { 
        matrix.print(i);
        for (int j = 59; i >= 0; j--)//seconds countdown
        {
          matrix.setCursor(
          matrix.print(j);
          delay(500);
          matrix.drawLine(15, 10, 15, 15, matrix.Color333(0, 0, 0));
          delay(500);
          newTimerSecOne();
          if ((j/10) != (timerTempSec/10))
            newTimerSecTen();
          timerTempSec = j;
          matrix.setCursor(13, 8);
          matrix.print(':');
        }
        newTimerMinOne();
        if ((i/10) != (timerTempMin/10))
          newTimerMinTen();
        timerTempSec = j;
      }
    case 60:
      timerTempMin = 59;
      for (int i = 60; i >= 0; i--)//minutes countdown
      { 
        matrix.print(i);
        for (int j = 59; i >= 0; j--)//seconds countdown
        {
          matrix.setCursor(
          matrix.print(j);
          delay(500);
          matrix.drawLine(15, 10, 15, 15, matrix.Color333(0, 0, 0));
          delay(500);
          newTimerSecOne();
          if ((j/10) != (timerTempSec/10))
            newTimerSecTen();
          timerTempSec = j;
          matrix.setCursor(13, 8);
          matrix.print(':');
        }
        newTimerMinOne();
        if ((i/10) != (timerTempMin/10))
          newTimerMinTen();
        timerTempSec = j;
      }
    default:
      break;
  }
}

void newHourOne()//normal time clear
{
  matrix.fillRect(8, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newTimerMinOne()//timer clear
{
  matrix.fillRect(8, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newHourTen()//normal time clear
{
  matrix.fillRect(2, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newTimerMinTen()//timer clear
{
  matrix.fillRect(8, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newMinOne()//normal time clear
{
  matrix.fillRect(24, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newTimerSecOne()//timer clear
{
  matrix.fillRect(8, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newMinTen()//normal time clear
{
  matrix.fillRect(18, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void newTimerSecTen()//timer clear
{
  matrix.fillRect(8, 1, 5, 7, matrix.Color333(0, 0, 0));
}

void dateDisplay()
{
  DateTime now = rtc.now();
  matrix.setCursor(1, 9);   
  matrix.setTextColor(matrix.Color333(0,7,0)); 
  matrix.print(daysOfTheWeek[now.dayOfTheWeek()]);
  matrix.setCursor(20, 9);   
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.print(now.day(), DEC);
}

void countDown()
{
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));
  matrix.setTextSize(2);
  matrix.setCursor(6, 0);
  matrix.setTextColor(matrix.Color333(7,7,7));

  matrix.setCursor(5, 1);
  matrix.print(10);
  delay(500);
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));
  delay(500);
  
  for (int x = 9; x > 0; x--)
  {
    matrix.setCursor(11, 1);
    matrix.print(x);
    delay(500);
    matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));
    delay(500);
    
  }

  matrix.setCursor(11, 1);
  matrix.print(0);
  delay(500);
  matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));
}

#endif
