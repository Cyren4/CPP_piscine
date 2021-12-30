#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    std::cout << "Let's create a ScavTrap and try some functions :" << std::endl;
    {
        ScavTrap p1("lee");
        p1.showParam();
        p1.beRepaired(10);
        p1.takeDamage(10);
        p1.attack("gaara");
        p1.guardGate();
        p1.showParam();
    }

    std::cout <<std::endl<< "Let's create try several constructor :" << std::endl;
    ScavTrap p1("Rock");
    ScavTrap p2;
    ScavTrap p3(p1);
}