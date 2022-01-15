#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *animal_brain;
    public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & src);
		~Cat();

		Cat& operator=(Cat const & a); //operateu

		virtual void    makeSound(void) const;
		Brain*			getBrainA(void)const;
};

#endif