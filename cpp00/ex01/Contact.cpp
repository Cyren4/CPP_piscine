
#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){}

Contact::Contact(const std::string fname, const std::string lname, std::string nname,std::string phone,std::string secret) : _firstName(fname), _lastName(lname){
	std::cout << "Contact was created" << std::endl;
	// this->_name = name;
	return ;
}

Contact::~Contact(void){
	std::cout << this->_firstName <<" was destroyed" << std::endl;
	return ;
}