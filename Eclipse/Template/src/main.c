#include "main.h"
#include "discovery.h"

//extern volatile uint32_t Time;

int main(void)
{	
  SysTick_Config(SystemCoreClock/1000);
  InitLeds();
  LedOn(LED_R | LED_G);
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
