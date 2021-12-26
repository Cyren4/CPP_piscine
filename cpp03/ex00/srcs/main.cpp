#include "ClapTrap.hpp"

int main(){
    ClapTrap p1;
    ClapTrap p2("Hipman");
    ClapTrap p3(p2);
    p1.attack("Hipman");
    p2.showParam();
    p2.takeDamage(10);
    p2.beRepaired(20);
    p2.showParam();
}