#include <avr/io.h>      //IO header
#define F_CPU 11059200UL //defining crystal frequency
#include <util/delay.h>  //delay header
#include "timer.h"
#include "bit.h"

static char x = 0;
static char i = 0;

void LED_Matrix(){
	
	for(int i = 0; i < 20; i++){
		if(i == 19){
			x++;
		}
	}
	
	
	char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2��2^7
	

	
	char SCROLL_RED[] = {0b00000000,0b00000000,0b01000000,0b11000000,0b01000000,0b00000000,0b00000000,0b00001000,0b00000000,0b00001000,0b00101000,0b00001000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11000000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00001000,0b00000000,0b00000000,0b01000000,0b11000000,0b11100000,0b01000000,0b00000000,0b00000100,0b00000100,0b00010000,0b00010000,0b00010000,0b00010000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00010000,0b00010100,0b00000000,0b00000000,0b01001000,0b11001000,0b11000000,0b10000000,0b00001000,0b00000000,0b00101000,0b00000000,0b00001000,0b00000000,0b00000000,0b00100000,0b00100000,0b00000000,0b00000000,0b00101000,0b00100000,0b00000000,0b00000000,0b00000010,0b00000110,0b00001110,0b00000000,0b00001110,0b00000110,0b01000010,0b11000000,0b01000000,0b00000010,0b00000110,0b00001110,0b00001110,0b00000000,0b00001110,0b00000110,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00001000,0b00001000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000010,0b00000110,0b00001110,0b00011110,0b00011110,0b00000000,0b01000000,0b11100000,0b11100010,0b01000000,0b00000000,0b00001110,0b00111110,0b00011000,0b00111110,0b00001110};
	char SCROLL[] = {0b00000001,0b00000001,0b01000001,0b11000001,0b01000001,0b00000001,0b00000001,0b00001001,0b00000001,0b00001001,0b00101001,0b00001001,0b00000001,0b00000001,0b00000001,0b00000001,0b10000111,0b11000111,0b01000001,0b00000001,0b00000001,0b00001111,0b00001111,0b00000001,0b00000001,0b00001111,0b00001111,0b00000001,0b00000001,0b00001111,0b00001111,0b00000001,0b00000001,0b00001001,0b00000001,0b00000001,0b01000001,0b11000001,0b11100000,0b01000000,0b00000001,0b00000101,0b00000101,0b00010001,0b00010001,0b00010001,0b00010001,0b00000001,0b00000001,0b00000000,0b00000000,0b00000000,0b00010001,0b00010101,0b00000001,0b00000001,0b01001001,0b11001001,0b11000001,0b10000001,0b00001001,0b00000001,0b00101001,0b00000001,0b00001001,0b00000001,0b00000001,0b00100001,0b00100001,0b00000001,0b00000001,0b00101001,0b00100001,0b00000001,0b00000001,0b00000011,0b00000111,0b00001111,0b00000001,0b00001111,0b00000111,0b01000011,0b11000001,0b01000001,0b00000011,0b00000111,0b00001111,0b00001111,0b00000000,0b00001111,0b00000111,0b00000011,0b00000001,0b00000111,0b00000111,0b00000001,0b00000001,0b00001001,0b00001001,0b00000001,0b00000001,0b00000001,0b00000111,0b00000111,0b00000011,0b00000111,0b00001111,0b00011111,0b00011111,0b00000001,0b01000001,0b11100001,0b11100011,0b01000001,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001};
	char SCROLL_BLUE[] = {0b00000000,0b00000000,0b01000000,0b11000000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b11000000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01000000,0b11000000,0b11100000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01000000,0b11000000,0b11000000,0b10000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01000000,0b11000000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01000000,0b11100000,0b11100000,0b01000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};

	//char CHARAC[] = { 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
	
	
	if(i < 8){
		PORTC = PORT[i];
		
		char pos = 0;
		
		if(i == 1){
			pos = 0b00000010;
			}else{
			pos = 0b00000000;
		}
		
		
		char temp = SCROLL[i+x] | SCROLL_RED[i+x] | SCROLL_BLUE[i+x];
		
		char temp1;
		
		if(GetBit(temp, 1)){
			if(i == 1){
				pos = 0b00000100;
				
				if(GetBit(temp, 2)){
					if(i == 1){
						pos = 0b00001000;
						
						if(GetBit(temp, 3)){
							if(i == 1){
								pos = 0b00010000;
								
								if(GetBit(temp, 4)){
									if(i == 1){
										pos = 0b00100000;
										}else{
										pos = 0b00000000;
									}
								}
								
								}else{
								pos = 0b00000000;
							}
						}
						
						}else{
						pos = 0b00000000;
					}
				}
				
				}else{
				pos = 0b00000000;
			}
		}
		
		temp1 = temp | pos;
		char temp2 = ~temp1;
		PORTA = temp2;
		i++;
		
		}else{
		i = 0;
	}
	
}

void transmit_data(unsigned char data) { //rows
	int i;
	for (i = 0; i < 8 ; ++i) {
		// Sets SRCLR to 1 allowing data to be set
		// Also clears SRCLK in preparation of sending data
		PORTC = 0x08;
		// set SER = next bit of data to be sent.
		PORTC |= ((data >> i) & 0x01);
		// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
		PORTC |= 0x02;
	}
	// set RCLK = 1. Rising edge copies data from �Shift� register to �Storage� register
	PORTC |= 0x04;
	// clears all lines in preparation of a new transmission
	PORTC = 0x00;
}

void transmit_data2(unsigned char data) { //colums
	int i;
	for (i = 0; i < 8 ; ++i) {
		// Sets SRCLR to 1 allowing data to be set
		// Also clears SRCLK in preparation of sending data
		PORTA = 0x08;
		// set SER = next bit of data to be sent.
		PORTA |= ((data >> i) & 0x01);
		// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
		PORTA |= 0x02;
	}
	// set RCLK = 1. Rising edge copies data from �Shift� register to �Storage� register
	PORTA |= 0x04;
	// clears all lines in preparation of a new transmission
	PORTA = 0x00;
}


int main(void)
{
	//DDRD = 0xFF; //PORTD as output
	//DDRD=0x00; PORTD = 0xFF;
	//DDRB=0xFF; PORTB = 0x00;
	DDRA = 0xFF; //PORTA as output
	DDRC = 0xFF; //PORTC as output
	TimerSet(1);
	TimerOn();
	
	while(1)
	{
		// there are 142 values in the set of ALPHA to display 'CIRCUIT DIGEST', then shift them after each loop execution
		
		while(!TimerFlag) {}
		//LED_Matrix();
		LED();
		//transmit_data2(0x02);
		
		TimerFlag=0;
	}
}
		