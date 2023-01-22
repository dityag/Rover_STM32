/*
 * pid.c
 *
 *  Created on: Jan 22, 2023
 *      Author: HP GAMING
 */

#include "pid.h"

short calculatePID(short setpoint, float actual_value, float kp, float ki, float kd, short maxval, short minval,float errornow, float errorbfr, float max_err, float min_err, float dt){
	short output;
	static float integral;
	static float derivative;

	errornow = setpoint - actual_value;

	integral += errornow;
	derivative = (errornow - errorbfr) / dt;

	integral = integral + errornow * dt;

	if(integral > max_err){
		integral = max_err;
	}else if(integral < min_err){
		integral = min_err;
	}

	output = kp*errornow + ki*integral + kd*derivative;

	if (output > maxval){
		output = maxval;
	}else if(output < minval){
		output = minval;
	}

	errorbfr = errornow;
	return output;
}
