
//Aliza Siddiqui; 09/15/2021
//This program will numerically calculate the integral from -1 to 1 of function f(x) wrt x
// using the Simpson's Rule
//Input: No user input
//Output: Integral of function f(x) approximated using a Parabola (Simpson's Rule) - yields least error

#include <iostream>
using namespace std;

int main(){
    double a = -1;
    double  b = 1;
    const int N = 9; //Number of terms used in sum
    double f[N] = {-24.0000,-16.9063, -11.5000, -7.5938, -5.0000, -3.5313, -3.0000, -3.2188, -4.0000 };
    double h = (b - a) / (N - 1); //width of each interval
    cout << "h: " << h << endl;
    double sum = 0;
    for(int x=0; x <= 9; x++){
        if(x == 0 || x == (N-1)){
            sum += f[x];
            cout << x << " " << sum << endl;
        }
        else if(x % 2 == 0){ //even term
            sum += 2*f[x];
            cout << x << " " << sum << endl;
        }
        else if(x % 2 != 0){ //odd term
            sum += 4*f[x];
            cout << x << " " << sum << endl;
        }
    }
    sum = (h/3)*sum;
    cout << "sum :" << sum << endl;
    return 0;
}
