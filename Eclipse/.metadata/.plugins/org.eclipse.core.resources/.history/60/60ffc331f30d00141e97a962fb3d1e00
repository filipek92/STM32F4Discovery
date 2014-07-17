#ifndef MEASURE_H
#define MEASURE_H
#include "stm32f4_discovery.h"

#define Voltage_ADC_Value (ADC_Value[0])
#define Current_ADC_Value (ADC_Value[1])

extern __IO uint16_t ADC_Value[2];

void Init_Measure(void);
float GetVoltage(void);
float GetCurrent(void);

#endif
