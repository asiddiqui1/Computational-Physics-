
//This program will calculate the voltage across a capacitor over a
//certain time interval using Euler's Rule to solve the ODE dV/dt = -V/RC
//Input: ODE you wish to solve, interval
//Output: The ODE Solution
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double fn(double V, double RC);
double eulerRule(double prev, double h, double timeConst);

int main(){
   int a = 0;  //starting time, s
   int b = 4;  // ending time, s
   double initialV = 5; //initial voltage, V
   double timeConst = 2; //time constant RC, s
   double v_tp = initialV; //voltage from previous time step
   double h = 0.1;  //step size
   double exact = initialV*(exp(0/timeConst));
   cout << a << " ; " << initialV << " ; " << exact << endl;
   for(double t=(a+h); t <= (b+h); t+=h){
      double v_t = eulerRule(v_tp, h, timeConst); //voltage at current time step
      exact = initialV*(exp(-t/timeConst)); //exact analytical solution for voltage
      cout << t << " ; " << v_t << " ; " << exact << endl;
      v_tp = v_t; //updating the previous iteration voltage
   }
   return 0;
}

//function f(x, y(x)) that is known and part of ODE
double fn(double V, double RC){
   return -V/RC;
}

//Euler's Rule
double eulerRule(double prev, double h, double timeConst){
   return prev + (h*fn(prev, timeConst));
}