#include "stm32f10x.h"                  // Device header
#include "Delay.h"

/**
  * 函    数：按键初始化
  * 参    数：无
  * 返 回 值：无
  */
void Key_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //开启GPIOB的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU; //上拉输入
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	//将PB1和PB11引脚初始化为上拉输入
}

/**
  * 函    数：按键获取键码
  * 参    数：无
  * 返 回 值：按下按键的键码值，范围：0x00~0x02，返回0x00代表没有按键按下
  * 注意事项：此函数是阻塞式操作，当按键按住不放时，函数会卡住，直到按键松手
  */
uint8_t Get_KeyNum(void)
{
    static uint8_t last_key = 0x00; 
    
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
    {
        Delay_ms(200);
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 && last_key != 0x01)
        {
            last_key = 0x01;
            return 0x01;
        }
    }
    else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
    {
        Delay_ms(200);
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0 && last_key != 0x02)
        {
            last_key = 0x02;
            return 0x02;
        }
    }
    else
    {
        last_key = 0x00;  // 按键释放
    }
    
    return last_key;
}


