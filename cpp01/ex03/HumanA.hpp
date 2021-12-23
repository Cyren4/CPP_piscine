#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon & weap);
        ~HumanA();
        void    attack(void);

    private:
        const std::string _name;
        const Weapon & _weap;
};
#endif