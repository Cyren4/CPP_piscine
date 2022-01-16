#include "Karen.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cout << "Error : Incorrect number of arguments" << std::endl << "Usage : <Karen level>" << std::endl;
		return (0);
	}
	std::string const lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};	
	std::string level = av[1];
	Karen karen;
	int i = 0;
	while (i < 4 && level.compare(lvl[i]))
		i++;
	
	switch (i)
	{
		case 0:
			karen.complain(lvl[0]);
		case 1:
			karen.complain(lvl[1]);
		case 2:
			karen.complain(lvl[2]);
		case 3:
			karen.complain(lvl[3]);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return(0);
}	