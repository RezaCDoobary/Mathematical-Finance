#include "Analytic.hpp"
#include <cmath>

double dminus(double interest_rate, double volatility, double expiration, double strike, double spot_initial)
{
    return 1/(volatility*sqrt(expiration))*(log(spot_initial/strike)+(interest_rate-(1/2)*volatility*volatility)*expiration);
}

double dplus(double interest_rate, double volatility, double expiration, double strike, double spot_initial)
{
    return dminus(interest_rate,volatility,expiration, strike, spot_initial) + volatility*sqrt(expiration);
}

double Normal_CDF(const double x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double s = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));
    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * s);
    } else {
        return 1.0 - Normal_CDF(-x);
    }
}
