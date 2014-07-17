#ifndef COMUNICATION_H
#define COMUNICATION_H

#include "stm32f4_discovery.h"

void Init_Comunication(void);
void USART_SendString(USART_TypeDef* USARTx, char* s);
void USART_SendNumber(USART_TypeDef* USARTx, uint32_t n);
void USART_SendHex(USART_TypeDef* USARTx, uint32_t n);

uint32_t StringToInt(char *s, int size);
	
#endif
