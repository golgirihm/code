#ifndef TFC_PWM_SERVO_H_
#define TFC_PWM_SERVO_H_
#define MAX_ANGLE 45

void TFC_InitServos();
void TFC_SetServo(uint8_t ServoNumber, float Position);
void TFC_SetServoDutyCycle(uint8_t ServoNumber, float DutyCycle);
void TFC_SetSteeringAngle(float angle);

#endif /* TFC_PWM_SERVO_H_ */
