#include <lpc21xx.h>
#include "lcd_defines.h"
#include "types.h"
#include "lcd.h"
#include "delay.h"
void WriteLCD(u8 byte)
{
	IOCLR0=1<<LCD_RW;
	IOPIN0=((IOPIN0 & ~(255<<LCD_DATA))|(byte<<LCD_DATA));
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	delay_ms(2);
}
void cmdLCD(u8 cmd)
{
	IOCLR0=1<<LCD_RS;
	WriteLCD(cmd);
}
void InitLCD(void)
{
	IODIR0|=(255<<LCD_DATA)|(1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN);
	delay_ms(15);
	cmdLCD(0X30);
	//delayus();
	cmdLCD(0X30);
	cmdLCD(0X30);
	cmdLCD(MODE_8BIT_2lINE);
	cmdLCD(DSP_ON_CUR_ON);
	cmdLCD(CLEAR_LCD);
	cmdLCD(SHIFT_CUR_RIGHT);
}
void charLCD(u8 ascii)
{
	IOSET0=1<<LCD_RS;
	WriteLCD(ascii);
}
void StrLCD(s8 *ch)
{
	while(*ch)
	{
		charLCD(*ch++);
	}
}
void U32LCD(u32 num)
{
	u32 temp=num;
	u8 digit[10];
	s32 i=0;
	if(temp==0)
	{
		charLCD('0');
	}
	while(temp)
	{
		digit[i]=temp%10;
		temp/=10;
		i++;
	}
	for(--i;i>=0;i--)
	{
		charLCD(digit[i]+48);
	}
}
void S32LCD(s32 num)
{
	if(num<0)
	{
		charLCD('-');
		num=-num;
	}
	U32LCD(num);
}
void F32LCD(f32 fnum,u8 ndp)
{ 
	u32 num,i;
	if(fnum<0)
	{
		charLCD('-');
		fnum=-fnum;
	}
	num=fnum;
	U32LCD(num);
	charLCD('.');
	for(i=0;i<ndp;i++)
	{
		fnum=(fnum-num)*10;
		num=fnum;
		charLCD(num+48);
	}
} 

