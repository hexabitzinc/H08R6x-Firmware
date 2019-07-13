/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
	
/*
		MODIFIED by Hexabitz for BitzOS (BOS) V0.1.6 - Copyright (C) 2017-2019 Hexabitz
    All rights reserved
*/

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"


/* Private variables ---------------------------------------------------------*/
float sensor = 0.0f;
volatile uint8_t Octave=4;

/* Private function prototypes -----------------------------------------------*/

bool DetectedHorizontalSweep(float distance);

/* Main functions ------------------------------------------------------------*/

int main(void)
{


  /* MCU Configuration----------------------------------------------------------*/

  /* Reset all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all user peripherals */

	/* Initialize BitzOS */
	BOS_Init();

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  while (1)
  {


  }

}
/*-----------------------------------------------------------*/

/* User Task */
void UserTask(void * argument)
{
#if _module == 1
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 2
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 3
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 4
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 6
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 7
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(200, portMAX_DELAY, &sensor);
	
#endif
#if _module == 8
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif

  /* Infinite loop */
  for(;;)
  {
        #if _module == 1
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=1;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
							  Delay_ms(50);
						}
				#endif
				       
				#if _module == 2
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=2;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
							  Delay_ms(50);
						}
				#endif
				
				#if _module == 3
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=3;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
								Delay_ms(50);
						}
				#endif
				
				#if _module == 4
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=4;
							//	IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
								Delay_ms(50);
						}
				#endif
				
				#if _module == 6
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=5;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
								Delay_ms(50);
						}
				#endif
				
				#if _module == 7
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=6;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
								Delay_ms(50);
						}
				#endif
				
				#if _module == 8
						if (DetectedHorizontalSweep(sensor)) 
						{					
								mode=7;
								//IND_ON();
								WriteRemote(5, (uint32_t) &mode, 1, FMT_UINT8, 0);
								Delay_ms(50);
						}
				#endif
				
	}
}

/*-----------------------------------------------------------*/
bool DetectedHorizontalSweep(float distance)
{
		static float state;
	if (distance < 40.0f && distance > 10.f && state != 1)
	{
		state = 1;	// Detected an object
		return true;
	}
	else if (distance >= h08r6MaxRange && state == 1) {
		state = 2;	// The object cleared
	} 
	return false;	
}
/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
