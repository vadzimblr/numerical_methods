//
// Created by vadim on 12.11.2023.
//

#include "SimpsonCubeMethod.h"
double calculateSimpsonCubeIntegral(const double& a, const double& b,const double& c, const double& d, const double& aForFucntion, const double& bForFunction,
                                    double function(const double&, const double&, const double&, const double&)){

    int m = 2;
    int n = 2;
    double hx = (b-a)/(2*n);
    double hy = (d-c)/(2*m);
    double sum = 0.0;
    double I = 0.0;
    double xi = a;
    double yi = c;

    vector<double> Xi;
    do{
        Xi.push_back(xi);
        xi+=hx;
    } while (xi <= b);
    vector<double> Yi;
    do{
        Yi.push_back(yi);
        yi+=hy;
    } while (yi <= d);

    for(int i = 0; i< n; i++){
        for(int j=0; j<m; j++){
            sum+=function(Xi[2*i],Yi[2*j],0.2*aForFucntion,0.1*bForFunction);
            sum+=4*function(Xi[2*i+1],Yi[2*j],0.2*aForFucntion,0.1*bForFunction);
            sum+=function(Xi[2*i+2],Yi[2*j],0.2*aForFucntion,0.1*bForFunction);
            sum+=4*function(Xi[2*i],Yi[2*j+1],0.2*aForFucntion,0.1*bForFunction);
            sum+=16*function(Xi[2*i+1],Yi[2*j+1],0.2*aForFucntion,0.1*bForFunction);
            sum+=4*function(Xi[2*i+2],Yi[2*j+1],0.2*aForFucntion,0.1*bForFunction);
            sum+=function(Xi[2*i],Yi[2*j+2],0.2*aForFucntion,0.1*bForFunction);
            sum+=4*function(Xi[2*i+1],Yi[2*j+2],0.2*aForFucntion,0.1*bForFunction);
            sum+=function(Xi[2*i+2],Yi[2*j+2],0.2*aForFucntion,0.1*bForFunction);
        }
    }
    I+=sum;
    I*=((hx*hy)/9);
    return I;
}