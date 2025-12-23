#include "sensor.h"

int SensorRead(Sensor *sensor)
{
    uint8_t rx_data[2];
    GPIO_WritePin(sensor->port, sensor->pin, GPIO_PIN_SET);
    SPI_Receive(sensor->spi, rx_data, 2, 0);
    GPIO_WritePin(sensor->port, sensor->pin, GPIO_PIN_RESET);
    return (int)rx_data[1];
}