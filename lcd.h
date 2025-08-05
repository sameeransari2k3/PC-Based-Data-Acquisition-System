#include "types.h"
void WriteLCD(u8 byte);
void cmdLCD(u8 cmd);
void InitLCD(void);
void charLCD(u8 ascii);
void StrLCD(s8 *ch);
void U32LCD(u32 num);
void S32LCD(s32 num);
void F32LCD(f32 fnum,u8 ndp); 

