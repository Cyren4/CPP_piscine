#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & src){
    *this = src;
}

ClapTrap::~ClapTrap(){}

ClapTrap& ClapTrap::operator=(ClapTrap const & ct){
	if (this != &ct)
	{
    	this->_name = ct._name;
    	this->_hitPoints = ct._hitPoints;
    	this->_energyPoints = ct._energyPoints;
    	this->_attackDamage = ct._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const & target){
	std::cout << "ClapTrap <" << this->_name;
	std::cout << "> attacks <" << target << ">, causing <";
	std::cout << this->_hitPoints << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap <" << this->_name;
	std::cout << "> take <" << amount << "> points of damage!" << std::endl;
    this->_energyPoints -= amount;
	std::cout <<"<" << this->_name << "> Current energy points: " << this->_energyPoints << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "Be careful <" << this->_name << "> has negative or 0 energy points he might die!" << std::endl;
    this->_attackDamage += amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "ClapTrap <" << this->_name;
	std::cout << "> gets <" << amount << "> points of repaired!" << std::endl;
    this->_energyPoints += amount;
	std::cout <<"<" << this->_name << "> Current energy points: " << this->_energyPoints << std::endl;
}