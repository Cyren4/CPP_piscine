#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    DiamondTrap p("yo");
    p.attack("wsh");
    p.showParam();
    std::cout << std::endl << "Let's try special functions :" << std::endl;
    p.whoAmI();
    p.guardGate();
    p.highFivesGuys();
}