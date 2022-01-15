#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat - default constructor called" << std::endl;
	this->animal_brain = new Brain();
}

Cat::Cat(std::string breed) :Animal("Cat (" + breed + ")"){
	std::cout << "Cat - constructor called" << std::endl;
	this->animal_brain = new Brain();
}

Cat::Cat(Cat const & src){
	std::cout << "Cat created - copy constructor called" << std::endl;
	this->animal_brain = new Brain();
    *this = src;
}

Cat::~Cat(){
	delete this->animal_brain;
	std::cout << "Cat <" << this->getType() << ">  - destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & ct){
	if (this != &ct)
	{
    	this->_type = ct.getType();
		*(this->animal_brain) = *(ct.animal_brain);
	}
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "*Nyan Nyaaan*" << std::endl;
}

Brain*	Cat::getBrainA(void)const{
	return this->animal_brain;
}