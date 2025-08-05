#include <LPC21xx.h>
#include "types.h"
#include "UART_defines.h"

void Init_UART0(void)
{
	PINSEL0=0x00000005;
	U0LCR = (1<<DLAB_BIT)|WORD_LEN;
	U0DLM = DIVISOR>>8;
  U0DLL = DIVISOR;
	U0LCR &= 0x03;
}
void U0_TXByte(u8 byte)
{
	U0THR = byte;
	while(((U0LSR>>TEMT_BIT)&1)==0);
}
void U0_TXStr (s8 *ch)
{
	while(*ch)
	{
		U0_TXByte(*ch++);
	}
}
void U0_TXU32 (u32 num)
	{
	u32 temp=num;
	u8 digit[10];
	s32 i=0;
	if(temp==0)
	{
		U0_TXByte('0');
	}
	while(temp)
	{
		digit[i]=temp%10;
		temp/=10;
		i++;
	}
	for(--i;i>=0;i--)
	{
		U0_TXByte(digit[i]+48);
	}
}
void U0_TXS32(s32 n)
{
	if(n<0)
	{
		U0_TXByte('-');
		n=-n;
	}
		U0_TXU32(n);	
}
void U0_TXF32(f32 fNum,u8 nDP )
{
	s32 i;
	u32 n;
	if(fNum<0)
	{
		U0_TXByte('-');
		fNum=-fNum;
	}
	n=fNum;
	U0_TXU32(n);
	U0_TXByte('.');
	for(i=0;i<nDP;i++)
	{
		fNum=(fNum-n)*10;
		n=fNum;
		U0_TXByte(n+48);
	}
}

u8 U0_RxByte(void)
{
	while(((U0LSR>>DR_BIT)&1)==0);
	return U0RBR;
} 
s8 * U0_ReadStr(void)
{
	static s8 rbuf[100];
	u32 i=0;
	while(1)
	{
		rbuf[i]=U0_RxByte();
		U0_TXByte(rbuf[i]);
		if((rbuf[i]=='\n')||(rbuf[i]=='\r'))
		{
			rbuf[i]='\0';
			break;
		}	
    i++;		
	}
	return rbuf;
}

