#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
    public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & src);
		~Cat();

		Cat& operator=(Cat const & a); //operateu

		virtual void    makeSound(void) const;
};

#endif