
#ifndef NEWZOMBIE_H
# define NEWZOMBIE_H

#include <iostream>
class newZombie {
	public:
		newZombie();
		newZombie(newZombie &);
		~newZombie();
		newZombie & operator=(newZombie & rhs);
};

#endif