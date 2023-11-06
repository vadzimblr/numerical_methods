//
// Created by vadim on 06.11.2023.
//

#ifndef NUMERICAL_METHODS_LEASTSQUARESAPPROXIMATION_H
#define NUMERICAL_METHODS_LEASTSQUARESAPPROXIMATION_H
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Gauss.h"
using namespace std;
vector<double> calculateA(const int& N, const int& m, const vector<int>& X, const vector<int>& Y);
double calculateS(const int& N, const int& m, const vector<int>& X, const vector<int>& Y, const vector<double>& A);
void printResult(const vector<int>& X, const vector<int>& Y,const vector<double>& A, const double& S);

#endif //NUMERICAL_METHODS_LEASTSQUARESAPPROXIMATION_H
