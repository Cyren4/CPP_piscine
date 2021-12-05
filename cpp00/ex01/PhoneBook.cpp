#include <iomanip>
#include "PhoneBook.hpp"

int PhoneBook::_nb_contact = 0;

const std::string	infos[5] = {
	"First name", 
	"Last name", 
	"Nickname", 
	"Phone number", 
	"Darkest secret"
};

PhoneBook::PhoneBook(void){
	return ;
}

bool	is_nb(std::string nb)
{
	int i = 0;
	while (nb[i])
	{
		if (!isdigit(nb[i]))
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::add_contact(void){
	std::string input;
	std::string tmpInfo[5];

	if (this->_nb_contact == 8)
	{
		std::cout << "Oh no ~ The phoneBook is full, sorry mate you need a premium account" << std::endl;
		return ;
	}
	std::cout << "Let's add a new Contact!" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		do{
			std::cout << infos[i] << " : ";
			getline(std::cin, tmpInfo[i]);
			if (std::cin.eof())
			{
				std::cout << "Well done Nills, You broke me!";
				exit(5);
			}
		} while(tmpInfo[i].empty());
		if (i == 4 && is_nb(tmpInfo[i]) == false)
			std::cout << "Be aware of scams this phone number seems fishy" << std::endl;
	}
	this->_contact[this->_nb_contact].set_info(tmpInfo);
	this->_nb_contact++;
	std::cout << "Congrats for this new friend!" << std::endl;

}

void	draw_line(int lengh)
{
	std::cout << "#";
	std::cout << std::setfill('-') << std::setw(lengh);
  	std::cout << "#" << std::endl;
}

void	print_head(void)
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index";
	std::cout << std::setfill(' ') << std::setw(5);
	std::cout << "|";
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setfill(' ') << std::setw(16);
		std::cout << infos[i];
		std::cout << std::setfill(' ') << std::setw(6);
		std::cout << "|";
	}
  	std::cout <<  std::endl;
}

void	PhoneBook::print_list_contact(void){

	draw_line(103);
	print_head();
	draw_line(103);
	for(int i = 0; i < this->_nb_contact; i++)
	{
		this->_contact[i].print_head(i);
		draw_line(103);
	}
}

bool	PhoneBook::is_index(std::string input){
	int	tmp = std::stoi(input);
	
	if (!is_nb(input))
		return false;
	return (tmp >= 0 && tmp < this->_nb_contact);
}

void	PhoneBook::search(void){
	std::string input;

	this->print_list_contact();
	if (this->_nb_contact == 0)
	{
		std::cout << "As you can see you have no friend so come back after making some.." << std::endl;
		return ;
	}
	std::cout << "Who are you looking for? (enter the corresponding index)" << std::endl ;
	std::cout << "index : ";
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "Well done Nills, You broke me!";
		exit(5);
	}
	if (std::cin.eof() || input.empty() || !is_index(input))
		std::cout << "You need to enter an index between 0 and " << this->_nb_contact - 1;
	else
		this->_contact[std::stoi(input)].print_info(infos);
	std::cout << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phonebook was destroyed" << std::endl;

	return ;
}