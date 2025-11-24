#include<reg51.h>
sbit led1 = P2^0;
void delay(int a);

void main()
{
	P2   =0X01;    // make all the pin zero
	TCON = 0X01;   //raising to falling edage
	IE   = 0X81;   // Enable INTO
	while(1)
	{
		
	}
	
}
void ISR_ex0() interrupt 0   // ISR fro external interupt
{
	led1 =~ led1;
	delay(10);
}
void delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
	{
		
	}
		
}

	