#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20){
	std::cout << "ScavTrap created" << std::endl;
}

// ScavTrap::ScavTrap(ScavTrap const & src){
//     *this = src;
// }

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destroyed" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap entered in Gate keeper mode" << std::endl;
}

// ScavTrap& ScavTrap::operator=(ScavTrap const & ct){
// 	if (this != &ct)
// 	{
//     	this->_name = ct._name;
//     	this->_hitPoints = ct._hitPoints;
//     	this->_energyPoints = ct._energyPoints;
//     	this->_attackDamage = ct._attackDamage;
// 	}
// 	return *this;
// }
