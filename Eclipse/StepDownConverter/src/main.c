#include "main.h"

#define LED_R GPIO_Pin_14
#define LED_G GPIO_Pin_12
#define LED_B GPIO_Pin_15
#define LED_O GPIO_Pin_13

#define SETREG BSRRL
#define CLRREG BSRRH

extern volatile uint32_t Time;
uint32_t Last_Blink=0;
uint32_t Last_Send=0;

uint32_t Actual_U=0;
uint32_t Actual_I=0;

uint32_t Set_U = 0;
uint32_t Set_I = 0;

volatile uint32_t loop=0;
uint32_t f = 0;

uint16_t offset_u=0;
uint16_t offset_i=0;
int16_t calib_u=19580;
int16_t calib_i=480;


__IO uint32_t output;

__IO uint32_t out=0;

void proccess_rx(void);
void init_output(void);
void timer_init(void);
void switching(void);

int main(void)
{	
	SysTick_Config(SystemCoreClock/1000);
	STM_EVAL_LEDInit(LED3); // Oranzova
	STM_EVAL_LEDInit(LED4); // Zelena
	STM_EVAL_LEDInit(LED5); // Cervena
	STM_EVAL_LEDInit(LED6); // Modra
	
	STM_EVAL_LEDOn(LEDG);
	Delay(1000);
	STM_EVAL_LEDOff(LEDG);
	Init_Measure();
	Init_Comunication();
	init_output();
	timer_init();
	
	STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);

	USART_SendString(USART6, "\nSwitching Power Source Welcome\n");
  while(1)
  {

	  	/*if((Time-Last_Blink > 75) && output){
			STM_EVAL_LEDToggle(LEDB);
			Last_Blink=Time;
		}else if(Time-Last_Blink > 75){
			STM_EVAL_LEDToggle(LEDB);
			Last_Blink=Time;
		}*/

	 //for(int i=500000; i>0; i--);
	 GPIOD->ODR ^= LED_B;
	 Delay(100);
	 loop++;
  }
}

char rx_buffer[50];
char rx_last=0;
uint8_t rx_pointer=0;

void USART6_IRQHandler(void){
	char ch;	
	ch = USART_ReceiveData(USART6);
	
	if(ch == '\r' || ch == '\n'){
		if(rx_last != '\r'){
			rx_buffer[rx_pointer]=0;
			proccess_rx();
			rx_pointer = 0;
		}
	}else if(ch == 8 && rx_pointer>0){
		rx_pointer--;
	}else{
		rx_buffer[rx_pointer++] = ch;
	}
	rx_last = ch;
}

void proccess_rx(void){
	uint32_t u, i;
	
	switch(rx_buffer[0]){
		case 'g':
			u = Actual_U;
			i = Actual_I;
			USART_SendString(USART6, "U:");
			USART_SendNumber(USART6, u);
			USART_SendString(USART6, ", I:");
			USART_SendNumber(USART6, i);
			USART_SendString(USART6, "\n");
			break;
		case 's':
			if(rx_pointer>1){
				u = StringToInt(rx_buffer+1, 5);
				i = StringToInt(rx_buffer+6, 5);
				Set_U = u;
				Set_I = i;
				USART_SendString(USART6, "OK\n");
			}else{
				u = Set_U;
				i = Set_I;
				USART_SendString(USART6, "Set U:");
				USART_SendNumber(USART6, u);
				USART_SendString(USART6, ", Set I:");
				USART_SendNumber(USART6, i);
				USART_SendString(USART6, "\n");
			}
			break;
		case 'o':
			if(rx_pointer>1){
				output = (rx_buffer[1]=='1');
			}		
			USART_SendString(USART6, output?"Output ON\n":"Output OFF\n");
			break;
		case 'q':
			GPIO_SetBits(GPIOC, GPIO_Pin_0);
			USART_SendString(USART6, "PC0 ON\n");
			break;
		case 'a':
			GPIO_ResetBits(GPIOC, GPIO_Pin_0);
			USART_SendString(USART6, "PC0 OFF\n");
			break;
		case 'l':
			USART_SendNumber(USART6, loop/(Time/1000));
			USART_SendData(USART6, '\n');
			break;
		default:
			USART_SendString(USART6, "Unknown command\n");
			break;
	}
}

void init_output(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_3 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void timer_init(void){
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	NVIC_EnableIRQ(TIM4_IRQn);
  
  
  //25Hz meren� 200-1 50Hz 100-1 100Hz 50-1
  TIM_TimeBaseStructure.TIM_Period = 168-1; //336
  TIM_TimeBaseStructure.TIM_Prescaler = 5-1;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  
  TIM4->DIER = TIM_DIER_UIE;  // povolen� preru�en�
  
  TIM_Cmd(TIM4, ENABLE);
}

void switching(void){
		Actual_U = (Voltage_ADC_Value * calib_u/0xFFF) - offset_u;		
		Actual_I = (Current_ADC_Value * calib_i/0xFFF) - offset_i;
		
		GPIOD->BSRRH = LED_R | LED_G | LED_O;

		if((Actual_U < Set_U) && (Actual_I < Set_I) && output){ // pod omezenim
			GPIOD->BSRRL = LED_O;
			GPIOC->BSRRL = GPIO_Pin_3;
		}else if((Actual_I >= Set_I) && output){ //omezeni proudu
			GPIOD->BSRRL = LED_R;
			GPIOC->BSRRH = GPIO_Pin_3;
		}else if((Actual_U >= Set_U) && output){ //omezeni napeti
			GPIOD->BSRRL = LED_G;
			GPIOC->BSRRH = GPIO_Pin_3;
		}else{
			GPIOC->BSRRH = GPIO_Pin_3;
		}
}

void TIM4_IRQHandler(void)     
{
if(TIM4->SR & TIM_SR_UIF) // if UIF flag is set
  {
    TIM4->SR &= ~TIM_SR_UIF; // clear UIF flag                                   
    	GPIOC->ODR ^= GPIO_Pin_5;
		switching();
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
