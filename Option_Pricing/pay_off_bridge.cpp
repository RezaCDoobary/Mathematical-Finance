#include "pay_off_bridge.hpp"


bridge::bridge(Pay_Off& payoff)
{
    bridge_ptr = payoff.clone();
}

bridge::bridge(const bridge& original)
{
    bridge_ptr = original.bridge_ptr->clone();
}

bridge& bridge::operator=(const bridge& original)
{
    if(this!=&original)
    {
        delete bridge_ptr;
        bridge_ptr = original.bridge_ptr->clone();
    }
    
    return *this;
}

bridge::~bridge()
{
    delete bridge_ptr;
}

double bridge::operator()(double spot) const
{
    return bridge_ptr -> operator()(spot);
}
