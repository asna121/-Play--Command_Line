#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "common.h"
#include "peripheral.h"

/* UART Mutex Semaphore*/
xSemaphoreHandle uart_lock = NULL;

/* Private function prototypes -----------------------------------------------*/
void prvNewPrintString (const uint8_t *pcString, const uint8_t size);


void Init_common(void)
{
	/*Mutex */
	uart_lock = xSemaphoreCreateMutex();
}



void prvNewPrintString (const uint8_t *pcString, const uint8_t size)
{
    xSemaphoreTake(uart_lock, portMAX_DELAY);
	
		//HAL_UART_Transmit_DMA(&UartHandle, (uint8_t *)pcString, size);
    if(HAL_UART_Transmit_DMA(&UartHandle, (uint8_t *)pcString, size) == HAL_OK)
	{
		/*##-3- Wait for the end of the transfer ###################################*/   
		while (UartTxReady != SET)
			vTaskDelay(1);
			/* Reset transmission flag */
		UartTxReady = RESET;
	}
	
    xSemaphoreGive(uart_lock);
}

void Error_Handler(void)
{
  /* Turn LED4 on */
 // BSP_LED_On(LED4);
  while(1)
		prvNewPrintString(" #@Error@# ",12);
}
