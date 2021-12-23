
#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon {
	public:
		Weapon();
		Weapon(std::string weapon);
		~Weapon();
		void	setType(std::string type);
		std::string const &	getType(void) const;
	private:
		std::string	_type;
};


#endif