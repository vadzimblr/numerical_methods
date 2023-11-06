#include <iostream>
#include "function.h"
#include <iomanip>
#include "TrapezoidalMethod.h"
#include "SimpsonMethod.h"

using namespace std;

int main() {
    const int N = 25;
    double a = 0.6;
    double b = 1.724;

    cout <<"TrapezoidalMethod: " << endl;
    cout << setprecision(20) << "I: " << calculateTrapezoidalIntegral(a,b,N,function) <<endl;
    cout << "SimpsonMethod: " << endl;
    cout << setprecision(20) <<"I: " << calculateSimpsonIntegral(a,b,N,function) << endl;
    return 0;
}
