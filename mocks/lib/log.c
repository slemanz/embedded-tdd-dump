#include "log.h"


void LogTempertature(int temp)
{
    uint8_t msg[20];
    int len = snprintf((char*)msg, 20, "Temp: %d\n", temp);
    UART_Transmit(UART2, msg, len, 0);
}