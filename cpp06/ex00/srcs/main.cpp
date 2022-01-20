#include "../includes/Converter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Error : Number of argument invalid " << std::endl;
		std::cout << "Usage : " << av[1] << " <literal> " << std::endl;
	}
	return 0;
}