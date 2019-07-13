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
	//BOS.trace = TRACE_NONE;
	AddBOSvar(FMT_UINT8, (uint32_t) &Octave);

#if _module == 1
	// Set units to mm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
	AddPortButton(MOMENTARY_NO, P5);
	SetButtonEvents(P5, 1, 0, 0, 0, 0, 0, 0, 0, 0);
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
#if _module == 5
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
#endif	
#if _module == 6
	// Set units to cm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(200, portMAX_DELAY, &sensor);
	
#endif
#if _module == 7
	// Set units to mm
	SetRangeUnit(UNIT_MEASUREMENT_MM);
	// Stream to memory
	Stream_ToF_Memory(50, portMAX_DELAY, &sensor);
	
	AddPortButton(MOMENTARY_NO, P6);
	SetButtonEvents(P6,1,0,0,0,0,0,0,0,0);
#endif

  /* Infinite loop */
  for(;;)
  {
        #if _module == 1 //note C
						if (DetectedHorizontalSweep(sensor)) 
						{					
									//freq
									messageParams[0] = 0;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;
									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				       
				#if _module == 2 //note D
						if (DetectedHorizontalSweep(sensor)) 
						{					
									//freq
									messageParams[0] = 2;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				
				#if _module == 3//note E
						if (DetectedHorizontalSweep(sensor)) 
						{					
										//freq
									messageParams[0] = 4;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				
				#if _module == 4 //note F
						if (DetectedHorizontalSweep(sensor)) 
						{					
									//freq
									messageParams[0] = 5;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				
				#if _module == 5 // note G
						if (DetectedHorizontalSweep(sensor)) 
						{					
									//freq
									messageParams[0] = 7;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				
				#if _module == 6 // Tone A
						if (DetectedHorizontalSweep(sensor)) 
						{					
									//freq
									messageParams[0] = 9;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
						}
				#endif
				
				#if _module == 7 // note B
						if (DetectedHorizontalSweep(sensor)) 
						{				
									//freq
									messageParams[0] = 11;
									messageParams[1] = Octave;

									// durationInSeconds * 16

									messageParams[2] = 4;

									SendMessageToModule(8, 802,3);
									IND_blink(100);
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
