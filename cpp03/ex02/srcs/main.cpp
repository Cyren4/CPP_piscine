#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    std::cout << "Let's create a FragTrap and try some functions :" << std::endl;
    {
        FragTrap p1("lee");
        p1.showParam();
        p1.beRepaired(10);
        p1.takeDamage(10);
        p1.showParam();
        p1.highFivesGuys();
    }

    std::cout <<std::endl<< "Let's create try several constructor :" << std::endl;
    FragTrap p0("Rock");
    ScavTrap p1("Rock");
    p1.guardGate();
    FragTrap p2;
    FragTrap p3(p0);
}