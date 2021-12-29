#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap{
    public:
        ScavTrap(); //defaut
		ScavTrap(std::string name); //defaut
		ScavTrap(ScavTrap const & src); // copie
		~ScavTrap();

		ScavTrap& operator=(ScavTrap const & CT); //operateur	

		void	guardGate(void);
};


#endif