#include "main.h"
#include "discovery.h"
#include "hd44780.h"

//extern volatile uint32_t Time;

int main(void)
{	
  SysTick_Config(SystemCoreClock/1000);
  hd44780_init(GPIOE, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_0,
  			GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, HD44780_LINES_2,
  			HD44780_FONT_5x8);

  hd44780_print("Hello World! ");
  hd44780_display(true, false, false);

  while(1)
  {
  }
}


#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
