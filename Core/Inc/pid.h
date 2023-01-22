/*
 * pid.h
 *
 *  Created on: Jan 22, 2023
 *      Author: HP GAMING
 */

#ifndef INC_PID_H_
#define INC_PID_H_

short calculatePID(short setpoint, float actual_value, float kp, float ki, float kd, short maxval, short minval,float errornow, float errorbfr, float max_err, float min_err, float dt);

#endif /* INC_PID_H_ */
