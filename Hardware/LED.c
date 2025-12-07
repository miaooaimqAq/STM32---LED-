#include "stm32f10x.h"                  // Device header


/**
  * 函    数：LED_1,LED_2初始化
  * 参    数：无
  * 返 回 值：无
  */
void LED_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2); //使LED的默认状态为关闭
}

/**
  * 函    数：开启和关闭 LED
  * 参    数：无
  * 返 回 值：无
  */

void LED_ON_OFF(uint8_t led_state)  // 使用1个字节存储状态
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2); //使LED的默认状态为关闭
    // 根据位状态点亮LED
    if(led_state & 0x01)  
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_1); //LED_1亮
    }
    if(led_state & 0x02)  
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);//LED_2亮
    }
}







