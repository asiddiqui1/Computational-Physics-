
//Aliza Siddiqui; 09/22/2021
//This program will calculate the first derivative of the 4th degree legendre polynomial using three differentiation algorithms: Forward differentiation
// central differentiation, and extrapolated differentiation. It then compares the results to the exact result
//Input: step size, number of points
//Output: Relative error between numerical differentiation methods and exact derivative for every x

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;

//Declaring Functions
double legendrePolynomial(double x);
double legendrePolynomialDer(double x); //derivative of legendre polynomial
double centralDifference(double x, double h);

int main(){
    int a = -1;
    int b = 1;
    double h = 0.1; //step size
    int N = 21; //number of points


    cout << " x      P4(x)      Abs Error FD      Abs Error CD      Abs Error ED      " << endl;
    for(double x = a; x <= b ; x+= h){
        //Forward Difference

        double exact = legendrePolynomialDer(x);
        double fd = (legendrePolynomial(x + h) - legendrePolynomial(x))/h;
        double cd = centralDifference(x, h);
        double ed = (4*centralDifference(x, (h/2)) - cd)/3;
        cout  << x << " ; " << exact << " ; "  << abs(fd - exact) << " ; "  <<  abs(cd - exact) << " ; "  << abs(ed - exact) << endl;

    }


    return 0;
}

//calculates the value of the 4th degree legendre polynomial at a point x
double legendrePolynomial(double x){
    return ((3 - (30*pow(x, 2)) + (35*pow(x, 4)))/8.0);
}

//Calculates the value of the first derivative of the 4th degree legendre polynomial at a point x
double legendrePolynomialDer(double x){
    return ((-15.0/2.0)*x) + ((35.0/2.0)*pow(x,3));
}

//Uses the central differentiation formula to calculate the derivative of the legendre polynomial
double centralDifference(double x, double h){
    return (legendrePolynomial(x + (h/2)) - legendrePolynomial(x - (h/2)))/h;
}
