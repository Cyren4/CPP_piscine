#include <iostream>
#include "PhoneBook.hpp"

void start_phoneBook(void)
{
	PhoneBook	pB;
	std::string input;

	do
	{
		std::cout << "Enter your command : {ADD, SEARCH, EXIT}" << std::endl;
		std::cout << "command : ";
		getline(std::cin, input);
		if (input.compare("EXIT") == 0 || input.empty())
			break;
		else if (input.compare("ADD") == 0)
			pB.add_contact();
		else if (input.compare("SEARCH") == 0)
			pB.search();
		else if (!input.empty())
			std::cout << "Invalid command, try again.";
		if (std::cin.eof())
		{
			std::cout << "Well done Nills, You broke me!";
			exit(5);
		}
		std::cout << std::endl;
	} while (!input.empty());
	std::cout << "Thank you for using our phoneBook!" << std::endl;
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