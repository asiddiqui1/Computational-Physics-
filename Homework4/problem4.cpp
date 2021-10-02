
//This program will calculate the first and second derivative both analytically
//and numerically of a function fn (sin(x)in this case) and compare results
//Input: The function fn, its first and second derivative
//Output: First and Second derivative using CD
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double fn(double x); //Function
double dfn(double x); //First derivative of function
double d2fn(double x); //Second derivative of function
double centralDiff(double x, double h); //First derivative of function using Central Difference
double centralDiffSecond(double x, double h); //Second derivative of function using Central Difference

int main(){
  const double pi = 3.14159265;
  double a = pi; //starting interval point, pi
  double b = 8*pi; //ending interval point, 8pi
  double h = pi/9; //step size for CD, pi/9
  double N = 57; //number of points
  double stepSize = (b -a)/( N-1); //step size for INTERVAL [pi, 8pi]

  int i = 1;
  double x = a;
  while(x <= b){
    double x_deg = x*(180/pi);
    double firstDer = dfn(x);
    double secondDer = d2fn(x);
    double firstDerNum = centralDiff(x, h);
    double secondDerNum = centralDiffSecond(x, h);
    cout << i << " ; " << x << " ; " << x_deg << " ; " << firstDer << " ; " << secondDer << " ; " << firstDerNum << " ; " << secondDerNum << endl;
    x += stepSize;
    i++;
  }
  return 0;
}

//Function
double fn(double x){
  return sin(x);
}

//First Derivative of Function
double dfn(double x){
  return cos(x);
}

//Second Derivative of Function
double d2fn(double x){
  return -sin(x);
}

//First Derivative of Function using CD
double centralDiff(double x,double h){
  return (fn(x + (h/2)) - fn(x - (h/2)))/h;
}

//Second Derivative of Function using CD
double centralDiffSecond(double x, double  h){

  return (dfn(x+(h/2)) - dfn(x -(h/2)))/h;

}