#include "Karen.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cout << "Error : Incorrect number of arguments" << std::endl << "Usage : <Karen level>" << std::endl;
		return (0);
	}
	std::string lvl = av[1];
	Karen karen;
	karen.complain(lvl);
	
	return(0);
}	