
//Aliza Siddiqui; 10/1/2021
//This program will calculate the integral of a eighth degree polynomial in
// the interval [1,2] using Gaussian Quadrature,
// Trapezoidal Rule, and Simpson's Rule

#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include "gauss.cpp"
using namespace std;

double gauss_integr(int no, double min, double max);
double trapezoid(int numpoints, double xmin, double  xmax);
double simpson(int numpoints, double xmin, double xmax);
double fn(double x);

int main(){
   ofstream outfile;
   outfile.open("integTSG_p2.txt");
   double a = 1; //starting interval point
   double b = 2; //ending interval point
   double  N = 3;
   double exact = 6.242539682539682; //exact analytical solution
   while(N <=501){
      double trap = trapezoid(N, a, b);
      double simp = simpson(N, a, b);
      double gauss = gauss_integr(N, a, b);
      double absErrorT = abs((trap-exact)); //absolute error between Trapezoidal Rule Solution and exact analytical solution
      double absErrorS = abs((simp-exact));
      double absErrorG = abs((gauss-exact));
      outfile << N << "  ; " << absErrorT << "  ;  " << absErrorS << "  ;  " << absErrorG <<  endl;

      N = N + 2;
   }

   return 0;

}

//This function will calculate the integral using Gaussian Quadrature
double gauss_integr (int no, double min, double max) {  // Gauss' rule
  int n;
  double quadra= 0.;
  double w[1000], x[1000];
  void gauss(int npts,int job,double a,double b,double x[],double w[]); // for points and weights

  gauss (no, 0, min, max, x, w);                                               // Gauss Legendre points & wts
  for (n = 0; n< no; n++) quadra += fn(x[n])*w[n];                             // Calc integral
  return (quadra);
}


double trapezoid(int numpoints, double xmin, double xmax){ //Trapezoid Rule
//input: xmin, xmax = interval endpoints
//       numpoints = tot. number of points used
  int i;
  double  xi, step, area = 0.;

  step = (xmax-xmin)/(numpoints-1);
  for( i=1; i<numpoints-1; i++){
     xi=xmin+i*step;
     area += fn(xi);
  } //for i
  area += ( fn(xmin) + fn(xmax) )*0.5;  //end points
  area *= step;
  return (area);
}
double simpson(int numpoints, double xmin, double  xmax){
  //input: xmin, xmax = interval endpoints
  int i;
  double xi, step, area=0.;

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

//Function you wish to integrate numerically
double fn(double x){
   return(( pow(x,2)) +( 0.3*pow(x,4)) - (0.2*pow(x, 6)) +( 0.1*pow(x, 8)));
}
