#include "../includes/Converter.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>

int main(int ac, char** av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error : Number of argument invalid " << std::endl;
		std::cout << "Usage : ./convert <literal> " << std::endl;
	}
	else{
		Converter literal(av[1]);
		literal.print();	
	}
	return 0;
}
