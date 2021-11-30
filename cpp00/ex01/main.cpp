#include <iostream>
#include "PhoneBook.hpp"

void	start_phoneBook(void)
{
	PhoneBook	annuaire;
	std::string str;

	do
	{
		std::cout << "Enter your command : ";
		getline(std::cin, str);
		if (str.compare("EXIT") == 0 || str.empty())
			break ;	
		else if (str.compare("ADD") == 0)
			std::cout << "Let's add a new Contact!";
		else if (str.compare("SEARCH") == 0)
			std::cout << "Who are you looking for?";
		else if(!str.empty())
			std::cout << "Invalid command, try again.";
		std::cout << std::endl;
	}
	while (!str.empty());
	std::cout << "Thank you for using our phoneBook!"<< std::endl;

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