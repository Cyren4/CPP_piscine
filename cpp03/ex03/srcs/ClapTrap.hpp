#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap{
    protected:
        std::string	_name;
        int		_hitPoints;
    	int		_energyPoints;
        int		_attackDamage;

    public:
        ClapTrap(); //defaut
		ClapTrap(std::string name); //defaut
		ClapTrap(std::string name, int hP, int eP, int aD);
		ClapTrap(ClapTrap const & src); // copie
		~ClapTrap();

		ClapTrap& operator=(ClapTrap const & CT); //operateur

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void showParam(void) const;
};

#endif