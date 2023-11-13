//
// Created by vadim on 06.11.2023.
//

#include "function.h"
double function(const double& x){

    return pow((x+x*x*x),0.5);
}
double function(const double& x, const double& y, const double& a, const double& b){
    return exp(-a * (x + y)) / (1 + b * (x + y));
}