#include <LPC21xx.h>
#include "kpm_defines.h"
#include "types.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "kpm.h"
const int Kpmlut[4][4] = {
    {'1', '2', '3', '/'},
    {'4', '5', '6', 'x'},
    {'7', '8', '9', '-'},
    {'#', '0', '=', '+'}
};
void Initkpm(void)
{
	IODIR1|=15<<ROW0;
}
u32 colScan(void)
{
	u32 t;
	t=(((IOPIN1>>COL0)&15)<15)?0:1;
	return t;
}
u32 rowCheck(void)
{
	u32 rno;
	for(rno=0;rno<4;rno++)
	{
		IOPIN1=((IOPIN1 & ~(15<<ROW0))|((~(1<<rno))<<ROW0));
		if(colScan()==0)
		{
			break;
		}
	}
	IOCLR1=(15<<ROW0);
	return rno;
}
u32 colCheck(void)
{
	u32 cno;
	for(cno=0;cno<4;cno++)
	{
		if(((IOPIN1>>(COL0+cno))&1)==0)
		{
			break;
		}
	} 
	return cno;
}
u32 keyScan(void)
{
	u32 Rno,Cno,Keyv=0;
	while(colScan()==1);	
	Rno=rowCheck();
	Cno=colCheck();
	Keyv=Kpmlut[Rno][Cno];
	while(colScan()==0);
	return Keyv;
}
u32 keyRead(void)
{
	u32 sum=0;
	s8 key;
	while(1)
	{
		key=keyScan();
		if((key>='0')&&(key<='9'))
		{
			sum=((sum*10)+(key-48));
			//cmdLCD(GOTO_LINE2_POS0);
			//U32LCD(sum);
			while(colScan()==0);
		}
		else
		{
			while(colScan()==0);
			break;
		}
	}
	return sum;
}  
u32 mykeyRead(void)
{
	u32 sum=0,i=0;
	s8 key;
	while(1)
	{
		key=keyScan();
		if((key>='0')&&(key<='9'))
		{
			
			if(i<4)
			{	
				i++;
				sum=((sum*10)+(key-48));
				cmdLCD(GOTO_LINE2_POS0);
				U32LCD(sum);
			}
			while(colScan()==0);
		}
		else if(key=='-')
		{
			if(i>0)
			{
				
				i--;
			}
			cmdLCD(GOTO_LINE2_POS0);
			StrLCD("                ");
			sum=sum/10;
			if(sum!=0)
			{
				cmdLCD(GOTO_LINE2_POS0);
				U32LCD(sum);
			}
			else
			{
				cmdLCD(GOTO_LINE2_POS0);
				StrLCD("                ");
			}
			while(colScan()==0);
		}
		else if(key=='#')
		{
				i=0;
				sum=0;
			 cmdLCD(GOTO_LINE2_POS0);
				StrLCD("                ");
		}
		else if(key=='=')
		{
			while(colScan()==0);
			break;
		}
	}
	return sum;
}  
 u32 Password_scan(void)
{
	u32 sum=0,i=0,j;
	s8 key;
	while(1)
	{
		key=keyScan();
		if((key>='0')&&(key<='9'))
		{
			
			if(i<4)
			{	
				i++;
				sum=((sum*10)+(key-48));
				cmdLCD(GOTO_LINE2_POS0);
				for(j=0;j<i;j++)
				charLCD('*');
			}
			while(colScan()==0);
		}
		else if(key=='-')
		{
			if(i>0)
			{
				
				i--;
			}
			cmdLCD(GOTO_LINE2_POS0);
			StrLCD("                ");
			sum=sum/10;
			if(sum!=0)
			{
				cmdLCD(GOTO_LINE2_POS0);
				for(j=0;j<i;j++)
				charLCD('*');
			}
			else
			{
				cmdLCD(GOTO_LINE2_POS0);
				StrLCD("                ");
			}
			while(colScan()==0);
		}
		else if(key=='#')
		{
				i=0;
				sum=0;
			 cmdLCD(GOTO_LINE2_POS0);
				StrLCD("                ");
		}
		else if(key=='=')
		{
			while(colScan()==0);
			break;
		}
	}
	return sum;
}  

