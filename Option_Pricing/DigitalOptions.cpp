#include "DigitalOptions.hpp"
#include "Analytic.hpp"
Digital_Call::Digital_Call(double lower_, double upper_)
{
    lower = lower_;
    upper = upper_;
}

double Digital_Call::operator()(double spot) const
{
    if(spot<=lower){return 0;}
    if(spot>=upper){return 0;}
    return 1;
}

Pay_Off* Digital_Call::clone()
{
    return new Digital_Call(*this);
}

double Digital_Call::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm_lower = dminus(interest_rate, volatility,expiration, lower, initial_spot);
    double dm_upper = dminus(interest_rate, volatility,expiration, upper, initial_spot);
    return exp(-interest_rate*expiration)*(Normal_CDF(dm_lower)-Normal_CDF(dm_upper));
}

Digital_Put::Digital_Put(double lower_, double upper_)
{
    lower = lower_;
    upper = upper_;
}

double Digital_Put::operator()(double spot) const
{
    if(spot<=lower){return 0;}
    if(spot>=upper){return 0;}
    return 1;
}

Pay_Off* Digital_Put::clone()
{
    return new Digital_Put(*this);
}

double Digital_Put::BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot)
{
    double dm_lower = dminus(interest_rate, volatility,expiration, lower, initial_spot);
    double dm_upper = dminus(interest_rate, volatility,expiration, upper, initial_spot);
    return exp(-interest_rate*expiration)*(1-Normal_CDF(dm_lower)+Normal_CDF(dm_upper));
}
