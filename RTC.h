#include "RTC_defines.h"
#include "types.h"

void RTC_Init(void);
void GetRTCTimeInfo(s32 *hr,s32 *mi,s32 *se);
void DisplayRTCTime(u32,u32,u32);
void GetRTCDateInfo(s32 *,s32 *,s32 *);
void DisplayRTCDate(u32,u32,u32);

void SetRTCTimeInfo(u32,u32,u32);
void SetRTCDateInfo(u32,u32,u32);

void GetRTCDay(s32 *);
void DisplayRTCDay(u32);
void SetRTCDay(u32);

void SetRTCHour(u32);
void SetRTCMin(u32);
void SetRTCSec(u32);
void SetRTCDate(u32);
void SetRTCMonth(u32);
void SetRTCYear(u32);
void SetRTCDay(u32);

void GetRTCHour(s32 *);
void GetRTCMin(s32 *);
void GetRTCSec(s32 *);
void GetRTCDate(s32 *);
void GetRTCMonth(s32 *);
void GetRTCYear(s32 *);
void GetDay(void);

 void DisplayRTCTime_uart(u32 hr,u32 mi,u32 se);
 void DisplayRTCDate_uart(u32 hr,u32 mi,u32 se);
