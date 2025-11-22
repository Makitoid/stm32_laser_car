#include "stm32f10x.h"                  // Device header

void HW_Init1(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
}

void HW_Init2(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
}

uint16_t HW_GetData1(void)
{
	uint16_t temData1;
	temData1 = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);  //无障碍读取1，有障碍读取0
	return temData1;	
}

uint16_t HW_GetData2(void)
{
	uint16_t temData2;
	temData2 = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
	return temData2;	
}
