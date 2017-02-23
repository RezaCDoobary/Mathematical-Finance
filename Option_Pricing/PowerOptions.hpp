/*
 
 Power Call and Put option classes.
 
 In addition to the European Call and Puts found in EuropeanOptions.hpp, a power_ is included.
 
 */

#ifndef PowerOptions_hpp
#define PowerOptions_hpp
#include <stdio.h>
#include "Option_Pay_Off.hpp"

class Power_Call : public Pay_Off
{
private:
    double strike;
    int power;
public:
    Power_Call(double strike_, int power_);
    virtual double operator()(double spot) const;
    virtual ~Power_Call(){};
    virtual Pay_Off* clone();
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);

};

class Power_Put : public Pay_Off
{
private:
    double strike;
    int power;
public:
    Power_Put(double strike_, int power_);
    virtual double operator()(double spot) const;
    virtual ~Power_Put(){};
    virtual Pay_Off* clone();
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);

};


#endif /* PowerOptions_hpp */
