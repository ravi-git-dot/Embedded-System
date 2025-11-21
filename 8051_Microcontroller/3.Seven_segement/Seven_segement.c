#include<reg51.h>

void delay(int a)
{
	int i, j;
		for(i =0; i<a; i++)
	{
		for(j =0; j<250; j++)
		{
		}
	}
}
void main()
{
	while(1)
		{
			P2 = 0XC0; //0
			delay(200);
			P2 = 0XF9; //1
			delay(100);
			P2 = 0xA4; //2
			delay(200);
			P2 = 0XB0; //3
			delay(200);
			P2 = 0X99; //4
			delay(200);
			P2 = 0X92; //5
			delay(200);
			P2 = 0X82; //6
			delay(200);
			P2 = 0XF8; //7
			delay(200);
			P2 = 0X80; //8
			delay(200);
			P2 = 0X98; //9
			delay(200);
		}
}