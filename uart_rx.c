/**
    ***********************************************************************
    * @file     module/INMS_IF_board
    * @author   TIKI
    * @version  V0.1
    * @date     26-January-2016
    * @brief    
    ***********************************************************************
    * 
    *
    *
    *
    *
**/

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "peripheral.h"
#include "common.h"

#include "uart_rx.h"



/* Private typedef -----------------------------------------------------------*/

/* This structure is based on Gomspace Protocol*/
typedef struct{
	
uint8_t priCommand;
uint8_t priErrorcode;
uint8_t *priRequestPtr ;
uint8_t *priReplyPtr ;
uint8_t priSizeofReply;
	
} priI2C_WriteActionTypeDef;

/* Private define ------------------------------------------------------------*/
/* Buffer size of priTransferDataBuffer*/
#define TRANSFERBUFFERSIZE 50

/* Private variables ---------------------------------------------------------*/
/* FreeRTOS */
xTaskHandle I2CThreadHandle_2;

/* UART handler declaration */
extern UART_HandleTypeDef UartHandle;
extern xQueueHandle usart_rxqueue;
extern __IO ITStatus UartTxReady;
extern __IO ITStatus UartRxReady;

/*I2C communication declaration*/
priI2C_WriteActionTypeDef I2C_transfer_slave_2;

/************************** register in module**************************/
//static ifb_current_temperature ifb_test;


/************variable in environment*************************/
//static uint16_t estimated_x_angular_rate;
//static uint16_t estimated_y_angular_rate;
//static uint16_t estimated_z_angular_rate;


/* Private function prototypes -----------------------------------------------*/
//static void I2C_2_Slave_Mode(void *argument);
//static void Initial_Register(void);
//static void Update_Register(void *argument);
//static void Flush_Buffer(uint8_t* pBuffer, uint16_t BufferLength);

static void vTaskUARTRx(void *argument);

extern xSemaphoreHandle uart_lock;
extern xSemaphoreHandle uart_dma_irq;

void uartRX_task(void)
{
    
    portBASE_TYPE xStatus;
	
		xStatus = xTaskCreate(vTaskUARTRx,"Uart Receive Task", configMINIMAL_STACK_SIZE, NULL, 1,NULL);
}


/**
  * @brief  Demo
  * @param  argument: No used
  * @retval None
  */
static void vTaskUARTRx(void *argument)
{
	uint8_t pcChar = 'A';
	/* for period */
    portTickType xLastWakeTime;
    
	xLastWakeTime = xTaskGetTickCount();
	
	
	prvNewPrintString("Hello",5);
    
    for(;;)
    {	
		HAL_UART_Receive_DMA(&UartHandle,&pcChar, 1);
		xSemaphoreTake(uart_dma_irq, portMAX_DELAY);
		
        //echo
        //prvNewPrintString(&pcChar,1);
		//prvNewPrintString("\n>>: ",4);
		
		xQueueSendToBack(usart_rxqueue,&pcChar,0);
	}

}


char uart_getc(void) {
    char buf;
    xQueueReceive(usart_rxqueue, &buf, portMAX_DELAY);
    return buf;
}

uint16_t uart_messages_waiting(void) {
    return uxQueueMessagesWaiting(usart_rxqueue);
}
