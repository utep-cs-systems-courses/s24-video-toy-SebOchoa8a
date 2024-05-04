#include <msp430.h>
#include <math.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "wakedemo.h"
#define LED BIT6/* note that bit zero req'd for display */

char blue = 31, green = 0, red = 31;
unsigned char step = 0;

// axis zero for col, axis 1 for row
short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};
short redrawScreen = 1;

void update_shape();

void makeFace(unsigned int color)
{
  int centerX = screenWidth / 2; // X-coordinate of circle center
  int centerY = screenHeight / 2; // Y-coordinate of circle center
  int radius = 50;  // Radius of the circle



  // Draw face outline (circle approximation)



  for (int x = centerX - radius; x <= centerX + radius; x++) {

    for (int y = centerY - radius; y <= centerY + radius; y++) {

      int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);

      if (distanceSquared <= radius * radius) {

	drawPixel(x, y, COLOR_TAN); // Yellow face

      }

    }

  }

  static unsigned char row = screenHeight / 2, col = screenWidth / 2;

  static char lastStep = 0;



  // Define colors

  unsigned int openEyeColor = color; // White color for open eyes

  unsigned int closedEyeColor = COLOR_BLACK; // Black color for closed eyes



  // Determine eye state (open or closed)

  int eyeState = (step % 20 < 10) ? 1 : 0; // Blink every 20 steps (10 steps open, 10 steps closed)



  // Draw eyes

  int eyeRadius = 5;
  int eyeOffsetX = 15;
  int eyeOffsetY = 10;

  // Left eye

  for (int x = col - eyeOffsetX - eyeRadius; x <= col - eyeOffsetX + eyeRadius; x++) {

    for (int y = row - eyeOffsetY - eyeRadius; y <= row - eyeOffsetY + eyeRadius; y++) {

      int distanceSquared = (x - (col - eyeOffsetX)) * (x - (col - eyeOffsetX)) + (y - (row - eyeOffsetY)) * (y - (row - eyeOffsetY));

      if (distanceSquared <= eyeRadius * eyeRadius) {

	drawPixel(x, y, (eyeState == 1) ? openEyeColor : closedEyeColor); // Draw eye based on state

      }

    }

  }
  // Right eye



  for (int x = col + eyeOffsetX - eyeRadius; x <= col + eyeOffsetX + eyeRadius; x++) {
    for (int y = row - eyeOffsetY - eyeRadius; y <= row - eyeOffsetY + eyeRadius; y++) {
      int distanceSquared = (x - (col + eyeOffsetX)) * (x - (col + eyeOffsetX)) + (y - (row - eyeOffsetY)) * (y - (row - eyeOffsetY));
      if (distanceSquared <= eyeRadius * eyeRadius) {
	drawPixel(x, y, (eyeState == 1) ? openEyeColor : closedEyeColor); // Draw eye based on state

      }

    }

  }
}
