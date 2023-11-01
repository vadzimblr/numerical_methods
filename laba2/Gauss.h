//
// Created by Вадзім Пазняк on 1.11.23.
//

#ifndef NUMERICAL_METHODS_GAUSS_H
#define NUMERICAL_METHODS_GAUSS_H


#pragma once
#include <vector>
using namespace std;
void gauss(vector<vector<double>>& matrix, int N, int M);
void swapLines(int line1, int line2, vector<vector<double>>& a);
void getAnswerGauss(vector<vector<double>>& matrix, int N, int M, vector<double>& B);



#endif //NUMERICAL_METHODS_GAUSS_H
