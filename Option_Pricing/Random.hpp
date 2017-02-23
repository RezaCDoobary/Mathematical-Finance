/*
 
 Marsaglia Box Muller
 
 This method provides a gaussian distribution for any mean and vairances by making use of the internal uniform random number generator.
 
 */

#ifndef Random_hpp
#define Random_hpp
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#define _USE_MATH_DEFINES


double gaussian(const double mean, const double standard_deviation);

#endif /* Random_hpp */
