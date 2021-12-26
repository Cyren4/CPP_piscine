#include "ClapTrap.hpp"

int main(){
    ClapTrap p1("lee");
    ClapTrap p2("Hipman");
    p1.attack("Hipman");
    p2.takeDamage(10);
    p2.beRepaired(20);
}