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
		std::string tmp = av[1];
		Converter c(tmp);
		std::cout << c;
	}
	return 0;
}