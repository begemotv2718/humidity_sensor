#define F_CPU 1000000UL                                    /* Clock Frequency = 1Mhz */

#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>

unsigned char display_E(unsigned char pos){
  PORTD=0b01110011;
  PORTC=~(1<<(3-pos));
  _delay_ms(2);
  return pos+1;
}

unsigned char display_degC(unsigned char pos){
  PORTD=0b01111000;
  PORTC=~(1<<(3-pos));
  _delay_ms(2);
  return pos+1;
}


unsigned char display_digit(unsigned char i, unsigned char pos, unsigned char point){
  unsigned char digits[10]={
    0b00111111, /*0*/
    0b00001100, /*1*/
    0b01011011, /*2*/
    0b01011110, /*3*/
    0b01101100, /*4*/
    0b01110110, /*5*/
    0b01110111, /*6*/
    0b00011100, /*7*/
    0b01111111, /*8*/
    0b01111110  /*9*/
  };
  unsigned char temp=digits[i%10]|(point<<7);
  PORTD=temp;
  PORTC=~(1<<(3-pos));
  _delay_ms(2);
  return pos+1;
}

unsigned char display_number(int n, unsigned char curpos){
  if(n==0){
    curpos=display_digit(0,curpos,0);
    return curpos;
  }
  while(n){
    curpos=display_digit(n%10,curpos,0);
    n=n/10;
  }
  return curpos;
}
  
int read_data(unsigned char* result){
  unsigned char i;
  DDRB=0b00000001;
  PORTB=0;
  _delay_ms(18);
  PORTB=1;
  _delay_us(20);
  DDRB=0b00000000;
  i=0;
  while((PINB & 1)&&(i<100)){i++;}
  if(i>=100) return(1);
  i=0;
  while(!(PINB & 1) && (i<100)){i++;}
  if(i>=100) return(2);
  i=0;
  while((PINB &1) && (i<100)){i++;}
  if(i>=100) return(3);
  
  unsigned char charpos;
  unsigned char bitpos;
  
 
  for(charpos=0;charpos<5;charpos++){
    result[charpos]=0;
    for(bitpos=0; bitpos<8;bitpos++){
      i=0;
      while(!(PINB & 1) && (i<100)){i++;}
      if(i>=100) return(4);
      i=0;
      while((PINB &1) && (i<255)){i++;}
      if(i>=255) return(5+bitpos);
      if(i>5){
        //1 transmitted
        result[charpos] |= 1<<(7-bitpos);
      }
    }
  }
  return 0;
}

       
    
int main(){                         // The main function

  DDRD=0b11111111;
  DDRC=0b00001111;
  DDRB=0b00000001;
  PORTB=1;
  int displaytime;
  unsigned char offset=0;

  unsigned char data[40];
  int res;


  while (1) {                        // Set up an infinite loop
    unsigned char pos =0;
    res=read_data(data);
    /*
    if(!res){
      for(offset=0;offset<5; offset+=1)
        for(displaytime=0;displaytime<10000;displaytime++){
         // for(counter=0;counter<2;counter++)
            //display_digit(data[counter+offset],counter,0);
           display_number(123,0);
        }
    }else{*/
      if(res>0){
        for(displaytime=0;displaytime<100;displaytime++){
          pos=display_number(res,pos);
          display_E(pos);
        }
      }else{
        for(displaytime=0;displaytime<500;displaytime++){
          display_number(data[0],0);
        }
        for(displaytime=0;displaytime<500;displaytime++){
          pos=display_degC(0);
          display_number(data[2],pos);
        }
      }
  }

}
