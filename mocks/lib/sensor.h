#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "driver_gpio.h"
#include "driver_spi.h"

typedef struct{
    GPIO_RegDef_t *port;
    SPI_RegDef_t *spi;
    uint16_t pin;
}Sensor;

int SensorRead(Sensor *sensor);

#ifdef __cplusplus
}
#endif

#endif /* INC_SENSOR_H_ */