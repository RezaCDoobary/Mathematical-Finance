#include "MC_pricer.hpp"
#include <cmath>
#include "Random.hpp"
#include "VanillaOptions.hpp"


double MonteCarlo(VanillaOption theoptionpayoff, const double interest_rate, const double volatility, const double initial_spot, const int number_of_simulations)
{
    double expectation_value = 0;
    double expiration = theoptionpayoff.getExp();
    double continuous_part = (interest_rate - 0.5*volatility*volatility)*expiration;
    double root = volatility*sqrt(expiration);
    double continous_spot_evolution = initial_spot*exp(continuous_part);
    double final_spot = 0;
    double sum = 0;
    
    for(unsigned long i = 0; i < number_of_simulations; i++)
    {
        double normal = gaussian(0,1);
        final_spot = continous_spot_evolution*exp(root*normal);
        double payoff = theoptionpayoff.OptionPayOff(final_spot);
        sum += payoff;
    }
    
    expectation_value = sum/number_of_simulations;
    expectation_value = expectation_value*exp(-interest_rate*expiration);
    return expectation_value;
}


