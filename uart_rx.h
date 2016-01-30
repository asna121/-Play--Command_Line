#include "stm32f4xx_hal.h"

extern uint8_t priI2C_NewCommand_2;

void uartRX_task(void);

/*for INMS Interface board*/

/**
On board status and INMS status
**/


uint16_t uart_messages_waiting(void);
char uart_getc(void);

/* private variable define*/
 
#define  priI2C_NewCommand_2 priI2Cx_2_NewCommand
