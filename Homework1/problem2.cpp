
//Aliza Siddiqui; 09/10/2021
//This program will compare two algorithms to calculate the relative velocity of an object using
// the Doppler Effect
// Now variables are of type double
//Input: source frequency, object frequency, frequency shift, speed of light
//Output: relative velocity of object
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  const double c=3.e8;   //speed of light, m/s  Now of value Double
  double fs,fo, deltaf, vrel; //fs, source frequency, Hz  Now of value Double
                             // fo, frequency detected by object, Hz Now of value Double
                             //deltaf, frequency shift, Hz Now of value Double
                             //vrel, object velocity, m/s Now of value Double

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
