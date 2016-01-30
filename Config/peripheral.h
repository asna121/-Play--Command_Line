/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PERIPHERAL_H
#define __PERIPHERAL_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"


/* Exported constants --------------------------------------------------------*/ 
/* User can use this section to tailor USARTx/UARTx instance used and associated 
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE() 

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD  
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD 
#define USARTx_RX_AF                     GPIO_AF7_USART3

/* Definition for USARTx's DMA */
#define USARTx_TX_DMA_CHANNEL            DMA_CHANNEL_4
#define USARTx_TX_DMA_STREAM             DMA1_Stream3
#define USARTx_RX_DMA_CHANNEL            DMA_CHANNEL_4
#define USARTx_RX_DMA_STREAM             DMA1_Stream1

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART3_IRQn
#define USARTx_IRQHandler                USART3_IRQHandler
#define USARTx_DMA_TX_IRQn               DMA1_Stream3_IRQn
#define USARTx_DMA_RX_IRQn               DMA1_Stream1_IRQn
#define USARTx_DMA_TX_IRQHandler         DMA1_Stream3_IRQHandler
#define USARTx_DMA_RX_IRQHandler         DMA1_Stream1_IRQHandler
#define USARTx_IRQn                      USART3_IRQn
#define USARTx_IRQHandler                USART3_IRQHandler

/* Size of Transmission buffer */
#define TXBUFFERSIZE                     (COUNTOF(aTxBuffer) - 1)
/* Size of Reception buffer */
#define RXBUFFERSIZE                     TXBUFFERSIZE

/* User can use this section to tailor I2Cx/I2Cx instance used and associated
   resources */
/* Definition for I2Cx clock resources */
 #define I2Cx_2                             I2C2
 #define I2Cx_2_CLK_ENABLE()                __HAL_RCC_I2C2_CLK_ENABLE()
 #define I2Cx_2_SDA_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOF_CLK_ENABLE()
 #define I2Cx_2_SCL_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOF_CLK_ENABLE()

 #define I2Cx_2_FORCE_RESET()               __HAL_RCC_I2C2_FORCE_RESET()
 #define I2Cx_2_RELEASE_RESET()             __HAL_RCC_I2C2_RELEASE_RESET()

/* Definition for I2Cx Pins */
 #define I2Cx_2_SCL_PIN                    GPIO_PIN_1
 #define I2Cx_2_SCL_GPIO_PORT              GPIOF
 #define I2Cx_2_SCL_AF                     GPIO_AF4_I2C2
 #define I2Cx_2_SDA_PIN                    GPIO_PIN_0
 #define I2Cx_2_SDA_GPIO_PORT              GPIOF
 #define I2Cx_2_SDA_AF                     GPIO_AF4_I2C2

/* Definition for I2Cx's NVIC */
 #define I2Cx_2_EV_IRQn                    I2C2_EV_IRQn
 #define I2Cx_2_EV_IRQHandler              I2C2_EV_IRQHandler
 #define I2Cx_2_ER_IRQn                    I2C2_ER_IRQn
 #define I2Cx_2_ER_IRQHandler              I2C2_ER_IRQHandler
 
/* Definition for I2Cx's Interrupt Priority */
 #define I2Cx_2_EV_Priority										11
 #define I2Cx_2_ER_Priority										10

/* Definition for I2Cx's ADDRESS */

#define I2C_2_ADDRESS        0xDA
 
 /*Exported variable -------------------------------------------------------  */

extern I2C_HandleTypeDef I2CxHandle_2;
extern UART_HandleTypeDef UartHandle;
extern __IO ITStatus UartTxReady;
extern __IO ITStatus UartRxReady;

extern uint8_t priI2Cx_2_NewCommand;
/* Exported functions ------------------------------------------------------- */

extern void Init_Peripheral(void);


#endif /* __PERIPHERAL_H */
