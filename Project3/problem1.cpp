
//Aliza Siddiqui; 10/1/2021
//This program will integrate a given function fn (in this case e^-x)
//using Trapezoidal Rule and then Simpson's Rule and compare.
//Input: fn function you wish to integrate numerically and interval
//Output: Solutions of the integral using Simpson's and Trapezoidal Rules
#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;

float trapezoid(int numpoints, float xmin, float xmax);
float simpson(int numpoints, float xmin, float xmax);
float fn(float x);

int main(){
   ofstream outfile;
   outfile.open("integTS.txt");
   float a = 0;
   float b = 1;
   int  N = 3;
   float exact = 0.632120558829;
   while(N <500000){ //interval of N is [3, 500000)
      float trap = trapezoid(N, a, b); //Trapezoidal Rule
      float simp = simpson(N, a, b);  //Simpson's Rule
      float relErrorT = abs((trap-exact)/exact); //Relative error of Trapezoidal Rule
      float relErrorS = abs((simp-exact)/exact);
      outfile << N << "  ; " << relErrorT << "  ;  " << relErrorS << endl;

      N = (N*2)+1;
   }

   return 0;

}


float trapezoid(int numpoints, float xmin, float xmax){ //Trapezoid Rule
//input: xmin, xmax = interval endpoints
//       numpoints = tot. number of points used
  int i;
  float xi, step, area = 0.;

  step = (xmax-xmin)/(numpoints-1);
  for( i=1; i<numpoints-1; i++){
     xi=xmin+i*step;
     area += fn(xi);
  } //for i
  area += ( fn(xmin) + fn(xmax) )*0.5;  //end points
  area *= step;
  return (area);
}

float simpson(int numpoints, float xmin, float xmax){
  //input: xmin, xmax = interval endpoints
  //           numpoints = tot. number of points used

  int i;
  float xi, step, area=0.;

  step = (xmax-xmin)/(numpoints-1);
  for(i=1;i<numpoints-1; i+=2){
     xi=xmin+i*step;
     area += 4*fn(xi);         //odd
  } //for i
  for(i=2; i<numpoints-2; i+=2){
     xi=xmin+i*step;
     area += 2*fn(xi);         //even
  } //for i

  area += ( fn(xmin) + fn(xmax) ); //end points
  area *= step/3;
  return (area);

}

//Function fn that you are integrating numerically
float fn(float x){
   return exp(-x);
}
