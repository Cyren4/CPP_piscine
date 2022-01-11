#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal{
	protected:
		std::string _type;
    public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal();

		WrongAnimal& operator=(WrongAnimal const & a); //operateur

		void    makeSound(void) const;
		std::string    getType(void) const;
};

#endif