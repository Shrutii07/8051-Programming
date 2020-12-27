//to & fro pattern on the LED's.
#include<reg51.h>

//Hex values for LED Bank
unsigned char LED[] = {0xFE,0xFD,0xFB,0xF7,
    0xEF,0xDF,0xBF,0x7F};

unsigned char k = 0;//variable
void main()
{
	while(1) //infinite loop
	{
	    for(k = 0; k<8 ;k++)
	    {
//Blink in forward manner
	       P1 = LED[k];		
	    }

	    for(k=7 ; k>=0 ;k--)
	    {
//Blink in backward manner
	       P1 = LED[k];		
	    }
	}
}
