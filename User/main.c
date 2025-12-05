#include "stm32f10x.h"                 
#include "Delay.h"
#include "Motor.h"
#include "HW.H"

int8_t Speed1;		//定义速度变量
int8_t Speed2;		//定义速度变量
int8_t a;
int8_t b;
int8_t c;


int main(void)
{
    /*模块初始化*/
    Motor_Init1();
    Motor_Init2();
    HW_Init1();
    HW_Init2();
    
    while (1)
    {
        a = HW_GetData1();
        b = HW_GetData2();
        c = a + b;
        
        if(c==2)  // 前方无障碍，直行
        {
            Speed1=88;
            Speed2=96;
            Motor_SetSpeed1(Speed1);
            Motor_SetSpeed2(Speed2);
        }
        else if(c==1)  // 一侧有障碍
        {	
            // 先停车
            Speed1=0;
            Speed2=0;
            Motor_SetSpeed1(Speed1);
            Motor_SetSpeed2(Speed2);
            
            // 延时100ms
            Delay_ms(100);
            
            // 重新读取传感器
            a = HW_GetData1();
            b = HW_GetData2();
            
            if(a==0)  // 左侧有障碍，右转
            {	
                Speed1=0;
                Speed2=80;
                Motor_SetSpeed1(Speed1);
                Motor_SetSpeed2(Speed2);
                Delay_ms(100);  // 转向持续时间
            }
            else if(b==0)  // 右侧有障碍，左转
            {
                Speed1=80;
                Speed2=0;
                Motor_SetSpeed1(Speed1);
                Motor_SetSpeed2(Speed2);
                Delay_ms(100);  //转向持续时间
            }
        }		
        else if(c==0)  // 两侧都有障碍
        {
            Speed1=0;
            Speed2=-80;
            Motor_SetSpeed1(Speed1);
            Motor_SetSpeed2(Speed2);
            Delay_ms(150);  //  后退持续时间
        }
        
        Delay_ms(50);  // 主循环小延时，稳定数据读取
    }
}
