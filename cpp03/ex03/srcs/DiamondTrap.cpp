#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): 
	ClapTrap("defaultDT_clap_name")
{
	std::cout << "DiamondTrap created  - default constructor" << std::endl;
	this->_name = "defaultDT"; 
	this->_hitPoints = FragTrap::_hp;
	this->_energyPoints = ScavTrap::_ep;
	this->_attackDamage =  FragTrap::_ad;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name")
{
	this->_name = name; 
	std::cout << "DiamondTrap  <" << _name << ">  - constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hp;
	this->_energyPoints = ScavTrap::_ep;
	this->_attackDamage =  FragTrap::_ad;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src){
	std::cout << "DiamondTrap created - copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap <" << _name<< ">  - destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & ct){
	if (this != &ct)
	{
    	this->_name = ct._name;
    	this->_hitPoints = ct._hitPoints;
    	this->_energyPoints = ct._energyPoints;
    	this->_attackDamage = ct._attackDamage;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const & target) 
{
	ScavTrap::attack(target);	
}

void	DiamondTrap::showParam()const{
	std::cout << "DiamondTrap : " << _name << std::endl;
	std::cout << "<" << this->_name << "> : hitPoints = " << this->_hitPoints << "; energyPoints = "<< this->_energyPoints << "; attack damage = " << this->_attackDamage << std::endl;
}

void	DiamondTrap::whoAmI(void) const{
	std::cout << "DiamondTrap : Hi my name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}