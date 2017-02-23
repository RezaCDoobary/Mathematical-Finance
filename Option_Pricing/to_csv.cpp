#include "to_csv.hpp"
#include <fstream>
#include <sstream>
#include <string>

void to_csv(std::string filename, std::string headers, std::vector<double> parameter_1, std::vector<double> parameter_2)
{
    std::ostringstream oss;
    std::ofstream myfile;
    myfile.open(filename);
    std::string text = "";
    myfile << headers;
    for(int i = 0; i < parameter_1.size(); i++){
        text+=std::to_string(parameter_1[i]);
        text+=",";
        text+=std::to_string(parameter_2[i]);
        text +=",\n";
    }
    
    myfile << text;
    myfile.close();
}
