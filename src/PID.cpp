#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
    i_error = cte + i_error;
    d_error = cte - p_error;    // current - previous
    p_error = cte;
}

double PID::TotalError() {
    double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
    if (steer < -1) {
        steer = -1;
    }
    if (steer > 1) {
        steer = 1;
    }
    return steer;
}

