#include <LPC214x.h>
#include "types.h"
#include "adc.h"
#include "adc_defines.h"
#include "delay.h"
void Intit_ADC(void)
{
	PINSEL1|=0x15400000;
	AD0CR=(1<<PDN_BIT)|(CLK_DIV<<CLKDIV_BITS);
}
void Read_ADC(u8 chNo,u32 *adcVal,f32 *ear)
{
	AD0CR&=0xffffff00;
   AD0CR|=1<<chNo;
	AD0CR|=1<<ACD_START_CONV_BIT; 
	delay_us(3);
	while(((AD0GDR>>DONE_BIT)&1)==0);
	AD0CR&=~(1<<ACD_START_CONV_BIT);
	*adcVal=(AD0GDR>>ADCVAL_BITS)&1023;
	*ear=((3.3/1023)*(*adcVal));
}

