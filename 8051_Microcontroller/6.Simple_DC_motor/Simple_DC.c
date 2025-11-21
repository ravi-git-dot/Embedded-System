#include <reg51.h>

void delay(int a)
{
	int i, j;
	for(i = 0; i < a; i++)
	    for(j = 0; j < 250; j++);
}

void main()
{
	while(1)
	{
		P2=0X01;//FWD  1st motor
		delay(500);
		P2=0X08;// REV  2nd motor
		delay(500);
		P2=0X02;//REV   1st motor
		delay(500);
	  P2=0X04;// FWD	2nd motor	
		delay(500);
	}

}

//Motor 1 Forward = P2.0 = 1 ? 0x01

//Motor 2 Forward = P2.2 = 1 ? 0x04
// Forward both = 0x01 + 0x04 = 0x05

//Motor 1 Reverse = P2.1 = 1 ? 0x02

//Motor 2 Reverse = P2.3 = 1 ? 0x08
//Reverse both = 0x02 + 0x08 = 0x0A

//Motor 1 forward and Motor 2 reverse
//	0X01 + 0X08 = 0X09
//Motor 1 reverse and Motor 2 forward
//     0X02 + 0X04 = 0X06