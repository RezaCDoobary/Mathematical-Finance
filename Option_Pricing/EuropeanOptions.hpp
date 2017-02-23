/*
 
 European Call and Put option classes.
 
 In addition to the Pay_Off class in Option_Pay_Off, a strike_ is included.
 
 */

#ifndef EuropeanOptions_hpp
#define EuropeanOptions_hpp
#include <stdio.h>
#include "Option_Pay_Off.hpp"

class Call : public Pay_Off
{
private:
    double strike;
public:
    //A strike for the option is called upon construction.
    Call(double strike_);
    virtual double operator()(double spot) const;
    virtual ~Call(){};
    virtual Pay_Off* clone();
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);
};
class Put : public Pay_Off
{
private:
    double strike;
public:
    Put(double strike_);
    virtual double operator()(double spot) const;
    virtual ~Put(){};
    virtual Pay_Off* clone();
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);
};

#endif /* EuropeanOptions_hpp */
