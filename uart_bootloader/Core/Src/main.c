/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx.h"

#define BOOTLOADER_SIZE        (0x8000U)
#define MAIN_APP_START_ADDRESS (FLASH_BASE + BOOTLOADER_SIZE)

static void jump_to_main(void){

	typedef void (*void_fun)(void);

	uint32_t* reset_vector_location = (uint32_t*)(MAIN_APP_START_ADDRESS + 4U); //Since the first vector is the Stack pointer;
	uint32_t* reset_vector = (uint32_t*)(*reset_vector_location);
	void_fun jump_fun = (void_fun)reset_vector;

	jump_fun();
}

int main(void)
{
	jump_to_main();
	//Never return


	while(1){

	}

}


