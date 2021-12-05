
#ifndef RANDOMCHUMP_H
# define RANDOMCHUMP_H

#include <iostream>
class randomChump {
	public:
		randomChump();
		randomChump(randomChump &);
		~randomChump();
		randomChump & operator=(randomChump & rhs);
};

#endif