#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *animal_brain;
    public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();

		Dog& operator=(Dog const & a); //operateu

		virtual void    makeSound(void) const;
		Brain*			getBrainA(void)const;
};

#endif


