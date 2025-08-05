#include "interrupts_pro.h"
#include "types.h"
#include "interrupts_defines_pro.h"
#include <lpc21xx.h>
void Enable_EINT1(void)
{
 PINSEL0|=0x000000C0;
 VICIntEnable=1<<EINT0_VIC_CHNO;
 VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
 VICVectAddr0=(u32)eint0_isr;
 EXTMODE=1<<0;
 } 

