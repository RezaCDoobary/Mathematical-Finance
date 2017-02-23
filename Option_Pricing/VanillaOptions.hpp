/* 
 
 Vanilla Options
 
 These are those which have a predefined strike and expiration. This class funnels through the various option pay off e.g. EuropeanOptions.hpp, PowerOptions.hpp etc. It uses the `bridge design' as this allows us to change/add option classes and this vanilla class without changing the abstract pay off class.
 
 */


#ifndef VanillaOptions_hpp
#define VanillaOptions_hpp

#include <stdio.h>
#include "pay_off_bridge.hpp"

class VanillaOption
{
private:
    double Expiration;
    bridge payoff;
public:
    VanillaOption(const bridge& payoff_, double Expiration_);
    double getExp() const;
    double OptionPayOff(double spot) const;
};

#endif /* VanillaOptions_hpp */
