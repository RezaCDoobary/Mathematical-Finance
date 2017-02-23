#include "Random.hpp"

double gaussian(const double mean, const double standard_deviation)
{
    double s, u1, u2;
    do{
        u1 = (double)rand()/RAND_MAX*2.0 - 1.0;
        u2 = (double)rand()/RAND_MAX*2.0 - 1.0;
        s = u1*u1 + u2*u2;
    }while(s >= 1.0 || s==0.0);
    
    s = u1*sqrt((-2.0* log(s))/s);
    return mean + standard_deviation*s;
}

