#include<reg51.h>
void delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
	{
		for(j=0; j<250; j++)
		{
		}
	}
}
void main()
{
	while(1)
	{
		P2=0X37;// a
		delay(200);
		P2=0XFF;// b
		delay(200);
		P2=0X39;// c
		delay(200);
		P2=0XF5;// d
		delay(200);
		P2=0XF9;// e 
		delay(200);
		P2=0X71;//  f
		delay(200);
		P2=0X75;// g
		delay(200);
		P2=0X76;// h
		delay(200);
		P2=0X49;// i
		delay(200);
		P2=0X0F;// j
		delay(200);
		P2=0X76;// k
		delay(200);
		P2=0X3F;// l
		delay(200);
		P2=0X73;// m
		delay(200);
		P2=0XF7;// n
		delay(200);
		P2=0X6D;// o
		delay(200);
		
	}
}