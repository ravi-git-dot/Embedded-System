#include <reg51.h>
#include <lcd.h> 
#include <string.h>

sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;
sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;

sbit Re = P3^4;
sbit G  = P3^5;
sbit R  = P3^6;

char a[] = {"7639"};  // Actual password
char b[4];            // rub time password
int n =0;
int val;
int count;
void main()
{
	lcd_init();
	Re = 0;   // Relay off
	G  = 0;   // Green LED off
	R  = 0;   // Red LED off

	//lcd_string("Welcome");

	while(1)
	{
		if (n <=3)           // limit the length of password
		{
					r1=r2=r3=r4=1;
				r1 = 0;
				if(c1 == 0)
				{
					lcd_data('*');
					b[n] = '1';
					n++;
					delay(50);
				}
				else if(c2 == 0)
				{
					lcd_data('*');
					b[n] = '2';
					n++;
					delay(50);
				}
				else if(c3 == 0)
				{
					lcd_data('*');
					b[n] = '3';
					n++;
					delay(50);
				}
				r1=r2=r3=r4=1;
				r2 = 0;
				if(c1 == 0)
				{
					lcd_data('*');
					b[n] = '4';
					n++;
					delay(50);
				}
				else if(c2 == 0)
				{
					lcd_data('*');
					b[n] = '5';
					n++;
					delay(50);
				}
				else if(c3 == 0)
				{
					lcd_data('*');
					b[n] = '6';
					n++;
					delay(50);
				}
				r1=r2=r3=r4=1;
				r3 = 0;
				if(c1 == 0)
				{
					lcd_data('*');
					b[n] = '7';
					n++;
					delay(50);
				}
				else if(c2 == 0)
				{
					lcd_data('*');
					b[n] = '8';
					n++;
					delay(50);
				}
				else if(c3 == 0)
				{
					lcd_data('*');
					b[n] = '9';
					n++;
					delay(50);
				}
					r1=r2=r3=r4=1;
				r4 = 0;
				if(c1 == 0)
				{
					lcd_data('*');
					b[n] = '*';
					n++;
					delay(50);
				}
				else if(c2 == 0)
				{
					lcd_data('*');
					b[n] = '0';
					n++;
					delay(50);
				}
				else if(c3 == 0)
				{
					lcd_data('*');
					b[n] = '#';
					n++;
					delay(50);
				}
			}
		  else 
				{
					val = strncmp(a, b, 4);
					if (val == 0)
					{
						Re=G=1;
						R = 0;
						//lcd_cmd(0X01);  // Clear display
						lcd_cmd(0X82);  // 1 line 4st position
						lcd_string("ACCESS GRANTED");
						
					}
				
					if(val >0 || val<0)
					{
						count++;
						R=1;
						Re=G=0;
						//lcd_cmd(0X01);  // Clear display
						lcd_cmd(0X83);  // 1 line 4st position
						lcd_string("ACCESS DENIED");
						delay(80);
						lcd_cmd(0X01);
						lcd_cmd(0X83);
						lcd_string("TRY AGAIN");
						n = 0;
						lcd_cmd(0XC7);
						if(count == 3)
						{
							lcd_cmd(0X01);
							lcd_cmd(0X81);
							lcd_string("ACCOUNT BLOCKED");
							delay(500);
							count = 0;
							lcd_cmd(0X01);
						  lcd_cmd(0X83);
						  lcd_string("TRY AGAIN");
							lcd_cmd(0XC7);
						}
					}
					
			   }
			
			
	}
}

