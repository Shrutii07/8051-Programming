//Switches+LED's
#include<reg51.h> 

void main()
{
//switches are connected to port 2 and LED's to port 1
	while(1)
	P1=P2;
}
