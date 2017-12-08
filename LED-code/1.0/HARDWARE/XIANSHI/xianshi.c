#include "xianshi.h"
#include "led.h"
#include "huayang.h"
#include "delay.h"

static u8 *Backup_PTR1  = (void *)0;	//备份指针
//static u8 *Backup_PTR2  = (void *)0;	//备份指针
static u32 Backup_SIZE = 0;	//备份大小

/*******************************************************************************
* 函数名         : void Zi_Disp(u8 *Source, u32 size)
* 函数功能		 : 显示字符
* 输入           : Source:显示内容的缓冲区
				   size:缓冲区的大小(单位: 字节)
* 输出         	 : 无
*******************************************************************************/
void Disp(u8 *Zifu, u32 size)
{
	u8 i;
//	u32 temp;
	u16 temp1;
	Backup_PTR1 = Zifu;	//备份指针
//	Backup_PTR2 = Huawen;
	Backup_SIZE = size;	//备份大小
	while(TongBu == 1);	//等待红外同步信号的到来
	for(i = 0; i < size / 2; i ++)
	{
		temp1 = (*(Zifu + 1) << 8) | *Zifu;
		Zifu += 2;
//		temp2 = (*(Huawen + 1) << 8) | *Huawen;
//		Huawen += 2;
//		temp = (temp2 << 16) | temp1;
		LED_Disp(temp1);//显示该列
		delay_us(250);	//适当延时
		LED_Disp(0);	//清除显示
		
	}
}
/*******************************************************************************
* 函数名         : void Disp_Delay(u32 num)
* 函数功能		 : 刷屏,利用多次显示达到延时目的的函数
* 输入           : num: 停留显示的次数
* 输出         	 : 无
*******************************************************************************/
void Disp_Delay(u32 num)
{
	while(num --)
	{
		Disp(Backup_PTR1,Backup_SIZE);//重复显示上一帧的数据
	}
}
/*******************************************************************************
* 函数名         : void Bowen(void)
* 函数功能		 : 显示一圈圈由小到大的波纹
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Bowen(void)
{
	u32 temp1 = 1 << 26;
	u32 temp2 = 150;
	while(temp1 >= 1)
	{
		LED_Disp(temp1);
		delay_ms(temp2);//适当延时
		temp1 >>= 1;
//		temp2 -= 15;
		if(temp1==(1<<15))
		{
			LED17 = 1;
			LED16 = 0;
			delay_ms(temp2);//适当延时
//			temp2 -= 15;
			LED16 = 1;
		}
	}
	LED0 = 1;
}
