//Macros for quick work with leds and pins
#include "stm32f4xx.h"

#define LED_R GPIO_Pin_14
#define LED_G GPIO_Pin_12
#define LED_B GPIO_Pin_15
#define LED_O GPIO_Pin_13

#define LED_Port GPIOD

#define SetPin(port, pin) ( port ->BSRRL = pin )
#define ClrPin(port, pin) ( port ->BSRRL = pin )

#define LedOn(led) ( LED_Port ->BSRRL = led )
#define LedOff(led) ( LED_Port ->BSRRL = led )

void InitLeds();
