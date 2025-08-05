#include <LPC21xx.H>
#include "types.h"
#include "rtc_defines.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "UART_.h"

char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};


// RTC Initialization: Configures and enables the RTC
void RTC_Init(void) 
{
  // Disable & Reset the RTC 
	CCR = RTC_RESET;
	
  // Set prescaler integer part
	PREINT = PREINT_VAL;
	
  // Set prescaler fractional part
	PREFRAC = PREFRAC_VAL;

  // Enable the RTC
	CCR = RTC_ENABLE | CLKSRC;
}

void GetRTCTimeInfo(s32 *hr,s32 *mi,s32 *se)
{
	*hr = HOUR;
	*mi = MIN;
	*se = SEC;
	
}

void DisplayRTCTime(u32 hr,u32 mi,u32 se)
{
	cmdLCD(GOTO_LINE1_POS0);
	charLCD((hr/10)+48);	//10's position value
	charLCD((hr%10)+48);	//1's position value
	charLCD(':');
	charLCD((mi/10)+48);	//10's position value
	charLCD((mi%10)+48);	//1's position value
	charLCD(':');
	charLCD((se/10)+48);	//10's position value
	charLCD((se%10)+48);	//1's position value
	
}

void GetRTCDateInfo(s32 *dt,s32 *mo,s32 *yr)
{
	*dt = DOM;
	*mo = MONTH;
	*yr = YEAR;
	
}

void DisplayRTCDate(u32 dt,u32 mo,u32 yr)
{
	int i=yr;
	cmdLCD(GOTO_LINE2_POS0);
	charLCD((dt/10)+48);	//10's position value
	charLCD((dt%10)+48);	//1's position value
	charLCD('/');
	charLCD((mo/10)+48);	//10's position value
	charLCD((mo%10)+48);	//1's position value
	charLCD('/');
	yr=yr/10;
	charLCD((yr%10)+48);
	charLCD((i%10)+48);		
	
}

void GetRTCDay(s32 *d)
{
	*d = DOW;	
}

void DisplayRTCDay(u32 d)
{
	cmdLCD(GOTO_LINE2_POS0+9);
	StrLCD(week[d]);
}
// RTC_SetTime: Sets the time and date on the RTC
void SetRTCTimeInfo(u32 hour, u32 min, u32 sec) 
{
  // Set hours	
	HOUR = hour;	  
  // Set minutes
	MIN = min;	
	// Set seconds
	SEC = sec;
}

void SetRTCDateInfo(u32 dt,u32 mo,u32 yr)
{
	// Set date
	DOM = dt;	  
  // Set month
	MONTH = mo;	
	// Set year
	YEAR = yr;	
}

void SetRTCDay(u32 day)
{
	DOW = day;
}
void DisplayRTCTime_uart(u32 hr,u32 mi,u32 se)
{
	U0_TXU32(hr);
	U0_TXByte(':');
	U0_TXU32(mi);
	U0_TXByte(':');
	U0_TXU32(se);
}
void DisplayRTCDate_uart(u32 dt,u32 mo,u32 yr)
{
	U0_TXU32(dt);
	U0_TXByte('/');
	U0_TXU32(mo);
	U0_TXByte('/');
	U0_TXU32(yr);
}


