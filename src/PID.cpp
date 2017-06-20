#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
	Kp = _Kp;
	Ki = _Ki;
	Kd = _Kd;
	
	sum_cte  = 0;
	prev_cte = 0;
}

void PID::UpdateError(double cte) {
	
	sum_cte += cte;
	double diff_cte = cte - prev_cte;	
	prev_cte = cte;
	
	p_error = -Kp * cte;
	i_error = -Ki * sum_cte;
	d_error = -Kd * diff_cte;
	
}

double PID::TotalError() {
	const double MAX_TOTAL_ERROR = 1;
	const double MIN_TOTAL_ERROR = -1;
	double total_error = p_error + i_error + d_error;
	total_error = total_error < MIN_TOTAL_ERROR ? MIN_TOTAL_ERROR : total_error;
	total_error = total_error > MAX_TOTAL_ERROR ? MAX_TOTAL_ERROR : total_error;
	return total_error;
}

