#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
    public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();

		Dog& operator=(Dog const & a); //operateu

		void    makeSound(void) const;
};

#endif


