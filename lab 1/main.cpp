#include <iostream>
#include <ctime>
#include <fstream>
#include "Func.hpp"

int main(void)
{
    
    std::ifstream in("time.txt");
    int k;
    k=ds::getExecutionNumber(in);

    std::time_t seconds = std::time(NULL);
    tm* timeinfo = std::localtime(&seconds);
   
    std::ofstream out("time.txt", std::ios::app);
    out << k << " " << timeinfo->tm_year + 1900 << " " << timeinfo->tm_mon + 1 <<
    " " << timeinfo->tm_mday << " " << timeinfo->tm_hour <<
    " " << timeinfo->tm_min << " " << timeinfo->tm_sec << std::endl;

}