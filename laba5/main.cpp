#include <iostream>
#include "function.h"
#include <iomanip>
#include "TrapezoidalMethod.h"
#include "SimpsonMethod.h"

using namespace std;

int main() {
    const double eps1 = 1e-4;
    const double eps2 = 1e-5;
    double a = 0.6;
    double b = 1.724;

    cout <<"TrapezoidalMethod (eps = 10^-4): " << endl;
    cout << setprecision(20) << "I: " << calculateTrapezoidalIntegral(a,b,eps1,function) <<endl;
    cout <<"TrapezoidalMethod (eps = 10^-5): " << endl;
    cout << setprecision(20) << "I: " << calculateTrapezoidalIntegral(a,b,eps2,function) <<endl;
    cout << "SimpsonMethod: " << endl;
   // cout << setprecision(20) <<"I: " << calculateSimpsonIntegral(a,b,N,function) << endl;
    return 0;
}
