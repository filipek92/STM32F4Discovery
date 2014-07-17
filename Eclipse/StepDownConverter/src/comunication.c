#include "comunication.h"

void Init_Comunication(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART6, &USART_InitStructure);

	USART_Cmd(USART6, ENABLE); // enable USART6
	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	

	// finally this enables the complete USART1 peripheral
	USART_Cmd(USART6, ENABLE);
}

void USART_SendString(USART_TypeDef* USARTx, char* s){
	while(*s){
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) ); 
		USART_SendData(USARTx, *s);
		s++;
	}
}

void USART_SendNumber(USART_TypeDef* USARTx, uint32_t n){
	char buffer[15];
	char *p;
	buffer[14] = 0;
	p = buffer+14;
	
	while(n>0){
		p--;
		*p = (n%10)+'0';
	  n = n/10;
	}
	USART_SendString(USARTx, p);
}

void USART_SendHex(USART_TypeDef* USARTx, uint32_t n){
  char buffer[11];
	uint8_t i; 
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[10] = 0;
	
	for(i=0; i<8; i++){
		buffer[9-i] = "0123456789ABCDEF"[n & 0xF];
		n = n >> 4;
	}
	
	USART_SendString(USARTx, buffer);
}

uint32_t StringToInt(char *s, int size){
	uint32_t ret=0;
	uint32_t n;
	while(*s && size){
		ret *= 10;
		n = *s - '0';
		if(n < 10){
			ret += n;
		}
		s++;
		size--;
	}
	return ret;
}
