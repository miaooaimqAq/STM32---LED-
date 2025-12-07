#include "stm32f10x.h"   // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_Init();
	
	/* LED_ON_OFF(uint8_t x) :
	0x00:LED_1灭，LED_2灭；
	0x01:LED_1亮，LED_2灭；
	0x02:LED_1灭，LED_2亮；
	0x03:LED_1亮，LED_2亮；
	*/
	
	while(1)
	{
		KeyNum = Get_KeyNum();
		LED_ON_OFF(KeyNum);
	}
}



