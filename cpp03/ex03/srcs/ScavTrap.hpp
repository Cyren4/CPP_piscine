#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap{
	protected: 
		static const int		_hp = 100;
    	static const int		_ep = 50;
        static const int		_ad = 20;
    public:
        ScavTrap(); //defaut
		ScavTrap(std::string name); //defaut
		ScavTrap(ScavTrap const & src); // copie
		~ScavTrap();

		ScavTrap& operator=(ScavTrap const & CT); //operateur	

		void	attack(std::string const & target);
		void	guardGate(void) const;
};


#endif