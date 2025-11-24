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
		for(j=0; j<350; j++)
		{
		}
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
		P2=0XF9;//1
		delay(100);
	}
	else if(c2==0)
	{
		P2=0XA4;//2
		delay(100);
	}
	else if(c3==0)
	{
		P2=0XB0;//3
		delay(100);
	}
	r1=r2=r3=r4=c1=c2=c3=1;
	r2=0;
	if(c1==0)
	{
		P2=0X99;//4
		delay(100);
	}
	else if(c2==0)
	{
		P2=0X92;//5
		delay(100);
	}
	else if(c3==0)
	{
		P2=0X82;//6
		delay(100);
	}
  r1=r2=r3=r4=c1=c2=c3=1;
	r3=0;
	if(c1==0)
	{
		P2=0XF8;//7
		delay(100);
	}
	else if(c2==0)
	{
		P2=0X80;//8
		delay(100);
	}
	else if(c3==0)
	{
		P2=0X98;//9
		delay(100);
	}
	r1=r2=r3=r4=c1=c2=c3=1;
	r4 = 0;
	if(c1 == 0) 
	{
		P2 = 0x00;  // * (blank)
		delay(100); 
	}
	else if(c2 == 0)
	{
	P2 = 0x3F; // 0
	delay(100);		
	}
	else if(c3 == 0)
	{
		P2 = 0x40; // # (dash)
		delay(100); 
	}
}	       
}
