#define FOSC 12000000
#define  CCLK (FOSC*5) 
#define  PCLK (CCLK/4)
# define BAUD 9600
#define  DIVISOR (PCLK/(16* BAUD))
#define  _8BIT 3
#define  WORD_LEN _8BIT
#define  DLAB_BIT 7
#define  DR_BIT 0
#define  TEMT_BIT 6

