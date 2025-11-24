#include<reg51.h>

sbit r1 = P3^0;
sbit r2 = P3^1;
sbit r3 = P3^2;
sbit r4 = P3^3;
sbit c1 = P3^4;
sbit c2 = P3^5;
sbit c3 = P3^6;

void delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
	{
		for(j=0; j<350; j++);
	}
}

void main()
{
	while(1)
	{
		r1=r2=r3=r4=c1=c2=c3=1;
		r1=0;
		if(c1==0)
		{
			P2=0xF9; // 1
			delay(100);
		}
		else if(c2==0)
		{
			P2=0xA4; // 2
			delay(100);
		}
		else if(c3==0)
		{
			P2=0xB0; // 3
			delay(100);
		}

		r1=r2=r3=r4=c1=c2=c3=1;
		r2=0;
		if(c1==0)
		{
			P2=0x99; // 4
			delay(100);
		}
		else if(c2==0)
		{
			P2=0x92; // 5
			delay(100);
		}
		else if(c3==0)
		{
			P2=0x82; // 6
			delay(100);
		}

		r1=r2=r3=r4=c1=c2=c3=1;
		r3=0;
		if(c1==0)
		{
			P2=0xF8; // 7
			delay(100);
		}
		else if(c2==0)
		{
			P2=0x80; // 8
			delay(100);
		}
		else if(c3==0)
		{
			P2=0x90; // 9
			delay(100);
		}

		r1=r2=r3=r4=c1=c2=c3=1;
		r4=0;
		if(c1==0)
		{
			P2=0xFF; // * blank
			delay(100);
		}
		else if(c2==0)
		{
			P2=0xC0; // 0
			delay(100);
		}
		else if(c3==0)
		{
			P2=0xBF; // # dash
			delay(100);
		}
	}
}
