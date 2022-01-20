#include "../includes/Converter.hpp"

int main(int ac, char** av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error : Number of argument invalid " << std::endl;
		std::cout << "Usage : ./convert <literal> " << std::endl;
	}
	else{
		Converter c(av[1]);
		std::cout << c;
	}
	return 0;
}