//Program to send hex values for name string characters
#include<reg66x.h> // header file for P89C66X uc
void main()
{   unsigned char name[25] = "SHRUTI"; //string
	int i;
	//set Assert Acknowledge Flag and I2C-bus Interface Enable
	S1CON = 0x44;   
    STA = 1;        // Set STA to generate START condition
    while (!SI);    // Wait till I2C-bus Interrupt Flag=1 to confirm
    STA = 0;        //  Stop START Condition
    S1DAT = 0xAA;   // slave address 1010101 +0(W) = AA
    SI = 0;         // clear SI bit
	for(i=0;i<6;i++)    //loop 6 times
        {while (!SI);// wait till I2C-bus Interrupt Flag=1 to confirm
        S1DAT = name[i];   // send data 
        SI = 0;}          // clear SI bit
    while (!SI);     //wait till I2C-bus Interrupt Flag=1 to confirm
    STO = 1;      //set STO to generate STOP condition
    while (1);
}
