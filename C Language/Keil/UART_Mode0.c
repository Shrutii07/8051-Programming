#include<reg51.h>
#include<string.h>

void String_Data(char *datastr)
{
	int i;
	for(i=0;i<strlen(datastr);i++) // Send each character of string till the NULL 
	{
    	SBUF = datastr[i];      //Load data
    	 while (TI == 0);       //Wait till Transmission completes
    	 TI=0;                  //Reset transmit interrupt flag
	 }     
	 return;
}	

void main()
{
	SCON = 0x00;                          // Mode 0
	String_Data("Shruti Murarka");      // Transmit 
	while(1);
}
