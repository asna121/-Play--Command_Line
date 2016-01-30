# UART Console

This package demonstrates the UART Console which is implemented using the FreeRTOS+CLI extensible command line interface. 

## Feature

### UART Command Console

直接使用freeRTOS的product作為架構，之後要維護也相對容易
#### FreeRTOS+CLI
- FreeRTOS_CLI.c
- FreeRTOS_CLI.h
#### Console Sample
這裡為了配合STM32F4-Discovery做了一些修改
- Sample-CLI-commands.c
	- `help`
	- `task-stats` 
	- 等等
- UARTCommandConsole.c
	

### UART Rx DMA

為了配合Uart Console，在uart 3的接收部分採用了DMA，並利用RX complete callback function 傳送semaphore，這時一個task將被致能並把字元送入queue中