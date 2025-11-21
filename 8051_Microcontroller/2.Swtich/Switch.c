#include<reg51.h>
sbit sw = P2^0;
sbit led = P3^0;

void main()
{
	led = 0;
	while(1)
	{
		if(sw == 0)
		{
			led = 1;
		}
		else
		{
			led = 0;
		}
	}
}