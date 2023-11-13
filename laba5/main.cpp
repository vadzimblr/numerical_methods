#include <iostream>
#include "function.h"
#include <iomanip>
#include "TrapezoidalMethod.h"
#include "SimpsonMethod.h"
#include "SimpsonCubeMethod.h"
using namespace std;

int main() {
    const double eps1 = 1e-4;
    const double eps2 = 1e-5;
    double a = 0.6;
    double b = 1.724;
    cout << "TrapezoidalMethod (eps = 10^-4): " << endl;
    cout << setprecision(20) << "I: " << calculateTrapezoidalIntegral(a, b, eps1, function) << endl;
    cout << "TrapezoidalMethod (eps = 10^-5): " << endl;
    cout << setprecision(20) << "I: " << calculateTrapezoidalIntegral(a, b, eps2, function) << endl;
    cout << "SimpsonMethod (eps = 10^-4): " << endl;
    cout << setprecision(20) << "I: " << calculateSimpsonIntegral(a, b, eps1, function) << endl;
    cout << "SimpsonMethod (eps = 10^-5): " << endl;
    cout << setprecision(20) << "I: " << calculateSimpsonIntegral(a, b, eps2, function) << endl;
    double a_ = 0;
    double b_ = 2.0;
    double c_ = 0.5;
    double d_ = 1.5;

    for (int m = 1; m <= 5; m++) {
        for (int n = 1; n <= 5; n++) {
            cout << "Simson Cube Method for m= " << m << " and n= " << n << endl;
            cout << calculateSimpsonCubeIntegral(a_, b_, c_, d_, (double) m, (double) n, function);
            cout << endl;
        }
    }

    return 0;
}