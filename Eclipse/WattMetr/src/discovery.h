//Macros for quick work with leds and pins

#define LED_R GPIO_Pin_14
#define LED_G GPIO_Pin_12
#define LED_B GPIO_Pin_15
#define LED_O GPIO_Pin_13

#define LED_Port GPIOD

#define SetPin(port, pin) ( port ->BSRRL = pin )
#define ClrPin(port, pin) ( port ->BSRRL = pin )

#define LedOn(led) ( LED_Port ->BSRRL = led )
#define LedOff(led) ( LED_Port ->BSRRH = led )

void InitLeds(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = LED_R | LED_G | LED_B | LED_O;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(LED_Port, &GPIO_InitStructure);
}