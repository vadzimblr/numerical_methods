//
// Created by Вадзім Пазняк on 1.11.23.
//

#include "NewtonsMethod.h"
double getD1(const vector<double>& x) {
    double f1 = function1(x[0], x[1]);
    double f2 = function2(x[0], x[1]);
    return (abs(f1)> abs(f2)? abs(f1): abs(f2));
}

double getD2(const vector<double>& x, const vector<double>& xKplus1) {
    double max = abs(xKplus1[0] - x[0]);
    for (int i = 1; i < x.size(); i++) {
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
    matrix[0][1] = (function1(x[0], x[1] + M * x[1]) - function1(x[0], x[1])) / M * x[1];
    matrix[1][0] = (function2(x[0] + M * x[0], x[1]) - function2(x[0], x[1])) / M * x[0];
    matrix[1][1] = (function2(x[0], x[1] + M * x[1]) - function2(x[0], x[1])) / M * x[1];
}