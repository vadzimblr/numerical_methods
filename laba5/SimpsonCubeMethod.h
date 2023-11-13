//
// Created by vadim on 12.11.2023.
//

#ifndef NUMERICAL_METHODS_SIMPSONCUBEMETHOD_H
#define NUMERICAL_METHODS_SIMPSONCUBEMETHOD_H
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double calculateSimpsonCubeIntegral(const double& a, const double& b,const double& c, const double& d, const double& aForFucntion, const double& bForFunction,
                                    double function(const double&, const double&, const double&, const double&));


#endif //NUMERICAL_METHODS_SIMPSONCUBEMETHOD_H
