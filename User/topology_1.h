/*
    BitzOS (BOS) V0.0.0 - Copyright (C) 2016 Hexabitz
    All rights reserved

    File Name     : topology_1.h
    Description   : Array topology definition.
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __topology_1_H
#define __topology_1_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
	 

#define _N    8                    // Number of array modules

// Array modules
#define _mod1	1<<3
#define _mod2	2<<3
#define _mod3	3<<3
#define _mod4	4<<3
#define _mod5	5<<3
#define _mod6	6<<3
#define _mod7	7<<3
#define _mod8	8<<3

// Topology
static uint16_t array[_N][8] = {
{ _H08R6, _mod2|P4, 0, 0, 0, 0, 0},			// Module 1
{ _H08R6, _mod3|P4, 0, 0, _mod1|P1, 0, 0},			// Module 2
{ _H08R6, _mod4|P4, 0, 0, _mod2|P1, 0, _mod8|P5},			// Module 3
{ _H08R6, _mod5|P4, 0, 0, _mod3|P1, _mod8|P4, 0},		// Module 4
{ _H08R6, _mod6|P4, 0, 0, _mod4|P1, 0, 0},		// Module 5
{ _H08R6, _mod7|P4, 0, 0, _mod5|P1, 0, 0},			// Module 6
{ _H08R6, 0, 0, 0, _mod6|P1, 0,0},	// Module 7
{ _H07R3, 0, 0, 0, _mod4|P5, _mod3|P6,0},	// Module 8
};

// Configurations for duplex serial ports
#if ( _module == 1 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_normal	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 2 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 3 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 4 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 5 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 6 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 7 )
	#define	H08R6	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_normal	1
	#define	_P6pol_normal	1
#endif
#if ( _module == 8 )
	#define	H07R3	1
	#define	_P1pol_normal	1
	#define	_P2pol_normal	1
	#define	_P3pol_normal	1
	#define	_P4pol_reversed	1	
	#define	_P5pol_reversed	1
#endif

#ifdef __cplusplus
}
#endif
#endif /*__ topology_1_H */


/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
