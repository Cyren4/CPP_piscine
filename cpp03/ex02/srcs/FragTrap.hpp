#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap{
    private:
        std::string	_name;
        int		_hitPoints;
    	int		_energyPoints;
        int		_attackDamage;

    public:
        FragTrap(); //defaut
		FragTrap(std::string name); //defaut
		FragTrap(FragTrap const & src); // copie
		~FragTrap();

		FragTrap& operator=(FragTrap const & CT); //operateur	

		void	highFivesGuys(void);
};


#endif