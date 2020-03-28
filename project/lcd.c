#include "lcd.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**** Cheacking the busy flag of LCD
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void busy()
{				  
	flag=1;
	rs=0;
	rw=1;
	while(flag!=0)
	{
		en=0;
		en=1;
	}
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**** Writing command to LCD ****
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void wrt_cmd(unsigned char val_lcd)
{
	busy();
	lcd_port=val_lcd;
	rs=0;
	rw=0;
	en=1;
	en=0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~
**** Writing data on LCD ****
~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void wrt_data(unsigned char dat)
{
	busy();
	lcd_port=dat;
	rs=1;
	rw=0;
	en=1;
	en=0;
}

void wrt_string(unsigned char *string)
{
	while(*string)
		wrt_data(*string++);
}

void LCD_INI(void)
{
	wrt_cmd(0X30);
	wrt_cmd(0X0C);
	wrt_cmd(0X01);
	wrt_cmd(0X06);
}

void hex2lcd(unsigned char hex){
	char temp1,temp2;
	temp1 = hex;
	temp2=0;
	do{
		temp1 = temp1-100;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	if(temp2>0)
	wrt_data(temp2+0x30);
	temp2=0;
	temp1 = temp1+100;
	do{
		temp1 = temp1-10;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	wrt_data(temp2+0x30);
	temp2 = temp1+10;
	wrt_data(temp2+0x30);
}
