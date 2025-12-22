#ifndef INC_DRIVER_UART_H
#define INC_DRIVER_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

void UART_Transmit(UART_RegDef_t *pUARTx, const uint8_t *pData, uint16_t Size, uint32_t Timeout);

#ifdef __cplusplus
}
#endif

#endif /* INC_DRIVER_UART_H */