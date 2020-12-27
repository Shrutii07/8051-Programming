#include <AT898252.H>
void main ()
{
int i;
char a[]="Shruti here";  //data which needs to be sent
SCON = 0x50;    //Initialize the serial port
TMOD = 0x20;     //self reload mode
TH1 = 221;  //load value
TR1 = 1;    //start timer 1
SPCR = 0x53;    //enable spi in master mode, fosc/128 rate
SS = 0;         //enable slave
while(1)
{
if (a[i]=='\0')     //reset i if end of string is reached
{i=0;}
SPDR = a[i];    //sending the data
while ((SPSR & 0x80) == 0);     //wait for confirmation
{i++;}
SPSR=0x00;
}
}
