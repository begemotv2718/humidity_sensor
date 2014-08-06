#ifndef FONT_H
#define FONT_H
#include <avr/pgmspace.h>
typedef struct {
  uint8_t startchar;
  uint8_t endchar;
  uint8_t charwidth;
  uint8_t charheight;
  uint8_t byteheight;
  PGM_P font_ptr;
} font_descriptor;
#endif
