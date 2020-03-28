#ifndef __LCD_H__
#define __LCD_H__

#include <REGX51.H>

#define lcd_port P2
#define rs P3_0
#define rw P3_1
#define en P3_2
#define flag P2_7

void wrt_cmd(unsigned char);
void wrt_data(unsigned char);
void wrt_string(unsigned char*);
void LCD_INI(void);
void busy(void);
void hex2lcd(unsigned char);

#endif
