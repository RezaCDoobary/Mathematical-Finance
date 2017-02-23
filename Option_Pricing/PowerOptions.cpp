#include "PowerOptions.hpp"
#include <cmath>
#include "Analytic.hpp"

Power_Call::Power_Call(double strike_, int power_): strike(strike_), power(power_){}

double Power_Call::operator()(double spot) const
{
    return fmax(pow(spot,power) - strike,0);
}

Pay_Off* Power_Call::clone()
{
    return new Power_Call(*this);
}


double Power_Call::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm = dminus(interest_rate, volatility,expiration, strike, initial_spot)+((power-1)*log(strike))/(power*volatility*sqrt(expiration));
    double dp = dm + power*volatility*sqrt(expiration);
    double first = exp((1/2)*expiration*(power-1)*(2*interest_rate+power*volatility*volatility))*pow(initial_spot,power)*Normal_CDF(dp);
    double second = exp(-interest_rate*expiration)*strike*Normal_CDF(dm);
    return (first - second);
}



Power_Put::Power_Put(double strike_, int power_): strike(strike_), power(power_){}

double Power_Put::operator()(double spot) const
{
    return fmax(strike - pow(spot,power),0);
}

Pay_Off* Power_Put::clone()
{
    return new Power_Put(*this);
}

double Power_Put::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm = dminus(interest_rate, volatility,expiration, strike, initial_spot)+((power-1)*log(strike))/(power*volatility*sqrt(expiration));
    double dp = dm + power*volatility*sqrt(expiration);
    double first = exp((1/2)*expiration*(power-1)*(2*interest_rate+power*volatility*volatility))*pow(initial_spot,power)*Normal_CDF(-dp);
    double second = exp(-interest_rate*expiration)*strike*Normal_CDF(-dm);
    return (-first + second);
}
