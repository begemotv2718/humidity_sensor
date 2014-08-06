#ifndef DISPLAY_H
#define DISPLAY_H
#include "font.h"
void set_contrast(uint8_t vop, uint8_t bias);
void init_display(uint8_t contrast);
void putsxy(uint8_t x, uint8_t y, unsigned char *msg,font_descriptor *f1);
void upload_box(uint8_t x, uint8_t y, uint8_t dx, uint8_t dy);
#endif
