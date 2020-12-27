#include<reg51.h>

void delay(int t);
void main()
{
	int t;
	unsigned char A=0x00;
//set Timer 1 in mode 1 and Timer 0 as counter
	TMOD = 0x15;

//Initial counter value 0
	TH0 = 0x00;
	TL0 = 0x00;     
	TR0 = 1;  //Start Counter
	TH1 = 0xB1;
	TL1 = 0xE0; //20ms Timer
	TR1 = 1; //Start Timer

//Run for 20ms only
     while(TF1 != 1)     
		{
//High-Low-High-Low
		 A = ~(A);      
		 P1 = A;           
//AS P3.5 IS FEEDED TO COUNTER
		 P3 = A;        
		 t = 29;
		 delay(t);
		}
}
void delay(int t)
//Delay Function
{
	while(t != 0)
		{t--;}
	return;
}
