#include<reg51.h>

int arr[] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};

void main()
{
	 TMOD = 0x05;   // Timer0 Mode1, Counter Mode (C/T = 1)
    TH0 = 0x00;    // Initial value
    TL0 = 0x00;    
    TR0 = 1;       // Start Counter0
	while(1)
		{
		  P2 = arr[TL0];
		}
		
		
}

/*
void delay()
{
	//int arr[] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
}
void main()
{
	 TMOD = 0x05;   // Timer0 Mode1, Counter Mode (C/T = 1)
    TH0 = 0x00;    // Initial value
    TL0 = 0x00;    
    TR0 = 1;       // Start Counter0
	while(1)
		{
			//P2 = arr[TL0];
		}
		
		
}

*/
