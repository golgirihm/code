#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"

// these give variables to particular parameters of the linescan camera
const uint8_t NUM_PIXELS = 128 - 2*TRIM_PIXELS_EACH_SIDE;
const uint8_t HALF_NUM_PIXELS = (128 - 2*TRIM_PIXELS_EACH_SIDE) / 2;
const float CAMERA_AIM_POINT_FLOAT = (float) ((128.0f - 2.0f*TRIM_PIXELS_EACH_SIDE - 1.0f) / 2.0f);

// this sets the exposure range
const int EXP_RANGE = (MAX_EXP - MIN_EXP);

int main(void)
{
	
	float track_center = CAMERA_AIM_POINT_FLOAT;	// default C is X
	int exposure_usecs = MAX_EXP;					// default exposure is slow
	float delta_time;								// this adjusts error before adding it to integral error, I_error_angle
	char* DigitalImage0 = NULL;
	char test[] = "hellooooooooooo?????????";
	/********************************************************************************************************************************/
	/*													PID Loop Variables															*/
	/********************************************************************************************************************************/
	float SP_center_angle = 0.0;	// angle from car to center of track
	float CV_turn_angle = 0.0;		// angle that the car should turn
	
	float P_error_angle = 0.0;		// instantaneous error
	float I_error_angle = 0.0; 		// integral error
	float D_error_angle = 0.0; 		// derivative error
	float last_P_error_angle = 0.0;	// error from previous iteration, used for derivative error calculation
	float temp_I_error_angle = 0.0f;// this is used to help check if integral is getting too large
	
	float Kp = 1.0;					// proportional error constant
	float Ki = 0.1;					// integral error constant
	float Kd = 0.1;					// derivative error constant
	/********************************************************************************************************************************/
	
	
	TFC_Init();
	DigitalImage0 = (char*)malloc(sizeof(char) * NUM_PIXELS);
	
	// use potentiometer 0 to change the exposure time
	//exposure_usecs = MIN_EXP + EXP_RANGE*(TFC_ReadPot(0) + 1.0)/2.0;
	//TFC_SetLineScanExposureTime(exposure_usecs);
	
	while(1)
	{	   
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
		TFC_Task();

		delta_time = exposure_usecs / 1000000.0;
		if((TFC_Ticker[0] > 2*exposure_usecs / 1000) && (LineScanImageReady == 1))
		{
				// reset ticker and image ready flag
				TFC_Ticker[0] = 0;
				LineScanImageReady  = 0;
				
				// convert image from linescan camera to digital and find the center between the two black lines on the track
				track_center = TFC_LineScanImageToDigital(DigitalImage0);
				
				/********************************************************************************************************************************/
				/*												PID Control Algorithm															*/
				/********************************************************************************************************************************/

				// find setpoint angle
				SP_center_angle = TFC_GetAngleToTrackCenter(track_center);

				// calculate error between setpoint angle and current angle
				P_error_angle = SP_center_angle - 0;

				// update the integral error, but keep it within some specific range
				temp_I_error_angle = I_error_angle + P_error_angle * delta_time;
				if(abs(temp_I_error_angle) < 90) I_error_angle = temp_I_error_angle;

				// calculate the change in error between iterations
				D_error_angle = P_error_angle - last_P_error_angle;

				// control variable -- this number is the end result that will be passed into the steering function
				CV_turn_angle = (Kp * P_error_angle) + (Ki * I_error_angle) + (Kd * D_error_angle);

				/* TODO: Find out if we actually need this if() statement.
					It may be okay to simply update the PWM value multiple times before an actual pulse occurs*/
				
				// if the servo is actually ready to turn
				if(TFC_Ticker[1] >= MIN_SERVO_UPDATE_TIME)
				{
					TFC_Ticker[1] = 0;
					TFC_SetSteeringAngle(CV_turn_angle);
				}

				//TERMINAL_PRINTF("%s %s %s %s \r\n", (int) (100*P_error_angle), (int) (100*I_error_angle), (int) (100*D_error_angle), (int) (100*CV_turn_angle));

				// store the error from this iteration so that it can be used for the next iteration
				last_P_error_angle = P_error_angle;

				/********************************************************************************************************************************/

					
				// identify center point of track, and current position
				DigitalImage0[(int) track_center] = CENTER_MARK;
				DigitalImage0[(int) (CAMERA_AIM_POINT_FLOAT)] = CURRENT_POSITION_MARK;
				DigitalImage0[(int) (CAMERA_AIM_POINT_FLOAT + 0.5)] = CURRENT_POSITION_MARK;
			
				// this will print out the track
				//TFC_PrintTrackString(DigitalImage0);
				TERMINAL_PRINTF("Test string is: %s\r\n", DigitalImage0);
				
//				for(i=0;i<NUM_PIXELS;i++)
//					TERMINAL_PRINTF("%c", DigitalImage0[i]);
//				TERMINAL_PRINTF("\r\n");

		} // if(good time to process picture)
	}

	free(DigitalImage0);
	return 0;
}
