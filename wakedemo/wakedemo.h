#ifndef wakedemo_included
#define wakedemo_included

void makeFace(unsigned int color,unsigned int faceColor);
void update_eyes(int state);
void drawDiagonal(unsigned char col, unsigned char row,unsigned char size);
extern int state;
extern int eyes_open;
#endif
