/*
 
 Pay_Off class.
 
 A purely interface class of which all options are inherited from.
 
 */

#ifndef Option_Pay_Off_hpp
#define Option_Pay_Off_hpp
#include <stdio.h>

class Pay_Off
{
public:
    // Implementation of the spot price:
    virtual double operator()(double spot) const = 0;
    
    virtual ~Pay_Off(){};
    
    // clone() method for constructing copies.
    virtual Pay_Off* clone() = 0;
    
    // The analytic expression for the black scholes result.
    virtual double BlackScholes(const double& interest_rate, const double& volatility,const double& expiration, const double& initial_spot) = 0;
};

#endif /* Option_Pay_Off_hpp */
