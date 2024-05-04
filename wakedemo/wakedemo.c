#include <msp430.h>
#include <math.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

unsigned int color = COLOR_BLACK;

void update_eyes(int state)
{
  if(state)
    {
      eyes_open = 1;
      makeFace(color);
    }
}

// axis zero for col, axis 1 for row
short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};

void makeFace(unsigned int newColor)
{
   // Hardcoded color values
  unsigned int faceColor = COLOR_PINK;
  unsigned int eyeColor = color;

  int centerX = screenWidth / 2;  // X-coordinate of circle center
  int centerY = screenHeight / 2; // Y-coordinate of circle center
  int radius = 50;               // Radius of the circle for the face

  // Draw face outline (circle)
  for (int x = centerX - radius; x <= centerX + radius; x++) {
    for (int y = centerY - radius; y <= centerY + radius; y++) {
      int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
      if (distanceSquared <= radius * radius) {
	drawPixel(x, y, faceColor); // Color for face
      }
    }
  }

  // Draw eyes
  int eyeRadius = 5;
  int eyeOffsetX = 15;
  int eyeOffsetY = 10;

  // Left eye
  for (int x = centerX - eyeOffsetX - eyeRadius; x <= centerX - eyeOffsetX + eyeRadius; x++) {
    for (int y = centerY - eyeOffsetY - eyeRadius; y <= centerY - eyeOffsetY + eyeRadius; y++) {
      int distanceSquared = (x - (centerX - eyeOffsetX)) * (x - (centerX - eyeOffsetX)) + (y - (centerY - eyeOffsetY)) * (y - (centerY - eyeOffsetY));
      if (distanceSquared <= eyeRadius * eyeRadius) {
	drawPixel(x, y, eyeColor); // Always draw open eyes
      }
    }
  }

  // Right eye
  for (int x = centerX + eyeOffsetX - eyeRadius; x <= centerX + eyeOffsetX + eyeRadius; x++) {
    for (int y = centerY - eyeOffsetY - eyeRadius; y <= centerY - eyeOffsetY + eyeRadius; y++) {
      int distanceSquared = (x - (centerX + eyeOffsetX)) * (x - (centerX + eyeOffsetX)) + (y - (centerY - eyeOffsetY)) * (y - (centerY - eyeOffsetY));
      if (distanceSquared <= eyeRadius * eyeRadius) {
	drawPixel(x, y, eyeColor); // Always draw open eyes
      }
    }
  }
}
