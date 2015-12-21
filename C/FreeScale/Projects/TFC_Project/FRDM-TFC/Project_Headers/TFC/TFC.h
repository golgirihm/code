/*
 * TFC.h
 *
 *  Created on: Apr 13, 2012
 *      Author: emh203
 *      Modified by: Search and Destroy
 *      
 */

#ifndef TFC_H_
#define TFC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "Derivative.h"
#include "TFC\TFC_Config.h"
#include "TFC\TFC_Types.h"
#include "TFC\TFC_arm_cm0.h"
#include "TFC\TFC_ARM_SysTick.h"
#include "TFC\TFC_BoardSupport.h"
#include "TFC\TFC_CrystalClock.h"
#include "TFC\TFC_Servo.h"
#include "TFC\TFC_Motor.h"
#include "TFC\TFC_ADC.h"
#include "TFC\TFC_LineScanCamera.h"
#include "TFC\TFC_Queue.h"
#include "TFC\TFC_UART.h"
#include "TFC\TFC_Terminal.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

void TFC_Task();
void TFC_Init();


// general math
///////////////////////////////
#define RTD(angle) (angle * 180.0 / 3.141592653589)
#define DTR(angle) (angle * 3.141592653589 / 180.0)
///////////////////////////////
// general math


// for main
///////////////////////////////
enum state_t {BUFFER_NOT_FILLED, STEADY};
///////////////////////////////
// for main

// for servos
///////////////////////////////
#define MIN_SERVO_UPDATE_TIME 20.0
///////////////////////////////
// for servos

// for LineScan Camera
///////////////////////////////
// set the exposure range here
#define MIN_EXP 3000
#define MAX_EXP 5000

// set the amount of pixels to ignore on each side of the 128 pixel array here
#define TRIM_PIXELS_EACH_SIDE 16

// for angle functions
#define CAMERA_HORIZONTAL_DISTANCE 30 //this is measured in cm
#define INDEX_DISTANCE 1 //this is measured in cm

// set the symbols for the various points of interest
#define BLACK_PIXEL ((uint8_t) '1')
#define WHITE_PIXEL ((uint8_t) ' ')
#define CENTER_MARK ((uint8_t) 'C')
#define CURRENT_POSITION_MARK ((uint8_t) 'X')

// global variables
extern const int EXP_RANGE;
extern const uint8_t NUM_PIXELS;
extern const uint8_t HALF_WIDTH;
extern const float CAMERA_AIM_POINT_FLOAT;
extern const float TransferFunction[];
///////////////////////////////
// for LineScan Camera



#endif /* TFC_H_ */
