#include<reg51.h>
#include<string.h>

sbit rs = P3^2;         
sbit rw = P3^1;
sbit en = P3^3;

//User defined functions
void LCD_Init();
void LCD_Cmd(unsigned char cmd);        
void LCD_string(unsigned char *string);
void LCD_Data(unsigned char data1);
void delay_us(unsigned int t);

void main()
{
//Initialize LCD
   LCD_Init();                 
//sent name to 1st line of LCD
   LCD_string("SHRUTI");	 	
// Move the Cursor to Second line First Position
   LCD_Cmd(0xC0);	            
//sent surname to 2nd line of LCD
   LCD_string("MURARKA");		
//Move the Cursor to First line First position again
   LCD_Cmd(0x80);             
   delay_us(2500);
//LCD_Cmd(0x06);//Clear LCD
}
void LCD_Cmd(unsigned char cmd)
{
    rs = 0; // Command Mode
	rw = 0; //Write mode LCD
	P2 = cmd;// Send the command to LCD
	en= 1;// Negative Edge
	delay_us(1000);
	en= 0;
	return;
}
void LCD_Init()
{
// LCD 2 lines, 5*7 matrix
    LCD_Cmd(0x38);  
// Display ON cursor ON
	LCD_Cmd(0x0E);
//Increment Cursor
	LCD_Cmd(0x06);        
	return;
}
void LCD_string(unsigned char *string)
{
	int i;
	int j =strlen(string);
//characters sent from string
	for(i=0; i< j; i++)
    	{LCD_Data(string[i]);
    	delay_us(1000);}
	return;
}
void LCD_Data(unsigned char data1)
{
	rw = 0;//Write mode LCD
	rs = 1;//Data Mode
// Send the data to LCD
	P2 = data1;
	en = 1;// Negative Edge
	delay_us(1000);
	en = 0;
	return;
}
void delay_us(unsigned int t)   //Delay function
{
	while(t!=0)
		t--;
}
