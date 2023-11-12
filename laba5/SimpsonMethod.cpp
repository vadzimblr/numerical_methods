// SimpsonMethod.cpp
#include "SimpsonMethod.h"

double calculateSimpsonIntegral(const double& a, const double& b, const double& eps, double function(const double&)) {
    int N = 2;
    double oddAmount = 0;
    double evenAmount = 0;
    double h = (b - a) / N;
    double I = function(a) + function(b);
    double I2;

    do {
        I2 = I;
        N *= 2;
        h = (b - a) / N;
        double xi = a + h;
        oddAmount = 0;
        evenAmount = 0;
        for (int i = 1; i < N; i++) {
            if (i % 2 == 0) {
                evenAmount += function(xi);
            } else {
                oddAmount += function(xi);
            }
            xi += h;
        }

        evenAmount *= 2;
        oddAmount *= 4;
        I += (evenAmount + oddAmount);
        I *= (h / 3);
    } while (fabs(I - I2) > eps);

    return I;
}
