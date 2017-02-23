#include "VanillaOptions.hpp"


VanillaOption::VanillaOption(const bridge& payoff_, double Expiration_): payoff(payoff_), Expiration(Expiration_){}

double VanillaOption::getExp() const
{
    return Expiration;
}

double VanillaOption::OptionPayOff(double spot) const
{
    return payoff(spot);
}
