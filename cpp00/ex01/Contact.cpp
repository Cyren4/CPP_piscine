
#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Contact was created" << std::endl;
	return ;
}

Contact::~Contact(void){
	std::cout << "Contact was destroyed" << std::endl;
	return ;
}