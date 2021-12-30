#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap{
	protected: 
		static const int		_hp = 100;
    	static const int		_ep = 100;
        static const int		_ad = 30;
    public:
        FragTrap(); //defaut
		FragTrap(std::string name); //defaut
		FragTrap(FragTrap const & src); // copie
		~FragTrap();

		FragTrap& operator=(FragTrap const & CT); //operateur	

		void	attack(std::string const & target);
		void	highFivesGuys(void) const;
};


#endif