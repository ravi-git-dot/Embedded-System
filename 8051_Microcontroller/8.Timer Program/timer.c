#include <reg51.h>

void delay();

void main()
{
    while(1)
    {
        P2 = 0x00;   // All LEDs ON
        delay();

        P2 = 0x01;   // Only P2.0 ON
        delay();
    }
}

void delay()
{
	  TMOD = 0x01;   // Timer0 mode 1 (16-bit)
    TH0 = 0xDC;     // Load timer for approx 10ms delay 
    TL0 = 0x00;

    TR0 = 1;        // Start Timer0
    while(TF0 == 0);

    TR0 = 0;        // Stop timer
    TF0 = 1;        // Clear overflow flag (note: must write 1)
}

// for 1ms
//TH0 = 0XFC;
//TL0 = 0X67; 