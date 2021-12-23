#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name)
{
    std::cout <<  "HumanB created" << std::endl;
    this->_weap = NULL;
}

void    HumanB::attack(){
    std::cout << this->_name << " attacks with ";
    if (this->_weap == NULL)
        std::cout << "no weapon";
    else
        std::cout << this->_weap->getType();
    std::cout << std::endl;
}

HumanB::~HumanB()
{
   std::cout << this->_name <<  "(HumanB) died" << std::endl; 
}

void	HumanB::setWeapon(Weapon & weap) {
	this->_weap = &weap ;
}
