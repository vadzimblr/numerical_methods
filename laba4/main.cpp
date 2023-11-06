#include <iostream>
#include <vector>
#include "LeastSquaresApproximation.h"
using namespace std;

int main() {
    const int N = 11;
    const int m = 2;
    vector<int> X = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> Y = {3, 87, 156, 210, 238, 252, 239, 211, 158, 90, -5};
    vector<double> A = calculateA(N,m,X,Y);
    double S = calculateS(N,m,X,Y,A);
    printResult(X,Y,A,S);
    return 0;
}
