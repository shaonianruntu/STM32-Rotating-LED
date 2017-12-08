#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "huayang.h"
#include "zimo.h"
#include "xianshi.h"

extern u8 BUF1[DISPLAY_BUFFER_SIZE];
//extern u8 BUF2[DISPLAY_BUFFER_SIZE];

//显示花纹和字符
void display(void);

/*******************************************************************************
* 函数名         : int main(void)
* 函数功能		 		 : 主函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
 int main(void)
 {	
	Clear_All(BUF1);	
//	Clear_All(BUF2);	//清除所有显示缓冲区
	delay_init();	    //延时函数初始化
	LED_Init();		  	//初始化与LED连接的硬件接口
	LED28 = 0;
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	delay_ms(5000);		//延时5秒钟,等待电机稳定
	while(1)
	{
		display();	//显示字符和花纹
	}
 }
 
 
 /*******************************************************************************
* 函数名         : void display(void)
* 函数功能		 : 显示花纹和字符
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void display(void)
{
	u16 i,j;
	u8 qiDian;	//居中显示时的起点位置
	Clear_All(BUF1);	
//	Clear_All(BUF2);	//清除所有显示缓冲区
//显示波纹,预备开始显示
	Bowen();
//光圈分割线亮
	LED16 = 0;	//中间红光圈亮
	LED28 = 0;	//最内层白光圈亮

	qiDian = Get_Centre(Welcome_SIZE);//居中"孵化器欢迎你"
//向下移入"孵化器欢迎你",向上移入尖花瓣
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 1);
//		ShangYi(BUF2, JianHuaban, 0 , BUF2_SIZE / 2, 1);
		Disp(BUF1, BUF1_SIZE);
	}
	Disp_Delay(200);	//持续显示200次
//向上移入星星,放在孵化器欢迎您的左侧
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
		Disp(BUF1,BUF1_SIZE);
	}
//向上移入星星,放在孵化器欢迎您的右侧
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian + Welcome_SIZE / 2 + 4, qiDian + Welcome_SIZE / 2 + 20, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(20);	//持续显示20次
//刷屏显示两个星星心三次,实现冒泡效果
	for(j = 0; j < 3; j++)
	{
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
			Disp(BUF1,BUF1_SIZE);
		}
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian + Welcome_SIZE / 2 + 4, qiDian + Welcome_SIZE / 2 + 20, 1);
			Disp(BUF1,BUF1_SIZE);
		}
	}
//重新向下移入"孵化器欢迎您"
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(200);	//持续显示200次
//向下移出"孵化器欢迎您",向下移出尖花瓣
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 0);
//		XiaYi(BUF2, (void *)0, 0 , BUF2_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);
	}
	
	qiDian = Get_Centre(Reai_SIZE);//居中"热爱"
//向上移入“热爱”
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Reai, qiDian, qiDian + Reai_SIZE / 2 , 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(50);	//持续显示50次
//"热（爱心）爱"
	qiDian = Get_Centre(Rekongai_SIZE);//居中"热爱"
	//向上移入“热  爱”
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Rekongai, qiDian, qiDian + Rekongai_SIZE / 2, 1);
	//	ShangYi(BUF1, Aixin, qiDian + 16, qiDian + 16 + Aixin_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Aixin, qiDian + 16, qiDian + 16 + Aixin_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(50);	//持续显示50次
	

	
	qiDian = Get_Centre(Welcome_SIZE);//居中"孵化器欢迎你"
//向上移出所有内容
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian - 20, qiDian + Welcome_SIZE / 2 + 20, 0);
		Disp(BUF1,BUF1_SIZE);		
	}
		
//从左移入孵化器长字符串
	while(ZuoYi(Fuhuaqi, Fuhuaqi_SIZE, 0, BUF1_SIZE / 2 ,1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
//从左移出孵化器长字符串
	for(i = 0; i < BUF1_SIZE / 2; i++)
	{
		ZuoYi((void *)0, 0, 0, BUF1_SIZE / 2, 0);
		Disp(BUF1, BUF1_SIZE);
	}
	Disp_Delay(20);	//持续显示20次
////向上移入尖花瓣
//	for(i = 0; i < 16; i++)
//	{
//		ShangYi(BUF2, YuanHuaban, 0 , BUF2_SIZE / 2, 1);
//		Disp(BUF1,BUF1_SIZE);
//	}
//	Disp_Delay(5);	//持续显示5次
//从右移入格言
	qiDian = Get_Centre(Geyan_SIZE);
	while(YouYi(Geyan, Geyan_SIZE, qiDian, qiDian + Geyan_SIZE / 2, 1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
//闪烁显示格言
	for(i = 0; i < 10; i ++)
	{
		Clear_All(BUF1);	
		Disp_Delay(3);
		Copy_to_Buf(Geyan, &BUF1[qiDian * 2], Geyan_SIZE-1);
		Disp_Delay(3);
	}
//向下移出格言
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Geyan_SIZE / 2, 0);
		Disp(BUF1, BUF1_SIZE);
	}
////向下移出尖花瓣
//	for(i = 0; i < 16; i++)
//	{
//		XiaYi(BUF2, (void *)0, 0 , BUF2_SIZE / 2, 0);
//		Disp(BUF1, BUF2, BUF1_SIZE);
//	}

	qiDian = Get_Centre(Xiaolian_SIZE);
//向上移入O(∩_∩)O
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xiaolian, qiDian, qiDian + Xiaolian_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//持续显示100次
//向下移除O(∩_∩)O
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Xiaolian_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);
	}
	
	qiDian = Get_Centre(Goodstudy_SIZE);
//向右移入“好好学习”
	while(YouYi(Goodstudy, Goodstudy_SIZE, qiDian, qiDian + Goodstudy_SIZE / 2, 1)==0)
	{	
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//持续显示100次	
//向上移出“好好学习”
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian, qiDian + Goodstudy_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);		
	}
	
	qiDian = Get_Centre(Dayup_SIZE);
//向左移入“天天向上”
	while(ZuoYi(Dayup, Dayup_SIZE, qiDian, qiDian + Dayup_SIZE / 2, 1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//持续显示100次	
//向下移出“天天向上”
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Dayup_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);		
	}
	qiDian = Get_Centre(Website_SIZE);
//向上移入"www.utii.org"
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Website, qiDian, qiDian + Website_SIZE / 2, 1);	
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//持续显示20次
//向下移出"www.utii.org"
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian, qiDian + Website_SIZE / 2, 0);	
		Disp(BUF1,BUF1_SIZE);
	}
	
	LED16 = 1;	//中间红光圈灭	
	delay_ms(500);
}
		
