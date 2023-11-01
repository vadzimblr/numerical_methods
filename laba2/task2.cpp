#include <iostream>
#include <iomanip>
#include "Gauss.h"
#include <vector>
using namespace std;

double getD1(const vector<double>& x);
double getD2(const vector<double>& x, const vector<double>& xKplus1);
double function1(const double& x01, const double& x02);
double function2(const double& x01, const double& x02);
double J1Dx01(const double& x01, const double& x02);
double J1Dx02(const double& x01, const double& x02);
double J2Dx01(const double& x01, const double& x02);
double J2Dx02(const double& x01, const double& x02);
void jakobianMethod1(vector<vector<double>>& matrix, const vector<double>& x);
void jakobianMethod2(vector<vector<double>>& matrix, const vector<double>& x, const double& M);

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

double getD1(const vector<double>& x) {
    double f1 = function1(x[0], x[1]);
    double f2 = function2(x[0], x[1]);
    if (abs(f1) > abs(f2))
        return abs(f1);
    else
        return abs(f2);
}

double getD2(const vector<double>& x, const vector<double>& xKplus1) {
    double max = -9999999;
    for (int i = 0; i < x.size(); i++) {
        if (abs(xKplus1[i]) < 1) {
            if (abs(xKplus1[i] - x[i]) > max)
                max = abs(xKplus1[i] - x[i]);
        } else {
            if (abs((xKplus1[i] - x[i]) / xKplus1[i]) > max)
                max = abs((xKplus1[i] - x[i]) / xKplus1[i]);
        }
    }
    return max;
}

double function1(const double& x01, const double& x02) {
    return x01 * x01 * x02 * x02 - 3 * x01 * x01 - 6 * x02 * x02 * x02 + 8;
}

double function2(const double& x01, const double& x02) {
    return x01 * x01 * x01 * x01 - 9 * x02 + 2;
}

double J1Dx01(const double& x01, const double& x02) {
    return 2 * x01 * x02 * x02 - 6 * x01;
}

double J1Dx02(const double& x01, const double& x02) {
    return 2 * x02 * x01 * x01 - 18 * x02 * x02;
}

double J2Dx01(const double& x01, const double& x02) {
    return 3 * x01 * x01 * x01;
}

double J2Dx02(const double& x01, const double& x02) {
    return -9;
}

void jakobianMethod1(vector<vector<double>>& matrix, const vector<double>& x) {
    matrix[0][0] = J1Dx01(x[0], x[1]);
    matrix[0][1] = J1Dx02(x[0], x[1]);
    matrix[1][0] = J2Dx01(x[0], x[1]);
    matrix[1][1] = J2Dx02(x[0], x[1]);
}

void jakobianMethod2(vector<vector<double>>& matrix, const vector<double>& x, const double& M) {
    matrix[0][0] = (function1(x[0] + M * x[0], x[1]) - function1(x[0], x[1])) / M * x[0];
    matrix[0][1] = (function1(x[0], x[1] + +M * x[1]) - function1(x[0], x[1])) / M * x[1];
    matrix[1][0] = (function2(x[0] + M * x[0], x[1]) - function2(x[0], x[1])) / M * x[0];
    matrix[1][1] = (function2(x[0], x[1] + +M * x[1]) - function2(x[0], x[1])) / M * x[1];
}
