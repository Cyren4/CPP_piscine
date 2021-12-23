#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon & weapon) : _name(name),  _weap(weapon)
{
    std::cout <<  "HumanA created" << std::endl;
}

void    HumanA::attack(){
    std::cout << this->_name << " attacks with " << this->_weap.getType() << std::endl;
}

HumanA::~HumanA()
{
   std::cout << this->_name <<  "(HumanA) died" << std::endl; 
}