//
// Created by Вадзім Пазняк on 31.10.23.
//

#ifndef NUMERICAL_METHODS_GAUSS_H
#define NUMERICAL_METHODS_GAUSS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
void gauss(vector<vector<double>>& matrix, vector<double>& X);
void swapLines(int line1, int line2, vector<vector<double>>& a);
double calculateRelativeError(vector<double>& X, vector<double>& newX, vector<vector<double>>& copyMatrix, vector<double>& B, vector<double>& newB);
vector<double> getAnswer(const vector<vector<double>>& matrix);
void printAnswer(const vector<double>& X);

#endif //NUMERICAL_METHODS_GAUSS_H
