#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    DiamondTrap p("yo");
    p.attack("wsh");
    p.showParam();
    p.whoAmI();
}