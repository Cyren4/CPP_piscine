#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat& operator=(WrongCat const & a); //operateu

		void    makeSound(void) const;
};

#endif