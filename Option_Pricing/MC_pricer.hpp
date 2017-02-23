/*
 Monte Carlo simulation of option pricing
 */

#ifndef MC_pricer_hpp
#define MC_pricer_hpp

#include <stdio.h>
#include "Option_Pay_Off.hpp"
#include "VanillaOptions.hpp"

//Monte Carlo Pricer//
double MonteCarlo(VanillaOption theoptionpayoff, const double interest_rate, const double volatility, const double spot_initial, const int number_of_simulations);

#endif /* MC_pricer_hpp */
