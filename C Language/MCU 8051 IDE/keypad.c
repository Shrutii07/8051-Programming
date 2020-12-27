#include<reg51.h>
//Array containing values to Display 0-9 in 7-Segment Display
unsigned char Seg[] = {0xC0,0xF9,0xA4,0xB0,0x99,
     0x92,0x82,0xF8,0x80,0x90};
void display(unsigned char num)
{
//LED binary Equivalent
	 P0 = ~(num);
//7-seg display
	P2 = Seg[num];	   
	return;
}

void main()
{
 while(1)
 {	
 //Initially LED's and 7-segment is OFF.
	 P0 = 0xFF;
	 P2 = 0xFF;
	 P1 = 0xFF;

	 P1_0 = 0; //Row 4 check
	 //Column check
	 if( P1_5 == 0)	 
		 {display(0);//display number
		  break;}

	 P1_0=P1_1=P1_2=P1_2=1;
	 
	 P1_3=0; //Row 1 check
	 //Column check
	 if (P1_6 == 0)	//C1 check
		 {display(1);
		  break;}
	 else if(P1_5 == 0) //C2 check
		 {display(2);
		  break;}
	 else if(P1_4 == 0)//C3 check
		 {display(3);
		  break;}

	 P1_0=P1_1=P1_2=P1_2=1;
	 P1_2 =0; //Row 2 check
	 //Column check
	 if (P1_6 == 0)	 
		 {display(4);
		  break;}
	 else if(P1_5 == 0)
		 {display(5);
		  break;}
	 else if(P1_4 == 0)
		 {display(6);
		  break;}

	 P1_0=P1_1=P1_2=P1_2=1;
	 P1_1=0; //Row 3 check
	 //Column check
	 if (P1_6 == 0) 
	 	 {display(7);
	 	  break;}
	 else if(P1_5 == 0)
	 	 {display(8);
	 	  break;}
	 else if(P1_4 == 0)
	 	 {display(9);
	 	  break;}
  }
}
