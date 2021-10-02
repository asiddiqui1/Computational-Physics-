
//Aliza Siddiqui; 09/10/2021
//This program will compare two algorithms to find the relative velocity of the   object
// using the Doppler Effect
// Input: frequency of source, frequency of object, frequency shift, speed of li  ght
// Output: Relative velocity of object

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
   const float c=3.e8;
   float fs, fo, deltaf, vrel;

   fs=103.3e6;
   deltaf=9.44;

   cout << "Algorithm (i):" << endl;
   fo=fs+deltaf;
   vrel=fo*c-fs*c;
   vrel=vrel/fs;
   cout << "v=" << setprecision(15) << vrel << " m/s" << endl;

   cout << "Algorithm (ii):" << endl;
   vrel=deltaf*c/fs;
   cout << "v=" << setprecision(15) << vrel << " m/s" << endl;

   cout << "Just a check:" << endl;
   cout << "v=" << setprecision(15)
        << 9.44*(3.e8)/( (double) fs) << " m/s" << endl;

   return 0;

}
