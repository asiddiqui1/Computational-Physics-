
//Aliza Siddiqui; 09/15/2021
//This program will numerically calculate the electric potential at Point P
// by summing all the potentials from each dx from the charged rod
// using the Simpson's Rule
//Input: No user input
//Output: Integral of function f(x) (in this case V) approximated using a Parabola (Simpson's Rule) - yields least error

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main(){
    double d = 0.1; //distance point P is at, m
    double lambda = 2e-10; //linear charge density, C/m
    double L = 0.5; //length L of the uniformly charged rod, m
    const double k = 9e9; //Coulomb's constant, Nm^2/C^2
    int N = 513; //Number of points being used in Simpson's rule
    double a = 0; //starting index of interval
    double b = L; //ending index of interval;

    //calculate h - spacing between points
    double h = (b - a)/(N - 1);

    //Calculating exact value
    double V_exact = k*lambda *log((L + sqrt(pow(L, 2) + pow(d, 2)))/ d); //Exact value of electric potential at point P, V

    double sum = 0; //Total electric potential at point P approximated by Simpson's Rule, V = Nm/C
    for(int i=0 ;i<= (N-1); i++){
         double x = a + i*h;
         double funcValue = (k*lambda)/sqrt(pow(x, 2) + pow(d, 2)); //Units V/m
         if(i == 0 || i == (N - 1)){
             sum += (h/3)*funcValue; //Units V
         }
         else if(i % 2 == 0){
             sum += ((2*h)/3)*funcValue;
         }
         else if(i % 2 != 0){
             sum += ((4*h)/3)*funcValue;
         }

    }

    cout.precision(15);
    cout<< "The final sum of the Electric potential at point P using N = 513 points is: " << sum << endl;
    cout<< "The exact value of the Electric potentil is: " << V_exact << endl;
    cout<< "Relative Error between sum and exact: " << (abs(V_exact - sum)/V_exact) << endl;
    return 0;
}
