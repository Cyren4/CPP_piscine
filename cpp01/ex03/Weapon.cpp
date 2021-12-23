#include "Weapon.hpp"


Weapon::Weapon(){
	std::cout <<  "Weapon created" << std::endl;
}

Weapon::Weapon(std::string weapon) : _type(weapon)
{}

Weapon::~Weapon() {
	std::cout <<  this->_type << " destroyed" << std::endl;
}

void	Weapon::setType(std::string type) {
	this->_type = type ;
}

std::string const & 	Weapon::getType(void) const{
	return (this->_type);
}