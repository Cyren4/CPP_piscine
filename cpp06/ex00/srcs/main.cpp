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
		// std::string literal = static_cast<std::string>(av[1]);
		Converter literal(av[1]);
		literal.print();
		// char *pEnd;
		// std::cout << strtol(av[1], &pEnd,10);
		std::cout << atof(av[1]);
		
		// char * pEnd;
		// double 
		// std::cout << 
		// Converter c(av[1]);
	}
	return 0;
}
