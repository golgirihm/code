#include "TFC\TFC.h"


volatile uint16_t  *LineScanImage0WorkingBuffer;
volatile uint16_t  *LineScanImage1WorkingBuffer;
volatile uint16_t  *LineScanImage0;
volatile uint16_t  *LineScanImage1;
volatile uint16_t  LineScanImage0Buffer[2][128];
volatile uint16_t  LineScanImage1Buffer[2][128];
volatile uint8_t  LineScanWorkingBuffer;

volatile uint8_t LineScanImageReady = 0;

uint8_t moving_buffer_setpoint[6];

void TFC_InitLineScanCamera()
{
	SIM_SCGC5 |=     SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTD_MASK; //Make sure the clock is enabled for PORTE;
	PORTE_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for the CLOCK Signal
	PORTD_PCR7 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for SI signal

	PORTD_PCR5 = PORT_PCR_MUX(0); //Make sure AO signal goes to an analog input
	PORTD_PCR6 = PORT_PCR_MUX(0); //Make sure AO signal goes to an analog input

	//Make sure the Clock and SI pins are outputs
	GPIOD_PDDR |= (1<<7);
	GPIOE_PDDR |= (1<<1);

	TAOS_CLK_LOW;
	TAOS_SI_LOW;

	LineScanWorkingBuffer = 0;

	LineScanImage0WorkingBuffer = &LineScanImage0Buffer[0][0];
	LineScanImage1WorkingBuffer = &LineScanImage1Buffer[0][0];

	LineScanImage0 = &LineScanImage0Buffer[1][0];
	LineScanImage1 = &LineScanImage1Buffer[1][0];
}


void TFC_SetLineScanExposureTime(uint32_t  TimeIn_uS)
{
	float t;

	//Figure out how many Pit ticks we need for for the exposure time
	t = (TimeIn_uS /1000000.0) * (float)(PERIPHERAL_BUS_CLOCK);
	PIT_LDVAL0 = (uint32_t)t;

}

float TFC_LineScanImageToDigital(uint8_t Digital_Signal[])
{
	static int i;
	static uint8_t WhiteThresh;
	static uint8_t Edge_Left, Edge_Right;

	//	Edge_Left = 0;
	//	Edge_Right = NUM_PIXELS - 1;

	WhiteThresh = 80*(TFC_ReadPot(1) + 1)/2.0;

	// transferring of LineScanImage data to static data
	for(i = 0; i < NUM_PIXELS; i++)
	{
		Digital_Signal[i] = (uint8_t) (LineScanImage0[i+TRIM_PIXELS_EACH_SIDE]/50);
	}

	// convert array to 0's and 1's
	for(i = 0; i < NUM_PIXELS; i++)
	{
		// METHOD 1: black/white thresholding
		// (this function requires calibration)
		if(Digital_Signal[i] < WhiteThresh)
			Digital_Signal[i] = BLACK_PIXEL;
		else
			Digital_Signal[i] = WHITE_PIXEL;
	}

	// find left edge
	for(i=NUM_PIXELS/2; i >= 0; i--)
	{
		if(Digital_Signal[i] == BLACK_PIXEL)
		{
			Edge_Left = i;
			break;
		}
	}

	// find right edge
	for(i=NUM_PIXELS/2; i < NUM_PIXELS; i++)
	{
		if(Digital_Signal[i] == BLACK_PIXEL)
		{
			Edge_Right = i;
			break;
		}
	}

	return ((float)(Edge_Left+Edge_Right)) / 2.0f;
}

float TFC_TransferFunction(uint8_t input[], const float transfer_array[])
{
	static uint8_t i = 0;
	static float result;

	result = 0;
	for(i = 0; i < NUM_PIXELS; i++)
		result += (float) input[i] * transfer_array[i];

	return result;
}

void TFC_MovingAverage(uint8_t x, uint8_t y[], uint8_t M)
{
	static uint8_t i;

	for(i = (M-1); i > 0; --i)
		y[i] = y[i - 1];

	y[0] = x;

	for(i = 1; i < M; ++i)
		y[0] += y[i];

	y[0] /= M;

}

float TFC_GetAngleToTrackCenter(float center)
{
	float difference_distance = (center - CAMERA_AIM_POINT_FLOAT)*INDEX_DISTANCE;

	//2*(1.0f - (track_center_index / CAMERA_AIM_POINT_FLOAT))

	return RTD( atan2(difference_distance, CAMERA_HORIZONTAL_DISTANCE) );
}

void TFC_PrintTrackString(uint8* TrackString)
{
	TERMINAL_PRINTF("%s\r\n", TrackString);
}









