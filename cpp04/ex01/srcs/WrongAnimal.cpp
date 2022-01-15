#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Undefined"){
	std::cout << "WrongAnimal - default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal - constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	std::cout << "WrongAnimal created - copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal <" << this->getType() << ">  - destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & ct){
	if (this != &ct)
    	this->_type = ct.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "*Undefined WrongAnimal sound*" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return this->_type;
}