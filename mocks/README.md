# TDD Mocks

The core problem in embedded TDD is that a significant portion of the code (like
drivers, Hardware Abstraction Layers/HALs, and direct register access) is
dependent on the physical hardware. This hardware is often slow, requires
complex setup, or may not even be available during the early stages of
development.

A Mock (or Test Double) is a stand-in object or function that simulates the
behavior of a real dependency in a controlled way, allowing the code under test
to be executed on a development host rather than the target hardware.

### Mock vs. Stub vs. Fake

While the term "mock" is often used generically, unit testing distinguishes
between various "Test Doubles":

**Stub:** A minimal implementation that provides canned data to the unit under
test. It answers the question: "What data should be returned?"

- Example: A function to read an ADC returns a hard-coded value like 4095.

**Mock:** A specialized stub that also has expectations about how it is used. It
answers the question: "Was the dependency called correctly?"

- Example: A mock verifies that Init() was called, then EraseSector(), and
finally WriteData() with the correct memory address.

**Fake:** A working but simplified implementation.

- Example: A flash memory driver is replaced with a RAM-based storage for
testing purposes.

## Implementation Concept

To enable mocking, your embedded code must be designed with loose coupling using
Hardware Abstraction Layers (HALs). This creates a "seam" where the mock can be
injected.

1. **Abstract Dependencies:** Instead of calling a hardware register directly, the
application code calls an intermediate function (e.g., HAL_ADC_Read()).

2. **The Test Build:** When building for unit testing on the host PC:

- The HAL_ADC_Read.c (the real driver code) is replaced by a generated or
hand-written HAL_ADC_Mock.c file.

- The unit test links against the mock version.

3. **The Production Build:** When building for the target hardware:

- The unit test code is excluded.

- The application links against the real HAL_ADC_Read.c driver.

---

## Example

**Drivers:**

- [stm32f4xx.h](drivers/stm32f4xx.h)
- [GPIO](drivers/driver_gpio.h)
- [UART](drivers/driver_uart.h)
- [SPI](drivers/driver_spi.h)
- [Driver Mock](drivers/driver_mock.c)

**Lib:**

- [Log.h](lib/log.h)
- [Log.c](lib/log.c)
- [sensor.h](lib/sensor.h)
- [sensor.c](lib/sensor.c)

**Tests:**

- [All Tests](tests/AllTests.cpp)
- [Sensor Tests](tests/ut_sensor.cpp)