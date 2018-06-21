#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  cte_prev = 0;


}

void PID::UpdateError(double cte) {

  p_error = -Kp * cte;
  d_error = -Kd * (cte - cte_prev);
  i_error = -Ki * cte - i_error;

  cte_prev = cte;

  std::cout << "Error updated: CTE | P | I | D: " << cte;
  std::cout << " | "<< p_error<< " | "<< i_error << " | " << d_error <<endl;


}

double PID::TotalError() {

  return p_error + d_error + i_error;

}
