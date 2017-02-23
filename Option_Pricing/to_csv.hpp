/*
 
 Changes two vectors into a .csv file which can be used by pythons - pandas library.
 
 */

#ifndef to_csv_hpp
#define to_csv_hpp
#include <stdio.h>
#include <vector>
#include <string>

/* filename is the prospective name; e.g. filename.csv. The headers must be written as "vol,price,\n" so that the first column is vol
and the second is price. 
 */
void to_csv(std::string filename, std::string headers, std::vector<double> parameter_1, std::vector<double> parameter_2);

#endif /* to_csv_hpp */
