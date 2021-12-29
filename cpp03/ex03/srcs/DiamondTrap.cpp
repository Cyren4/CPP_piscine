#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): 
	ClapTrap("defaultDT_clap_name")
{
	std::cout << "DiamondTrap created  - default constructor" << std::endl;
	this->_name = "defaultDT"; 
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage =  FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name")
{
	this->_name = name; 
	std::cout << "DiamondTrap  <" << _name << ">  - constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage =  FragTrap::_attackDamage;
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


void	DiamondTrap::showParam()const{
	std::cout << "DiamondTrap : " << _name << std::endl;
	std::cout << "<" << this->_name << "> : hitPoints = " << this->_hitPoints << "; energyPoints = "<< this->_energyPoints << "; attack damage = " << this->_attackDamage << std::endl;
}