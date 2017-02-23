/*
 Selection of useful formulae for the analytic form of the option prices
 */

#ifndef Analytic_hpp
#define Analytic_hpp

#include <stdio.h>
#include "Random.hpp"
//Normal cumulative distribution function
double Normal_CDF(const double x);

//dminus is used in the analytic form of options
double dminus(double interest_rate, double volatility, double expiration, double strike, double spot_initial);

//dplus is used in the analytic form of options
double dplus(double interest_rate, double volatility, double expiration, double strike, double spot_initial);
#endif /* Analytic_hpp */
