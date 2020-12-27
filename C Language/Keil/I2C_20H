#include<reg66x.h> // header file for P89C66X uc
void main()
{   //set Assert Acknowledge Flag and I2C-bus Interface Enable
    S1CON = 0x44;   
    STA = 1;        // Set STA to generate START condition
    while (!SI);    // Wait till I2C-bus Interrupt Flag=1 to confirm
    STA = 0;        //  Stop START Condition
    S1DAT = 0xAA;   // slave address 1010101 +0(W) = AAH
    SI = 0;         // clear SI bit
    while (!SI);    // wait till I2C-bus Interrupt Flag=1 to confirm
    S1DAT = 0x20;   // send data 20H
    SI = 0;          // clear SI bit
    while (!SI);     //wait till I2C-bus Interrupt Flag=1 to confirm
    STO = 1;      //set STO to generate STOP condition
    while (1);
}
