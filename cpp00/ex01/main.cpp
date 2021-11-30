#include <iostream>
#include "PhoneBook.class.hpp"

void	start_phoneBook(void)
{
	PhoneBook	annuaire;
	std::string str;

	while (1)
	{
		std::cout << "Enter your command : ";
		getline(std::cin, str);
		// std::cout << std::endl;
		std::cout << str << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 1)
	{
		std::cout << "Error : No arguments required" << std::endl;
		std::cout << "Usage : " << av[0] << std::endl;
    }
	else
		start_phoneBook();

    return (0);
}