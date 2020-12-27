#include<reg51.h>
#include<string.h>

void String_Data(char *datastr)
{
	int i;
// Send each character of string till the NULL 
	for(i=0;i<strlen(datastr);i++) 
	{SBUF = datastr[i];
// Wait till Transmission completes
	 while (TI == 0);
//Reset transmit interrupt flag
	 TI=0;}
	 return;
}	

void main()
{
// Timer 1 in Mode 2
// 8-bit auto reload mode
	TMOD = 0x20; 
// Load value for 9600 baud rate
	TH1 = 0xFD;  
// Mode 1, reception enable 
//8-bit UART communication with variable BR
    SCON = 0x50; 
// Start timer 1 
	TR1 = 1; 
	
// Transmit
 String_Data("Shruti Murarka");  
	while(1);
}
