#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat - default constructor called" << std::endl;
}

Cat::Cat(std::string breed) :Animal("Cat (" + breed + ")"){
	std::cout << "Cat - constructor called" << std::endl;
}

Cat::Cat(Cat const & src){
	std::cout << "Cat created - copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(){
	std::cout << "Cat <" << this->getType() << ">  - destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & ct){
	if (this != &ct)
    	this->_type = ct.getType();
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "*Nyan Nyaaan*" << std::endl;
}
