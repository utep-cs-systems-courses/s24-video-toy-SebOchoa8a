#ifndef wakedemo_included
#define wakedemo_included

void makeFace();
void update_eyes(int state);
unsigned int change_eye_color(unsigned int color);

extern int state;
extern int eyes_open;
#endif
