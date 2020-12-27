#include<reg51.h>

sbit zero = P3^0;//MOTOR PORTA
sbit one = P3^1; //MOTOR PORTB 

void main()
{
	int i;
// Dataset of values to display 0-9 on 7-segment display
unsigned char SevenSeg[] = {0xC0,0xF9,0xA4,0x99,0xB0,
   0x92,0x82,0xF8,0x80,0x90};
// timer as counter in mode 1
    TMOD = 0x50;  
	TR1 = 1; // Start counter
	
// forward motion of motor
    zero = 0;
	one = 1;
	
	while(1)
	{
		i = TL1;
		if (i==10)
// reset to zero if count exceeds 9
		{TL1 = 0x00;}  
//display on 7-segment
		P1 = SevenSeg[i]; 
	}
}
