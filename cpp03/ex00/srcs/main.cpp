#include "ClapTrap.hpp"

int main(){
    ClapTrap p1("Hipman");
    ClapTrap p2;
    // ClapTrap p3(p2);

    p1.showParam();
    p1.attack("Hipman");
    p1.takeDamage(10);
    p1.takeDamage(UINT32_MAX);
    p1.beRepaired(UINT32_MAX);
    p1.showParam();
    p1.beRepaired(3);
    p1.showParam();
}