#include <inttypes.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "font.h"
#include "display.h"

#define DISP_SCE BIT(2)
#define DISP_SDC BIT(3)
#define DISP_DIN BIT(4)
#define DISP_CLK BIT(5)
#define DISP_RESET BIT(1)
#define DISP_PORT PORTC


#define DISP_COMMAND 0
#define DISP_DATA 1

#define DISP_XSIZE 84
#define DISP_YSIZE 6


#define DISP_POWERDOWN 0x04
#define DISP_ENTRYMODE 0x02
#define DISP_EXTENDEDINSTRUCTION 0x01

#define DISP_DISPLAYBLANK 0x0
#define DISP_DISPLAYNORMAL 0x4
#define DISP_DISPLAYALLON 0x1
#define DISP_DISPLAYINVERTED 0x5

// H = 0
#define DISP_FUNCTIONSET 0x20
#define DISP_DISPLAYCONTROL 0x08
#define DISP_SETYADDR 0x40
#define DISP_SETXADDR 0x80

// H = 1
#define DISP_SETTEMP 0x04
#define DISP_SETBIAS 0x10
#define DISP_SETVOP 0x80



#define BIT_GET(p,m) ((p) & (m))
#define BIT_SET(p,m) ((p) |= (m))
#define BIT_CLR(p,m) ((p) &= ~(m))
#define BIT_FLIP(p,m) ((p) ^= (m))
#define BIT_WRITE(c,p,m) (c ? BIT_SET(p,m) : BIT_CLR(p,m))
#define BIT(x) (0x01 << (x))
#define LONGBIT(x) ((unsigned long)0x00000001 << (x))


uint8_t data[DISP_XSIZE*DISP_YSIZE];

void send_byte(unsigned char db, unsigned char dc){
  unsigned char bit;
  BIT_WRITE(dc,DISP_PORT,DISP_SDC);
  BIT_CLR(DISP_PORT,DISP_SCE);
  for(bit = 0x80; bit; bit >>=1){
    BIT_CLR(DISP_PORT,DISP_CLK);
    if(db & bit){
      BIT_SET(DISP_PORT,DISP_DIN);
    }else{
      BIT_CLR(DISP_PORT,DISP_DIN);
    }
    _delay_us(10);
    BIT_SET(DISP_PORT,DISP_CLK);
    _delay_us(10);
  }
} 

  
void init_display(uint8_t contrast){
  BIT_CLR(DISP_PORT,DISP_RESET);
  _delay_ms(500);
  BIT_SET(DISP_PORT,DISP_RESET);
  _delay_ms(5);
  if(contrast>0x7f){
    contrast=0x7f;
  }
  send_byte(DISP_FUNCTIONSET | DISP_EXTENDEDINSTRUCTION,DISP_COMMAND);
  send_byte(DISP_SETVOP | contrast,DISP_COMMAND);
  send_byte(DISP_SETBIAS | 0x04,DISP_COMMAND);
  send_byte(DISP_FUNCTIONSET,DISP_COMMAND);
  send_byte(DISP_DISPLAYCONTROL | DISP_DISPLAYNORMAL,DISP_COMMAND);

  send_byte(DISP_SETYADDR, DISP_COMMAND);
  send_byte(DISP_SETXADDR, DISP_COMMAND);
  memset(data,0,sizeof(data));
}

void set_contrast(uint8_t vop, uint8_t bias){
  if(vop > 0x7f) vop = 0x7f;
  if(bias > 0x07) bias =0x04;
  send_byte(DISP_FUNCTIONSET | DISP_EXTENDEDINSTRUCTION,DISP_COMMAND);
  send_byte(DISP_SETVOP | vop,DISP_COMMAND);
  send_byte(DISP_SETBIAS | bias,DISP_COMMAND);
  send_byte(DISP_FUNCTIONSET,DISP_COMMAND);
}


void upload_box(uint8_t x, uint8_t y, uint8_t dx, uint8_t dy){ 
  uint8_t i,j;
  send_byte(DISP_SETYADDR |y , DISP_COMMAND);
  for(j=y; (j<y+dy && j<DISP_YSIZE); j++){
    send_byte(DISP_SETXADDR |x , DISP_COMMAND);
    for(i=x;i<x+dx;i++){
      send_byte(data[j*DISP_XSIZE+i], DISP_DATA);
    }
  }
}  

int8_t putsxy(uint8_t x, uint8_t y, unsigned char *msg, font_descriptor *f1){
  uint8_t curx;
  curx=x;
  if(y+f1->byteheight>=DISP_YSIZE) return(-1) ;
  if(x>=DISP_XSIZE) return (-1);
  while(*msg){
    if(*msg>=f1->startchar && *msg<=f1->endchar){
      for(uint8_t i=0; i< f1->charwidth; i++){
        for(uint8_t j=0; j<f1->byteheight; j++){
          data[(y+j)*DISP_XSIZE+curx]=pgm_read_byte(&f1->font_ptr[((*msg-f1->startchar)*f1->charwidth+i)*f1->byteheight+j]);
        }
        curx++;
        if(curx>DISP_XSIZE) break;
      }
      if(curx>DISP_XSIZE) break;
    }
    msg++;
  }
  upload_box(x,y,curx-x+1,f1->byteheight);
  BIT_SET(DISP_PORT,DISP_SCE);
  return (int8_t)curx;
}
