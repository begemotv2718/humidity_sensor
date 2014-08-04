#define F_CPU 1000000UL                                    /* Clock Frequency = 1Mhz */
#define FACTOR (F_CPU/1000000UL)

#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include "display.h"

  
int read_data(unsigned char* result){
  unsigned char i;
  DDRB=0b00000001;
  PORTB=0;
  _delay_ms(18);
  PORTB=1;
  _delay_us(20);
  DDRB=0b00000000;
  i=0;
  while((PINB & 1)&&(i<100*FACTOR)){i++;}
  if(i>=100) return(1);
  i=0;
  while(!(PINB & 1) && (i<100*FACTOR)){i++;}
  if(i>=100) return(2);
  i=0;
  while((PINB &1) && (i<100*FACTOR)){i++;}
  if(i>=100) return(3);
  
  unsigned char charpos;
  unsigned char bitpos;
  
 
  for(charpos=0;charpos<5;charpos++){
    result[charpos]=0;
    for(bitpos=0; bitpos<8;bitpos++){
      i=0;
      while(!(PINB & 1) && (i<100*FACTOR)){i++;}
      if(i>=100*FACTOR) return(4);
      i=0;
      while((PINB &1) && (i<255*FACTOR)){i++;}
      if(i>=255*FACTOR) return(5+bitpos);
      if(i>5){
        //1 transmitted
        result[charpos] |= 1<<(7-bitpos);
      }
    }
  }
  return 0;
}

unsigned char print_digits(unsigned char x, unsigned char *str){
  unsigned char cur_digit;
  unsigned char str_pos;
  str_pos=0;
  cur_digit=0;
  while(x>=100){
    x-=100;
    cur_digit++;
  }
  if(cur_digit>0 || str_pos>0){
    str[str_pos]=cur_digit+'0';
    str_pos++;
  }
  cur_digit=0;
  while(x>=10){
    x-=10;
    cur_digit++;
  }
  if(cur_digit>0 || str_pos>0){
    str[str_pos]=cur_digit+'0';
    str_pos++;
  }
  str[str_pos]=x+'0';
  str_pos++;
  str[str_pos]=0;
  str_pos++;
  return(str_pos);
}
  

    
unsigned char print_digits_int(unsigned char str_pos, int x, unsigned char buflen, unsigned char *str){
  unsigned char digits[8];
  if(x<0 && str_pos<buflen){
    str[str_pos++]='-';
    x=x*(-1);
  }
  if(x==0 && str_pos<buflen){
    str[str_pos++]='0';
    str[str_pos]=0;
    return(str_pos);
  }
  unsigned char i=0;
  while(x>0){
    digits[i++] = x%10;
    x=x/10;
  }
  while(i>0 && str_pos<buflen){
    str[str_pos++]=digits[--i]+'0';
  }
  str[str_pos]=0;
  return(str_pos);
}

unsigned char print_str(unsigned char str_pos, unsigned char *source, unsigned char buflen, unsigned char *target){
  while(*source && str_pos<buflen){
    target[str_pos++]=*source++;
  }
  target[str_pos]=0;
  return(str_pos);
}

#define BUF_LEN 16    
int main(){                         // The main function

  DDRB=0b00000001;
  PORTB=1;

  unsigned char data[5];

  unsigned char datastring[BUF_LEN];
  unsigned char errstr[2];
  int res;
  int temperature;
  unsigned char temperature_frac;
  int humidity;
  unsigned char humidity_frac;
  unsigned char str_pos;


  DDRC=0b00111110;
  init_display(15);
  set_contrast(23,2);

  while (1) {                        // Set up an infinite loop
    res=read_data(data);
    if(res==0 && data[0]+data[1]+data[2]+data[3]== data[4]){
      putsxy(0,0,"                ");
      putsxy(0,0,"Температура:");
      temperature = data[2]*256+data[3];
      temperature_frac = temperature % 10;
      temperature = temperature/10;
      str_pos=0;
      str_pos=print_digits_int(str_pos,temperature,BUF_LEN,datastring);
      str_pos=print_str(str_pos,".",BUF_LEN,datastring);
      str_pos=print_digits_int(str_pos,temperature_frac,BUF_LEN,datastring);
      str_pos=print_str(str_pos,"C",BUF_LEN,datastring);
      putsxy(0,1,"                ");
      putsxy(0,1,datastring);

      putsxy(0,2,"                ");

      putsxy(0,3,"                ");
      putsxy(0,3,"Влажность:");
      humidity = data[0]*256+data[2];
      humidity_frac = humidity % 10;
      humidity = humidity/10;
      str_pos=0;
      str_pos=print_digits_int(str_pos,humidity,BUF_LEN,datastring);
      str_pos=print_str(str_pos,".",BUF_LEN,datastring);
      str_pos=print_digits_int(str_pos,humidity_frac,BUF_LEN,datastring);
      str_pos=print_str(str_pos,"%",BUF_LEN,datastring);
      putsxy(0,4,"                ");
      putsxy(0,4,datastring);
      putsxy(0,5,"                ");
    }else{
      putsxy(0,0,"Error!          ");
      errstr[0]=res+'0';
      errstr[1]=0;
      putsxy(0,1,"                ");
      putsxy(0,1,errstr);
    }
    _delay_ms(3000);
  }
}

