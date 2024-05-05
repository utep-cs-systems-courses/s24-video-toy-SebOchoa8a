#include <msp430.h>
#include <math.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

unsigned int color = COLOR_GREEN;
unsigned int faceColor = COLOR_BLACK;
void update_eyes(int state)
{
  if(state)
    {
      eyes_open = 1;
      makeFace(color,faceColor);
    }
}

// axis zero for col, axis 1 for row
short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};

void makeFace(unsigned int newEyeColor, unsigned int newFaceColor)
{
  unsigned int faceColor = newFaceColor;
  unsigned int eyeColor = newEyeColor;
  
  int centerX = screenWidth / 2;
  int centerY = screenHeight / 2;
  int radius = 50;              
  //Draw face
  for (int x = centerX - radius; x <= centerX + radius; x++) {
    for (int y = centerY - radius; y <= centerY + radius; y++) {
      int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
      if (distanceSquared <= radius * radius) {
	drawPixel(x, y, faceColor); // Color for face
      }
    }
  }

  int eyeRadius = 5;
  int eyeOffsetX = 15;
  int eyeOffsetY = 10;
  //Draw Left eye
  for (int x = centerX - eyeOffsetX - eyeRadius; x <= centerX - eyeOffsetX + eyeRadius; x++) {
    for (int y = centerY - eyeOffsetY - eyeRadius; y <= centerY - eyeOffsetY + eyeRadius; y++) {
      int distanceSquared = (x - (centerX - eyeOffsetX)) * (x - (centerX - eyeOffsetX)) + (y - (centerY - eyeOffsetY)) * (y - (centerY - eyeOffsetY));
      if (distanceSquared <= eyeRadius * eyeRadius) {
	drawPixel(x, y, eyeColor);
      }
    }
  }
  //draw right eye
  for (int x = centerX + eyeOffsetX - eyeRadius; x <= centerX + eyeOffsetX + eyeRadius; x++) {
    for (int y = centerY - eyeOffsetY - eyeRadius; y <= centerY - eyeOffsetY + eyeRadius; y++) {
      int distanceSquared = (x - (centerX + eyeOffsetX)) * (x - (centerX + eyeOffsetX)) + (y - (centerY - eyeOffsetY)) * (y - (centerY - eyeOffsetY));
      if (distanceSquared <= eyeRadius * eyeRadius) {
	drawPixel(x, y, eyeColor); // Always draw open eyes
      }
    }
  }
}

void drawDiagonal(unsigned char col, unsigned char row, unsigned char size)
{
  unsigned char val = 0;

  while(val < size)
    {
      drawPixel(col,row,color);
      col++;
      row--;
      val++;
    }
}
