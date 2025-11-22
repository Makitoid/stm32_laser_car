#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Motor.h"
#include "HW.H"

#define Speed0 0
#define Speed1 20
#define Speed2 1
#define Speed3 -10//定义速度常量

int8_t a;
int8_t b;
int8_t c;

int main(void)
{
	/*模块初始化
	依次初始化两个马达，两个红外传感器
	*/		
	Motor_Init1();		
	Motor_Init2();
	HW_Init1();
	HW_Init2();
	
	while (1)
	{
		a = HW_GetData1();
		b = HW_GetData2();
		c = a + b;//获取两个红外传感器数据
		if(c==2)
		{
			Motor_SetSpeed1(Speed1);
			Motor_SetSpeed2(Speed1);//若无障碍，正常前进；速度为40
		}
		else if(c==1)
		{	
			Motor_SetSpeed1(Speed0);
			Motor_SetSpeed2(Speed0);
			Delay_ms(100);//若检测到障碍物，先停500毫秒
			
			a = HW_GetData1();
			b = HW_GetData2();//更新红外传感器状态
			
			if(a==0)
			{
				Motor_SetSpeed1(Speed0);//若检测右方到障碍物，进行右转：左轮-20，右轮20
				Motor_SetSpeed2(Speed2);	
				Delay_ms(150);				
			}
			else if(b==0)
			{
				Motor_SetSpeed1(Speed2);//若检测左方到障碍物，进行左转：右轮-20，左轮20
				Motor_SetSpeed2(Speed0);
				Delay_ms(150);
			}
		}	
		else if(c==0)
		{
			Motor_SetSpeed1(Speed0);//若都有障碍，原地转向
			Motor_SetSpeed2(Speed3);
			Delay_ms(150);
		}
				
	}
}
