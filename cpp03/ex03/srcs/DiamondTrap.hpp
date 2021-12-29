#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string	_name;
        
    public:
        DiamondTrap(); //defaut
		DiamondTrap(std::string name); //defaut
		DiamondTrap(DiamondTrap const & src); // copie
		~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const & CT); //operateur	

		void	guardGate(void);
		void	showParam()const;
};


#endif