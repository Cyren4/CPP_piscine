#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap{
    private:
        ClapTrap(); //defaut
        std::string	_name;
        int		_hitPoints;
    	int		_energyPoints;
        int		_attackDamage;

    public:
		ClapTrap(std::string name); //defaut
		ClapTrap(ClapTrap const & src); // copie
		~ClapTrap();

		ClapTrap& operator=(ClapTrap const & CT); //operateur

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif