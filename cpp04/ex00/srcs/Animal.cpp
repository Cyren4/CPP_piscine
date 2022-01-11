#include "../includes/Animal.hpp"

Animal::Animal() : _type("Undefined"){
	std::cout << "Animal - default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal - constructor called" << std::endl;
}

Animal::Animal(Animal const & src){
	std::cout << "Animal created - copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(){
	std::cout << "Animal <" << this->getType() << ">  - destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const & ct){
	if (this != &ct)
    	this->_type = ct.getType();
	return *this;
}

void	Animal::makeSound(void) const{
	std::cout << "*Undefined animal sound*" << std::endl;
}

std::string	Animal::getType(void) const{
	return this->_type;
}