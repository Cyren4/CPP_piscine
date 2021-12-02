
#include "PhoneBook.hpp"

int PhoneBook::_nb_contact = 0;

PhoneBook::PhoneBook(void){
	this->_nb_contact++;
	std::cout << "Phonebook "<<this->_nb_contact<<" was created" << std::endl;
	return ;
}

std::string	infos[5] = {
	"First name", 
	"Last name", 
	"Nickname", 
	"Phone number", 
	"Darkest secret"
};

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
			std::cout << infos[i] << std::endl;
			getline(std::cin, tmpInfo[i]);
		} while(tmpInfo[i].empty());
	}
	std::cout << "Oh no ~ The phoneBook is full, sorry mate you need a premium account" << std::endl;

}


void	PhoneBook::print_list_contact(void){

	std::cout << "#---------------------------------------------------------------------------------------#" << std::endl;
	std::cout << "|	index	|	first name	|	last name	|	nickname	|" << std::endl;
	std::cout << "#---------------------------------------------------------------------------------------#" << std::endl;
	// std::cout << "#-----------------------------------------------------#" << std::endl;
	// for(int i = 0; i < this->nb_contact; i++)
	// {

	// }

}

void	PhoneBook::search(void){
	this->print_list_contact();
	// std::cout << "Who are you looking for? (enter the corresponding index)" << std::endl ;
	// getline(std::cin, str);
	// choice = check_num(str);
	// if (choice < 0)
	// 			std::cout << "You need to enter a valid index!" << std::endl;
	// 		else
	// 			pB.print_contact(choice);
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phonebook was destroyed" << std::endl;

	return ;
}