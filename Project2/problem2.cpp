//Aliza Siddiqui; 09/10/2021
//This program will calculate e^-x by making the infinite sum a finite sum
//Input: x Output: An approximation for e^-x

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
   float error;  //Error tolerance
   float xmin;
   float xmax;
   float xstep;
   float sum;   //finite sum value
   float element; //element (-x)/n
   float exact; //exact value (e^-x)
   float x; //keeps track of x value
   int n; //number of terms

   ofstream outfile;
   outfile.open("VariableValues.txt");

   error = 1e-6;                        //approximation error
   xmin = 0.; xmax = 10.0; xstep = 0.1; //min x, max x, step for x

   x = xmin;
   while(x < xmax+0.5*xstep){   //loop over values of x
      sum = 1.;                 //initialize sum (important!)
      element = 1.;             //initialize element (important!)
      exact = exp(-x);

      n = 0;
      do{
        n++;
        element *= -x/n;       //calculate new element
        sum += element;        //calculate the sum at n

      } while( (sum == 0) || (fabs(element/sum) > error));
      outfile << n << ";" << x <<  "; " << sum << "; " <<  exact << "; " << (sum - exact) << "; " <<  endl;



      x += xstep;
   }// while x

   return 0;
}
