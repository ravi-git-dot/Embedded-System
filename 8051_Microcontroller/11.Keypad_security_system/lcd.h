
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

void lcd_init();
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_string(char *str);
void delay(int a);


void lcd_init()
{
	lcd_cmd(0x38);    // 8-bit, 2 line
	lcd_cmd(0x0C);    // Display ON, cursor off
	lcd_cmd(0x01);    // Clear display
	//lcd_cmd(0x84);    // First line, 4th position
	lcd_cmd(0XC7);
}

void lcd_data(unsigned char ch)
{
	P2 = ch;
	rs = 1;
	rw = 0;
	en = 1;
	delay(5);
	en = 0;
	delay(5);
}

void lcd_cmd(unsigned char ch)
{
	P2 = ch;
	rs = 0;
	rw = 0;
	en = 1;
	delay(5);
	en = 0;
	delay(5);
}

void lcd_string(char *str)
{
	int k = 0;
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
		for(j = 0; j < 1275; j++);
		{
		}
	}
}

