#include "stm32f10x.h"                  // Device header
#include "PWM.h"


 //直流电机初始化
void Motor_Init1(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PA4和PA5引脚初始化为推挽输出	
	
	PWM_Init1();													//初始化直流电机的底层PWM
}

void Motor_Init2(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PA6和PA7引脚初始化为推挽输出	
	
	PWM_Init2();													//初始化直流电机的底层PWM
}

 //直流电机设置速度
void Motor_SetSpeed1(int8_t Speed1)
{
	if (Speed1 >= 0)							//如果设置正转的速度值
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);	//PA4置高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);	//PA5置低电平，设置方向为正转
		PWM_SetCompare3(Speed1);				//PWM设置为速度值
	}
	else									//否则，即设置反转的速度值
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);	//PA4置低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_5);	//PA5置高电平，设置方向为反转
		PWM_SetCompare3(-Speed1);			//PWM设置为负的速度值，因为此时速度值为负数，而PWM只能给正数
	}
}

void Motor_SetSpeed2(int8_t Speed2)
{
	if (Speed2 >= 0)							//如果设置正转的速度值
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8);	//PA4置高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);	//PA5置低电平，设置方向为正转
		PWM_SetCompare4(Speed2);				//PWM设置为速度值
	}
	else									//否则，即设置反转的速度值
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);	//PA4置低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_9);	//PA5置高电平，设置方向为反转
		PWM_SetCompare4(-Speed2);			//PWM设置为负的速度值，因为此时速度值为负数，而PWM只能给正数
	}
}
