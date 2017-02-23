/*
    The bridge design pattern
 
    Used between option pay off class and vanilla options.
 */


#ifndef pay_off_bridge_hpp
#define pay_off_bridge_hpp

#include <stdio.h>
#include "Option_Pay_Off.hpp"
class bridge
{
private:
    Pay_Off* bridge_ptr;
    
public:
    bridge(Pay_Off& payoff_);
    bridge(const bridge& original);
    bridge& operator=(const bridge& original);
    ~bridge();
    double operator()(double spot) const;
};


#endif /* pay_off_bridge_hpp */
