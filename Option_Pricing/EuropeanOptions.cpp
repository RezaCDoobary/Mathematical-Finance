#include "EuropeanOptions.hpp"
#include "Analytic.hpp"
#include <cmath>

Call::Call(double strike_)
{
    strike = strike_;
}

double Call::operator()(double spot) const
{
    return fmax(spot - strike,0);
}

Pay_Off* Call::clone()
{
    return new Call(*this);
}

double Call::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm = dminus(interest_rate, volatility,expiration, strike, initial_spot);
    double dp = dplus(interest_rate, volatility,expiration, strike, initial_spot);
    return initial_spot*Normal_CDF(dp)-exp(-interest_rate*expiration)*strike*Normal_CDF(dm);
    
}

Put::Put(double strike_)
{
    strike = strike_;
}

double Put::operator()(double spot) const
{
    return fmax(strike - spot,0);
}

Pay_Off* Put::clone()
{
    return new Put(*this);
}

double Put::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm = dminus(interest_rate, volatility,expiration, strike, initial_spot);
    double dp = dplus(interest_rate, volatility,expiration, strike, initial_spot);
    return -initial_spot*Normal_CDF(-dp)+exp(-interest_rate*expiration)*strike*Normal_CDF(-dm);
    
}
