#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK (CCLK/4)
#define ADC_CLK 3000000
#define CLK_DIV ((PCLK/ADC_CLK)-1)
#define CLKDIV_BITS 8
#define PDN_BIT 21
#define ACD_START_CONV_BIT 24
#define ADCVAL_BITS 6
#define DONE_BIT 31

