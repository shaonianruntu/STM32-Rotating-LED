#include "led.h"

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{ 	
	GPIO_InitTypeDef  GPIO_InitStructure;
	//使能GPIOA和GPIOB口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	
	//
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//引脚复用
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //禁止JTAG-DP和使能SW-DP

	
	GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x1fff);	//A0~A12端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);	//根据设定参数初始化GPIOA
	GPIO_SetBits(GPIOA,(uint16_t)0x1fff);	//A0~A12输出高,灭
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;	//B0~B15端口配置
	GPIO_Init(GPIOB, &GPIO_InitStructure);	//根据设定参数初始化GPIOB
	GPIO_SetBits(GPIOB,GPIO_Pin_All);	//B0~B15输出高,灭
}
 
/*******************************************************************************
* 函数名         : void LED_Zi_Disp(u16 num)
* 函数功能		 : 点亮字符该列的LED
* 输入           : num: 对应列的16位数据
* 输出         	 : 无
*******************************************************************************/
void LED_Disp(u32 num)
{
	//从低到高
	//显示字符
	LED0  = (num & (1<<0))  > 0 ? 0 : 1;	//数是1,输出0,点亮
	LED1  = (num & (1<<1))  > 0 ? 0 : 1;
	LED2  = (num & (1<<2))  > 0 ? 0 : 1;
	LED3  = (num & (1<<3))  > 0 ? 0 : 1;
	LED4  = (num & (1<<4))  > 0 ? 0 : 1;
	LED5  = (num & (1<<5))  > 0 ? 0 : 1;
	LED6  = (num & (1<<6))  > 0 ? 0 : 1;
	LED7  = (num & (1<<7))  > 0 ? 0 : 1;
	LED8  = (num & (1<<8))  > 0 ? 0 : 1;
	LED9 =  (num & (1<<9))  > 0 ? 0 : 1;
	LED10 = (num & (1<<10)) > 0 ? 0 : 1;
	LED11 = (num & (1<<11)) > 0 ? 0 : 1;
	LED12 = (num & (1<<12)) > 0 ? 0 : 1;
	LED13 = (num & (1<<13)) > 0 ? 0 : 1;
	LED14 = (num & (1<<14)) > 0 ? 0 : 1;
	LED15 = (num & (1<<15)) > 0 ? 0 : 1;
	//显示花瓣
	LED17 = (num & (1<<16)) > 0 ? 0 : 1;
	LED18 = (num & (1<<17)) > 0 ? 0 : 1; 
	LED19 = (num & (1<<18)) > 0 ? 0 : 1;
	LED20 = (num & (1<<19)) > 0 ? 0 : 1;
	LED21 = (num & (1<<20)) > 0 ? 0 : 1;
	LED22 = (num & (1<<21)) > 0 ? 0 : 1;
	LED23 = (num & (1<<22)) > 0 ? 0 : 1;
	LED24 = (num & (1<<23)) > 0 ? 0 : 1;
	LED25 = (num & (1<<24)) > 0 ? 0 : 1;
	LED26 = (num & (1<<25)) > 0 ? 0 : 1;
	LED27 = (num & (1<<26)) > 0 ? 0 : 1;
}
