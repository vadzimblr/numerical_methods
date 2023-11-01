#include <iostream>
#include <iomanip>
#include <vector>
#include "NewtonsMethod.h"
using namespace std;



int main() {
    //system("chcp 1251");
    const double eps = 1e-9;
    double d1 = 1, d2 = 1;
    vector<double> x;
    x.push_back(-1.5);
    x.push_back(1.5);
    vector<double> xKplus1(x);
    int k = 1;
    int NIT = 100;
    int N = 2;
    int M = 3;
    double MParametr = 0.1;
    vector<vector<double>> matrix(N, vector<double>(M));
    vector<double> ans(N);

    while ((d1 > eps || d2 > eps) && k < NIT) {
        jakobianMethod1(matrix, x);
        //jakobianMethod2(matrix, x, MParametr);
        matrix[0][2] = -function1(x[0], x[1]);
        matrix[1][2] = -function2(x[0], x[1]);
        getAnswerGauss(matrix, N, M, ans);
        xKplus1[0] += ans[0];
        xKplus1[1] += ans[1];

        d1 = getD1(x);
        d2 = getD2(x, xKplus1);
        cout << "Iteration:" << k << " d1: " << d1 << " d2: " << d2 << endl;
        k++;
        x = xKplus1;
    }

    //261886462 0.01
    //261890459 0.05
    //261947396 0.1
    cout << "Solution: x = " << setprecision(25) << x[0] << ", y = " << x[1] << endl << "Number of iterations: " << k << endl;
}


