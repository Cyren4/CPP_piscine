#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("defaultST", 100, 50, 20){
	std::cout << "ScavTrap created  - default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20){
	std::cout << "ScavTrap  <" << ClapTrap::_name << ">  - constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src){
	std::cout << "ScavTrap created - copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap <" << ClapTrap::_name<< ">  - destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target){
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap : <" << this->_name<< "> can't attack he is dead(hitPoints == 0)" << std::endl;
		return;
	}
	std::cout << "ScavTrap <" << this->_name;
	std::cout << "> attacks <" << target << ">, causing <";
	std::cout << this->_attackDamage << "> points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) const{
	std::cout << "ScavTrap  <" << ClapTrap::_name << ">  entered in Gate keeper mode" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & ct){
	if (this != &ct)
	{
    	this->_name = ct._name;
    	this->_hitPoints = ct._hitPoints;
    	this->_energyPoints = ct._energyPoints;
    	this->_attackDamage = ct._attackDamage;
	}
	return *this;
}
