#include <iostream>
#include <ctime>
#include <fstream>
#include "Func.hpp"

namespace ds
{
	int getExecutionNumber(std::ifstream &in)
	{
		char str[100];
		int k = 1;
		while (in.getline(str, 100))
		{
			k++;

		}
		return k;
	}
}