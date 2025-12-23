#include "driver_spi.h"
#include "driver_gpio.h"

#include "CppUTestExt/MockSupport_c.h"

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t pin, uint8_t state)
{
    mock_c()->actualCall("GPIO_WritePin")
        ->withConstPointerParameters("GPIO_RegDef_t", pGPIOx)
        ->withUnsignedIntParameters("GPIO_Pin", pin)
        ->withUnsignedIntParameters("PinState", state);
}

void SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    (void)pSPIx;
    (void)pData;
    (void)Size;
    (void)Timeout;
}

void UART_Transmit(UART_RegDef_t *pUARTx, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    (void)pUARTx;
    (void)pData;
    (void)Size;
    (void)Timeout;
}