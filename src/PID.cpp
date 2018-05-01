#include "PID.h"
#include <limits>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
    i_error = std::numeric_limits<double>::max ( );
    d_error = std::numeric_limits<double>::max ( );
    p_error = std::numeric_limits<double>::max ( );
    is_init = false;
}

void PID::UpdateError(double cte_in) {
    
    if (false ==  is_init )
    {
        p_error = cte_in;
        i_error = 0.0;
        is_init = true;
    }
   
    d_error = cte_in - p_error;
    i_error += cte_in;
    p_error = cte_in;
        
}

double PID::TotalError() {
     return -Kp * p_error - Kd * d_error - Ki * i_error;
}


