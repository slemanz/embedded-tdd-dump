#ifndef INC_DRIVER_GPIO_H
#define INC_DRIVER_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t state);

#ifdef __cplusplus
}
#endif

#endif /* INC_DRIVER_GPIO_H */