#include "driver_gpio.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport_c.h"
#include "sensor.h"

TEST_GROUP(Sensor)
{
    GPIO_RegDef_t port_1;
    SPI_RegDef_t spi_1;
    uint16_t pin_1 = 1;
    Sensor sensor = {.port = &port_1, .spi = &spi_1, .pin = pin_1};
    int temperature = -100;

    void teardown()
    {
        mock_c()->checkExpectations();
        mock_c()->clear();
    }
};

TEST(Sensor, ReadSetsCs)
{
    mock_c()->expectOneCall("GPIO_WritePin")
            ->withConstPointerParameters("GPIO_RegDef_t", &port_1)
            ->withUnsignedIntParameters("GPIO_Pin", pin_1)
            ->withUnsignedIntParameters("PinState", GPIO_PIN_SET);

    mock_c()->expectOneCall("GPIO_WritePin")
            ->withConstPointerParameters("GPIO_RegDef_t", &port_1)
            ->withUnsignedIntParameters("GPIO_Pin", pin_1)
            ->withUnsignedIntParameters("PinState", GPIO_PIN_RESET);

    SensorRead(&sensor);
}