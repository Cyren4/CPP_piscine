
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
class Zombie {
	public:
		Zombie();
		Zombie(std::string zname);
		~Zombie();
		void	announce( void );
		void	setName(std::string zname);
	
	private:
		std::string	name;
};

Zombie* zombieHorde(int N, std::string name);

#endif