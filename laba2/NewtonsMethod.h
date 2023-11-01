//
// Created by Вадзім Пазняк on 1.11.23.
//

#ifndef NUMERICAL_METHODS_NEWTONSMETHOD_H
#define NUMERICAL_METHODS_NEWTONSMETHOD_H

#include <vector>
#include "Gauss.h"
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


#endif //NUMERICAL_METHODS_NEWTONSMETHOD_H
