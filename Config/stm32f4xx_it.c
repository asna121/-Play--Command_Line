/**
  ******************************************************************************
  * @file    FreeRTOS/FreeRTOS_ThreadCreation/Src/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    14-August-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "stm32f4xx_it.h"
#include "peripheral.h"
//#include "main.h"
//#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

extern xSemaphoreHandle uart_dma_irq;


/* Private function prototypes -----------------------------------------------*/

extern void xPortSysTickHandler( void );
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
   */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

void SysTick_Handler(void)
{
  //osSystickHandler();
	xPortSysTickHandler();
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles DMA RX interrupt request.
  * @param  None
  * @retval None   
  */
void USARTx_DMA_RX_IRQHandler(void)
{

	HAL_DMA_IRQHandler(UartHandle.hdmarx);


}

/**
  * @brief  This function handles DMA TX interrupt request.
  * @param  None
  * @retval None  
  */
void USARTx_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(UartHandle.hdmatx);
}

/**
  * @brief  This function handles USARTx interrupt request.
  * @param  None
  * @retval None
  */
void USARTx_IRQHandler(void)
{

	
	HAL_UART_IRQHandler(&UartHandle);
	

}




/**
  * @brief  This function handles I2C event interrupt request.  
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission     
  */
// void I2Cx_1_EV_IRQHandler(void)
// {
	// if((__HAL_I2C_GET_FLAG(&I2CxHandle_1, I2C_FLAG_MSL) == SET) && (__HAL_I2C_GET_FLAG(&I2CxHandle_1, I2C_FLAG_TRA) == SET))
		// I2CxHandle_1.State = HAL_I2C_STATE_BUSY_TX;
	
	// if((__HAL_I2C_GET_FLAG(&I2CxHandle_1, I2C_FLAG_MSL) == SET) && (__HAL_I2C_GET_FLAG(&I2CxHandle_1, I2C_FLAG_TRA) == RESET))
		// I2CxHandle_1.State = HAL_I2C_STATE_BUSY_RX;
		
	// HAL_I2C_EV_IRQHandler(& I2CxHandle_1);
// }

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
// void I2Cx_1_ER_IRQHandler(void)
// {
	// HAL_I2C_ER_IRQHandler(& I2CxHandle_1);
// }

/**
  * @brief  This function handles I2C event interrupt request.  
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission     
  */
void I2Cx_2_EV_IRQHandler(void)
{	
	if((__HAL_I2C_GET_FLAG(&I2CxHandle_2, I2C_FLAG_MSL) == SET) && (__HAL_I2C_GET_FLAG(&I2CxHandle_2, I2C_FLAG_TRA) == SET))
		I2CxHandle_2.State = HAL_I2C_STATE_BUSY_TX;
	
	if((__HAL_I2C_GET_FLAG(&I2CxHandle_2, I2C_FLAG_MSL) == SET) && (__HAL_I2C_GET_FLAG(&I2CxHandle_2, I2C_FLAG_TRA) == RESET))
		I2CxHandle_2.State = HAL_I2C_STATE_BUSY_RX;
		
	HAL_I2C_EV_IRQHandler(& I2CxHandle_2);
}

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
void I2Cx_2_ER_IRQHandler(void)
{
	HAL_I2C_ER_IRQHandler(& I2CxHandle_2);
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
