
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
class Zombie {
	public:
		Zombie();
		Zombie(Zombie &);
		~Zombie();
		Zombie & operator=(Zombie & rhs);
	
	private:
		std::string	name;
};

#endif