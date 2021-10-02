
//Aliza Siddiqui; 09/23/2021
//This program will numerically calculate the electric field using forward Diffentiation  at 21 equally spaced points due to a posiively charged sphere
// and compare with the exact value of the electric field found by taking first rivative of the electric potential
//Input: Number of points/intervals, step size
//Output: Electric field values at each of the points

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double actualElectricField(double r, double R);
double electricPotential(double r, double R);


int main(){
    const double R = 0.8; //m, radius of the conducting sphere
    int N = 21;
    double a = 0.001; //m
    double b = 4;     //m
    double h = 0.02; //derivative step size,m

    double delx = (b-a)/(N-1); //step size to calculate the points x_i at which u are taking the derivative of Electirc potential

    int i = 0;
    for(double x= a; x<= b; x+=delx){
        double x_i = (electricPotential((x+h), R) - electricPotential(x, R))/h;
        cout << x  << " ; " << electricPotential(x, R) << " ; " << x_i << " ; "  actualElectricField(x, R) << endl;
        i++;
    }
    return 0;
}

//Calculates the electric field at a point r using first derivative of electric tential
double actualElectricField(double r, double R){
    if(r > R){ //outside
        return -(9e9 * 0.5e-9)/(pow(r,2));
    } else{ //inside
        return 0;
    }
}

//Calculates the electric potential at a point r
double electricPotential(double r, double R){
    if (r > R){ //outside
        return (4.5/r); //V
    }
    else{ //inside
        return 5.625; //V
    }
}

