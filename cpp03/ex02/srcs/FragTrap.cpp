#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("defaultFT", 100, 100, 30){
	std::cout << "FragTrap created  - default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name, 100, 100, 30){
	std::cout << "FragTrap  <" << ClapTrap::_name << ">  - constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src){
	std::cout << "FragTrap created - copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap <" << ClapTrap::_name<< ">  - destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void){
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
