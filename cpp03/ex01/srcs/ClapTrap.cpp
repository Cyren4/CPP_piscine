#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("defaultCT"),_hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap created  - default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hP, int eP, int aD): _name(name),_hitPoints(hP), _energyPoints(eP), _attackDamage(aD) {
	std::cout << "ClapTrap  <" << this->_name<< ">  - constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),_hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap  <" << this->_name<< ">  - constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src){
	std::cout << "ClapTrap created - copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap <" << this->_name<< ">  - destructor called" << std::endl;
}

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
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap : <" << this->_name<< "> can't attack he is dead(energyPoints == 0)" << std::endl;
		return;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap : <" << this->_name<< "> can't attack (hitPoints == 0)" << std::endl;
		return;
	}
	std::cout << "ClapTrap <" << this->_name;
	std::cout << "> attacks <" << target << ">, causing <";
	std::cout << this->_attackDamage << "> points of damage!" << std::endl;
	this->_hitPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_energyPoints == 0)
	{
		std::cout << "<" << this->_name<< "> can't take damage he is dead(energyPoints == 0)" << std::endl;
		return;
	}
    std::cout << "<" << this->_name;
	std::cout << "> takes <" << amount << "> points of damage!" << std::endl;
    this->_energyPoints -= amount;
	if (this->_energyPoints < 0)
	{
		this->_energyPoints = 0;
		std::cout << "<" << this->_name << "> just died!" << std::endl;
	}
	std::cout <<"<" << this->_name << "> Current energy points: " << this->_energyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints == 0)
		std::cout << "<" << this->_name<< "> was dead you just resurected him" << std::endl;
	std::cout << "<" << this->_name;
	std::cout << "> gets <" << amount << "> points of repaired!" << std::endl;
    this->_energyPoints += amount;
	std::cout <<"<" << this->_name << "> Current energy points: " << this->_energyPoints << std::endl;
}

void	ClapTrap::showParam()const{
	std::cout << "<" << this->_name << "> : hitPoints = " << this->_hitPoints << "; energyPoints = "<< this->_energyPoints << "; attack damage = " << this->_attackDamage << std::endl;
}