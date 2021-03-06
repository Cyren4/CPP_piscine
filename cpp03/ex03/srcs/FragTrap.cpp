#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("defaultFT"){
	std::cout << "FragTrap created  - default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage =  30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	std::cout << "FragTrap  <" << ClapTrap::_name << ">  - constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage =  30;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src){
	std::cout << "FragTrap created - copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap <" << ClapTrap::_name<< ">  - destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) const{
	std::cout << "FragTrap  <" << ClapTrap::_name<< ">  wants to high five everyone ! (but can't because of social distanciation)" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & ct){
	if (this != &ct)
	{
    	this->_name = ct._name;
    	this->_hitPoints = ct._hitPoints;
    	this->_energyPoints = ct._energyPoints;
    	this->_attackDamage = ct._attackDamage;
	}
	return *this;
}
