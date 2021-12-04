
#include <iostream>
#include <cstring>
#include "Contact.hpp"

Contact::Contact(void) {}

// void Contact::set_info(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret)
void Contact::set_info(std::string info[5])
{
	// std::cout << "Contact was created" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		this->_infos[i] = info[i];
	}
	// this->_firstName = fname;
	// this->_lastName = lname;
	// this->_nickname = nname;
	// this->_phoneNb = phone;
	// this->_secret = secret;
}

// std::string	goodFormat(std::string word)
// {
// 	std::cout.width(10);
// 	std::cout.fill(' ');
// 	if (strlen(word) > 10)
	
// 	std::string head = word.Format("%s")
// 	return ()
// }

void Contact::print_head(int i)
{
	// std::cout << "#---------------------------------------------------------------------------------------#" << std::endl;
	// std::cout << "|	  	"<< i <<"|" << goodFormat(this->_infos[0]) << "|";
	// std::cout  << goodFormat(this->_infos[1])<< "|" <<	goodFormat(this->_infos[2])	<< "|" << std::endl;
	std::cout << "#---------------------------------------------------------------------------------------#" << std::endl;
}

Contact::~Contact(void){}