#Option_Pricing

The program so far is designed to price options. It does this in two ways - an analytic method, where one can work out the precise form of the price of a given option and - a statstical method, namely using Monte Carlo methods.
The code is heavily based/adapted from ch 1-4 from Mark Joshi - `C++ design patterns and derivative pricing'. 

I make no claim of novelty - the codes are used for self-education. The idea is to follow some of the coding exercising at the end of Mark Joshi - `The Concepts and Practice of Mathematical Finance'.

In the analytic method, (so far) we use the standard martingale approach to pricing various (so far three) vanilla type options (European, Digital and Power). At the same time, we also have a Monte Carlo methods (also based on the martingale approach) which performs the same function. Option_Pricing.pdf PROVIDES THE THEORETICAL BACKGROUND BEHIND THESE APPROACHES.

Tasks Completed : 

1 - Working program which prices various vanilla options. 

2 - Short analysis of vega (variation of price against volatility produced - see Section 4 of Option_Pricing.pdf)

Short term tasks to be completed/resolved:

1 - Monte Carlo method highly inaccurate for large expirations and volatity (can this be fixed? if so how?)

2 - Path depedent options, exotics?


The structure of the files, is that we have option type classes, which funnel through to a vanilla type class via a bridge pattern. The vanilla option class can then be used as input for the a monte carlo pricer  to retrieve a price. The initial option class input are entered with the analytic black scholes price. 
The structure is as follows:

###Option Input:

1 - Option_Pay_Off.hpp is a purely abstract class and all inherited classes are user inout option classes.


2 - EuropeanOptions, DigitalOptions and PowerOptions files are all to be thought of input classes, namely if we wish to consider further option types (be they vanilla/exotic) they will inherit from Option_Pay_Off. 

###VanillaOption and pay_off_bridge:

1 - VanillaOption is the funelling of the option classes into a specifically vanilla option (i.e. one with predefined expiration). This class adopts all of the option type - whilst also packaging the expiration unquely. We could in principle introduce a bunch of exotic options, which would funnel into another (as yet not created) `ExoticOption' class.

2 - pay_off_bridge provides a bridge pattern, which allows us to manipulate the abstract Option_Pay_Off class, without altering the VanillaOption class. This is important if we include Exotic options at a later point.

###Random and MCPricer:

1 - MCPricer takes in VanillaOptions as input (which defines the spot, strike, expiration and call/put), the MCPricer requires further volatility, interest rate to place a price statistically.

2  - Random supplies the Marsaglia Box Muller method , which gives normally distributed numbers given uniformly distributed numbers.

###Analytic:

1 - Analytic provides the cumulative distribution function and some key equations to be used by the analytically computed black scholes equations.

###Producing plots:

To produce plots and collect data, we transform output into .csv files. We then use python's matplotlib.pyplot to probe the results.

1 - to_csv takes two C++ vectors (plus titles and headers), and returns a .csv file.

2 - price_vs_vol.py is a python file that produces the plots using matplotlib.pyplot.
