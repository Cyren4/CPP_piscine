#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal{
	protected:
		std::string _type;
    public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();

		Animal& operator=(Animal const & a); //operateur

		virtual void    makeSound(void) const = 0;
		std::string    getType(void) const;
};

#endif