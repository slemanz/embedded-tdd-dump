#ifndef INC_DRIVER_SPI_H
#define INC_DRIVER_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

void SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pData, uint16_t Size, uint32_t Timeout);

#ifdef __cplusplus
}
#endif

#endif /* INC_DRIVER_SPI_H */
