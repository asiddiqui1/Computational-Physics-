
//Aliza Siddiqui; 09/10/2021
//This program will calculate the values of three functions with the same input value
//Input: x value
//Output: f(x) = x/2, f(x) - -x/2, f(x) = 0.5xsin(x)
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;

//declaring each function
double functionOne(double x);
double functionTwo(double x);
double functionThree(double x);

ofstream outfile;

int main(){
    outfile.open("FunctionResults.txt");
    const double pi = 3.141592653589793;  //pi
    outfile << "PI: " << pi << "\n" << endl;
    int m = 20; //The number to divide the interval (-6pi to 6pi) by
    outfile << "m = " << m << "\n" << endl;
    double increment = (2*6*pi)/ m; //the step size for the increments of the interval
    outfile << "Increment: " << increment << "\n" << endl;

    //Printing out columns
    outfile << "|       x       |        y = x/2      |      y = -x/2       |       y = 0.5xsin(x)    " << endl;
    outfile << "|               |                     |                     |                         " << endl;
    int x = 1; //keeps track of the interval
    for(double i=-6*pi; i <= 6*pi; i+=increment){ //from -6pi to 6pi
        double y1 = functionOne(i);
        double y2 = functionTwo(i);
        double  y3 = functionThree(i);
        if(i > 0){
           outfile << "|     " << i << "   |       " << y1 << "       |         " << y2 << "    |            " << y3 << endl;
           outfile << "|               |                     |                     |                         " << endl;
        }
        else{
            outfile << "|    " << i << "   |    " << y1 << "         |         " << y2 << "     |       " << y3 <<  endl;
            outfile << "|               |                     |                     |                         " << endl;

        }
        x++;
    }

    outfile << endl;
    outfile << endl;

    //changing interval divider from 20 to 40 now
    m = 40;
    outfile << "m = " << m << "\n" << endl;
    increment = (2*6*pi)/m;
    outfile << "Increment: " << increment << "\n" << endl;

    outfile << "|       x       |        y = x/2      |      y = -x/2       |       y = 0.5xsin(x)    " << endl;
    outfile << "|               |                     |                     |                         " << endl;

    int z = 1;
    for(double i=-6*pi; i <= 6*pi; i+=increment){
        double y1 = functionOne(i);
        double y2 = functionTwo(i);
        double  y3 = functionThree(i);
        if(i > 0){
           outfile << "|     " << i << "   |       " << y1 << "       |         " << y2 << "    |            " << y3 << endl;
           outfile << "|               |                     |                     |                         " << endl;
        }
        else{
            outfile << "|    " << i << "   |    " << y1 << "         |         " << y2 << "     |       " << y3 <<  endl;
            outfile << "|               |                     |                     |                         " << endl;

        }
        z++;
    }
    outfile << endl;

    return 0;
}

//y = x/2
double functionOne(double x){
    return x/2;
}

//y = -x/2
double functionTwo(double x){
    return -x/2;

}

//y = 0.5xsin(x)
double functionThree(double x){
    return 0.5*x*sin(x);
}
