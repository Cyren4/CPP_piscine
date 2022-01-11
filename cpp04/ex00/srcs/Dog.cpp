#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog - default constructor called" << std::endl;
}

Dog::Dog(std::string breed) :Animal("Dog (" + breed + ")"){
	std::cout << "Dog - constructor called" << std::endl;
}

Dog::Dog(Dog const & src){
	std::cout << "Dog created - copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(){
	std::cout << "Dog <" << this->getType() << ">  - destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & ct){
	if (this != &ct)
    	this->_type = ct.getType();
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "*Bark Bark Bark*" << std::endl;
}
