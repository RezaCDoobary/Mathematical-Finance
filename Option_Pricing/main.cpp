#include <iostream>
#include "DigitalOptions.hpp"
#include "VanillaOptions.hpp"
#include "PowerOptions.hpp"
#include "pay_off_bridge.hpp"
#include "MC_pricer.hpp"
#include "Random.hpp"
#include "Analytic.hpp"
#include "to_csv.hpp"
#include "EuropeanOptions.hpp"

// Example of how to use this program:
int main()
{
    double interest_rate = 0.01;
    double volatility = 0.03;
    double strike = 110;
    double initial_spot = 100;
    double expiration = 5;
    int steps = 100000;
    Call call(strike);
    VanillaOption option(call, expiration);
    std::cout << MonteCarlo (option, interest_rate, volatility, initial_spot, steps) << std::endl; // gives, 1.02602
    std::cout << call.BlackScholes(interest_rate, volatility, expiration, initial_spot) << std::endl; //gives 1.02028
}
