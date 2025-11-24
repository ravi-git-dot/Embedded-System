#include <reg51.h>
#include <string.h>

void uart_init();
void uart_tx(char ch);
char uart_rx();

void main()
{
    uart_init();          // initialize UART
    uart_tx('H');         // send single character
	  uart_tx('E');
		uart_tx('L');
	  uart_tx('L');
		uart_tx('O');

    while(1)
    {
        uart_tx(uart_rx());   // echo received char
    }
}

void uart_init()
{
    SCON = 0x50;   // Mode 1, 8-bit UART, REN=1
    TMOD = 0x20;   // Timer1 Mode2, auto-reload
    TH1  = 0xFD;   // 9600 baud @ 11.0592MHz
    TR1  = 1;      // Start Timer1
}

void uart_tx(char ch)
{
    SBUF = ch;          // Load data
    while(TI == 0);     // Wait for TX complete
    TI = 0;             // Clear flag
}

char uart_rx()
{
    while(RI == 0);     // Wait for byte
    RI = 0;             // Clear receive interrupt
    return SBUF;        // Return received data
}
