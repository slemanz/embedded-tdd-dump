#ifndef INC_LOG_H_
#define INC_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "driver_uart.h"

void LogTempertature(int temp);

#ifdef __cplusplus
}
#endif

#endif /* INC_LOG_H_ */