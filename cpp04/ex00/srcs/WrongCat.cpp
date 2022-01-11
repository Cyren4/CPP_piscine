#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat - default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string breed) :WrongAnimal("WrongCat (" + breed + ")"){
	std::cout << "WrongCat - constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src){
	std::cout << "WrongCat created - copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat <" << this->getType() << ">  - destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & ct){
	if (this != &ct)
    	this->_type = ct.getType();
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "*Nyan Nyaaan*" << std::endl;
}
