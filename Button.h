/*
  Time.h - Library for time functions on Matrix Display.
  Created by Eric E. Valle, October 20, 2018.
  Not yet released into the public domain.
*/
#ifndef Button_h
#define Button_h

void blinking(int xPosition, int yPosition)
{
  do {
    matrix.drawPixel(xPosition, yPosition, matrix.Color333(7, 7, 7));
    delay(100);
    matrix.drawPixel(xPosition, yPosition, matrix.Color333(0, 0, 0));
    delay(100);
  } while (buttonPress() == 0);
  
}

void moveRightFromPoint(int xPosition, int yPosition)
{
  int x;
  matrix.drawPixel(xPosition, yPosition, matrix.Color333(0, 0, 4));
  do { 
    for(x=xPosition; x < 32; x++)
    {
      if((buttonPress() <= 0)||(buttonPress() >= 5))
      {
        matrix.drawPixel(x, yPosition, matrix.Color333(7, 7, 7));
        matrix.drawPixel((x-1), yPosition, matrix.Color333(0, 0, 0));
        delay(200);
      }
      else{
        break;
      }
    }
    matrix.drawPixel(31, yPosition, matrix.Color333(0, 0, 0));
    xPosition = 0;
    
    } while ((buttonPress() <= 0)||(buttonPress() >= 5));
    matrix.drawPixel((x-1), yPosition, matrix.Color333(0, 0, 0));
    XPosition = x;
    YPosition = yPosition;
  
}

void moveLeftFromPoint(int xPosition, int yPosition)
{
  int x;
  matrix.drawPixel(xPosition, yPosition, matrix.Color333(0, 0, 5));
  do { 
    for(x=xPosition; x >= 0; x--)
    {
      if((buttonPress() <= 0)||(buttonPress() >= 5))
      {
        matrix.drawPixel(x, yPosition, matrix.Color333(7, 7, 7));
        matrix.drawPixel((x+1), yPosition, matrix.Color333(0, 0, 0));
        delay(200);
      }
      else{
        break;
      }
    }
    matrix.drawPixel(0, yPosition, matrix.Color333(0, 0, 0));
    xPosition = 31;
    
    } while ((buttonPress() <= 0)||(buttonPress() >= 5));
    matrix.drawPixel((x+1), yPosition, matrix.Color333(0, 0, 0));
    XPosition = x;
    YPosition = yPosition;
  
}

void moveUpFromPoint(int xPosition, int yPosition)
{
  int y;
  matrix.drawPixel(xPosition, yPosition, matrix.Color333(0, 0, 06));
  do { 
    for(y=yPosition; y >= 0; y--)
    {
      if((buttonPress() <= 0)||(buttonPress() >= 5))
      {
        matrix.drawPixel(xPosition, y, matrix.Color333(7, 7, 7));
        matrix.drawPixel(xPosition, (y+1), matrix.Color333(0, 0, 0));
        delay(200);
      }
      else{
        break;
      }
    }
    matrix.drawPixel(xPosition, 0, matrix.Color333(0, 0, 0));
    yPosition = 15;
    
    } while ((buttonPress() <= 0)||(buttonPress() >= 5));
    matrix.drawPixel(xPosition, (y+1), matrix.Color333(0, 0, 0));
    XPosition = xPosition;
    YPosition = y;
  
}

void moveDownFromPoint(int xPosition, int yPosition)
{
  int y;
  matrix.drawPixel(xPosition, yPosition, matrix.Color333(0, 0, 7));
  do { 
    for(y=yPosition; y < 16; y++)
    {
      if((buttonPress() <= 0)||(buttonPress() >= 5))
      {
        matrix.drawPixel(xPosition, y, matrix.Color333(7, 7, 7));
        matrix.drawPixel(xPosition, (y-1), matrix.Color333(0, 0, 0));
        delay(200);
      }
      else{
        break;
      }
      
    }
    matrix.drawPixel(xPosition, 15, matrix.Color333(0, 0, 0));
    yPosition = 0;
    
    } while ((buttonPress() <= 0)||(buttonPress() >= 5));
    matrix.drawPixel(xPosition, (y-1), matrix.Color333(0, 0, 0));
    XPosition = xPosition;
    YPosition = y;
  
}

int buttonPress()
{
  matrix.drawCircle(7, 7, 7, matrix.Color333(0, 0, 7));
  pressUp = digitalRead(Up);  // read input value
  pressDown = digitalRead(Down);
  pressLeft = digitalRead(Left);
  pressRight = digitalRead(Right);
  matrix.drawCircle(7, 7, 7, matrix.Color333(0, 0, 0));
  if (pressUp == HIGH) {         // check if the input is HIGH (button released)
    matrix.drawPixel(0, 0, matrix.Color333(7, 0, 0));
    return 1;
  } else {
    matrix.drawPixel(0, 0, matrix.Color333(0, 0, 0));
  }
  if (pressDown == HIGH) {         // check if the input is HIGH (button released)
    matrix.drawPixel(31, 0, matrix.Color333(7, 0, 0));
    return 2;
  } else {
    matrix.drawPixel(31, 0, matrix.Color333(0, 0, 0));
  }if (pressLeft == HIGH) {         // check if the input is HIGH (button released)
    matrix.drawPixel(0, 15, matrix.Color333(7, 0, 0));
    return 3;
  } else {
    matrix.drawPixel(0, 15, matrix.Color333(0, 0, 0));
  }if (pressRight == HIGH) {         // check if the input is HIGH (button released)
    matrix.drawPixel(31, 15, matrix.Color333(7, 0, 0));
    return 4;
  } else {
    matrix.drawPixel(31, 15, matrix.Color333(0, 0, 0));
  }
  
}
#endif
