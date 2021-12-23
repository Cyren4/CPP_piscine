#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB();
        void	setWeapon(Weapon & weap);
        void    attack(void);

    private:
        const std::string _name;
        Weapon *_weap;
};
#endif