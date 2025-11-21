#include <reg51.h>

sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(char *);
void lcd_init();
void delay(int);

void main()
{
    lcd_init();

    lcd_string("Welcome");
    lcd_cmd(0xC0);   // move to 2nd line
    lcd_string("Home");

    delay(200);

    lcd_cmd(0x01);   // clear display

    lcd_cmd(0x83);   // Line 1, position 4
    lcd_string("Hello RaviRaj");   // FIXED missing semicolon

    lcd_cmd(0xC4);   // move to 2nd line position 5
    lcd_string("Sweet Home");     // corrected spelling

    while(1);
}

void lcd_init()
{
    lcd_cmd(0x38);   // 8-bit 2-line
    lcd_cmd(0x01);   // clear display
    lcd_cmd(0x0C);   // display ON, cursor OFF
    lcd_cmd(0x80);   // line 1, position 1
}

void lcd_cmd(unsigned char ch)
{
    P2 = ch;
    rs = 0;
    rw = 0;
    en = 1;
    delay(10);
    en = 0;
}

void lcd_data(unsigned char ch)
{
    P2 = ch;
    rs = 1;      // DATA mode
    rw = 0;
    en = 1;
    delay(10);
    en = 0;
}

void lcd_string(char *str)
{
	  int k =0;
    while(str[k] != '\0')
    {
        lcd_data(str[k]);
        k++;
    }
}

void delay(int a)
{
    int i, j;
    for(i = 0; i < a; i++)
	{
		for(j = 0; j < 350; j++);
	}
}
