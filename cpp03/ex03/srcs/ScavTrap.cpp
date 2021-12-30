#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("defaultST"){
	std::cout << "ScavTrap created  - default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage =  20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name){
	std::cout << "ScavTrap  <" << ClapTrap::_name << ">  - constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage =  20;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src){
	std::cout << "ScavTrap created - copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap <" << ClapTrap::_name<< ">  - destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target){
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap : <" << this->_name<< "> can't attack he is dead(energyPoints == 0)"<< std::endl;
		return;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap : <" << this->_name<< "> can't attack (hitPoints == 0)"<< std::endl;
		return;
	}
	std::cout << "ScavTrap <" << this->_name;
	std::cout << "> attacks <" << target << ">, causing <";
	std::cout << this->_attackDamage << "> points of damage!" << std::endl;
	this->_hitPoints--;
}

void	ScavTrap::guardGate(void) const{
	std::cout << "ScavTrap  <" << ClapTrap::_name<< ">  entered in Gate keeper mode" << std::endl;
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
