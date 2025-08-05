#include "types.h"
void Init_UART0(void);
void U0_TXByte (u8 byte);
u8 U0_RxByte (void);
void U0_TXStr (s8 *);
void U0_TXU32 (u32 );
void U0_TXS32 (s32);
void U0_TXF32 (f32,u8);
s8 * U0_ReadStr(void);

