/*
 
 Digital Call and Put option classes.
 
 In addition to the European Call and Puts found in EuropeanOptions.hpp, a lower and upper bound for the option expiration is included.
 
 */

#ifndef DigitalOptions_hpp
#define DigitalOptions_hpp
#include <stdio.h>
#include "Option_Pay_Off.hpp"

class Digital_Call : public Pay_Off
{
private:
    double lower;
    double upper;
public:
    Digital_Call(double lower_, double upper_);
    virtual double operator()(double spot) const;
    virtual ~Digital_Call(){};
    virtual Pay_Off* clone();
    
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);
};

class Digital_Put : public Pay_Off
{
private:
    double lower;
    double upper;
public:
    Digital_Put(double lower_, double upper_);
    virtual double operator()(double spot) const;
    virtual ~Digital_Put(){};
    virtual Pay_Off* clone();
    
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot);
};


#endif /* DigitalOptions_hpp */
