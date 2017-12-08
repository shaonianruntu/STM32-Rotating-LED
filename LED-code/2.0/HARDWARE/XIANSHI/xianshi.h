#ifndef __XIANSHI_H
#define __XIANSHI_H

#include "sys.h"
#include "huayang.h"

#define TongBu PAin(15)	//红外接收, 检测到红外信号时为低电

//extern u8 BUF1[DISPLAY_BUFFER_SIZE];
//extern u8 BUF2[DISPLAY_BUFFER_SIZE];

void Disp(u8 *Zifu, u32 size);
void Disp_Delay(u32 num);
void Bowen(void);
#endif
