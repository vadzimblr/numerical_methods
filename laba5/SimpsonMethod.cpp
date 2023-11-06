//
// Created by vadim on 06.11.2023.
//

#include "SimpsonMethod.h"
double calculateSimpsonIntegral(const double& a, const double& b, const int& N, double function(const double&)){
    double oddAmount = 0;
    double evenAmount = 0;
    double h = (b-a)/(2*N);
    double I = function(a)+ function(b);
    double xi = a;
    for(int i = 1; i<N*2; i++){
        xi+=h;
        if(i%2==0){
            evenAmount +=function(xi);
        }
        else{
            oddAmount += function(xi);
        }
    }
    evenAmount *=2;
    oddAmount *=4;
    I+= (evenAmount+oddAmount);
    I*=(h/3);
    return I;
}