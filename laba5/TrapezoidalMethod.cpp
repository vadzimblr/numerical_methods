//
// Created by vadim on 06.11.2023.
//

#include "TrapezoidalMethod.h"
double calculateTrapezoidalIntegral(const double& a, const double& b, const int& N, double function(const double&)){
    double h = (b-a)/N;
    double I = function(a)+ function(b);
    double sum = 0;
    double xi = a;
    for(int i = 1; i<N; i++){
        xi+=h;
        sum+= function(xi);
    }
    sum*=2;
    I+=sum;
    I*=(h/2);
    return I;
}