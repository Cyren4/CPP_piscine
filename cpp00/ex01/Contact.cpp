
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.hpp"

Contact::Contact(void) {}

// void Contact::set_info(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret)
void Contact::set_info(std::string info[5])
{
	for (int i = 0; i < 5; i++)
		this->_infos[i] = info[i];
}

void	goodFormat(std::string word)
{
	std::string	str(10, ' ');

	if (word.length() > 10)
	{
		str = word.substr(0, 10);
		str[9] = '.';
	}
	else
		str = word.substr(0, word.length());
	std::cout << std::setfill(' ') << std::setw(16);
	std::cout << str;
	std::cout << std::setfill(' ') << std::setw(6);
	std::cout << "|";
}

void Contact::print_info(const std::string infos[5])
{
	for (int i = 0; i < 5; i++)
		std::cout << infos[i] << " : " << this->_infos[i] << std::endl;
}

void Contact::print_head(int i)
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << i;
	std::cout << std::setfill(' ') << std::setw(5);
	std::cout << "|";
	for (int i = 0; i < 4; i++)
		goodFormat(this->_infos[i]); 
	std::cout << std::endl;

}

Contact::~Contact(void){}