#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog - default constructor called" << std::endl;
	this->animal_brain = new Brain();
}

Dog::Dog(std::string breed) :Animal("Dog (" + breed + ")"){
	std::cout << "Dog - constructor called" << std::endl;
	this->animal_brain = new Brain();
}

Dog::Dog(Dog const & src){
	std::cout << "Dog created - copy constructor called" << std::endl;
	this->animal_brain = new Brain();
    *this = src;
}

Dog::~Dog(){
	delete this->animal_brain;
	std::cout << "Dog <" << this->getType() << ">  - destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & ct){
	if (this != &ct)
	{
    	this->_type = ct.getType();
		*(this->animal_brain) = *(ct.animal_brain);
	}
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "*Bark Bark Bark*" << std::endl;
}

Brain*	Dog::getBrainA(void)const{
	return this->animal_brain;
}