#include "TrapezoidalMethod.h"

double calculateTrapezoidalIntegral(const double& a, const double& b, const double& eps, double function(const double&)) {
    int n = 1;
    double h = (b - a);
    double xi = a;
    double sum = 0;
    double I = function(a) + function(b);
    I *= h;
    double I2;
    do {
        n *= 2;
        I2 = I;
        h = (b - a) / n;
        xi = a;
        sum = 0;
        for (int i = 0; i < n - 1; i++) {
            xi += h;
            sum += function(xi);
        }
        I = (function(a) + function(b) + 2 * sum )* (h / 2);
    } while (fabs(I - I2) >= 3 * eps);

    return I;
}
