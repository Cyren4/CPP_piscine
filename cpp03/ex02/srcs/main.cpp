#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    std::cout << "Let's create a FragTrap and try some functions :" << std::endl;
    {
        FragTrap p1("lee");
        p1.showParam();
        p1.attack("gaara");
        p1.beRepaired(100);
        // p1.takeDamage(10);
        p1.showParam();
        p1.highFivesGuys();
    }

    // std::cout <<std::endl<< "Let's create try several constructor :" << std::endl;
    // FragTrap p0("Rock");
    // FragTrap p2;
    // FragTrap p3(p0);
}