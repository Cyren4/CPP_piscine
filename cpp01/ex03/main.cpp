#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


void	ownTests()
{
	std::cout << "Creation of deadly weapons" << std::endl;
	Weapon w1, w2, w3;
	w1.setType("knife");
	w2.setType("katana");
	w3.setType("gun");
	Weapon w4("spoon");

	std::cout  << std::endl << "Let's have some humans" << std::endl;
	HumanA p1("John", w1);
	HumanA p2("Lara", w3);
	HumanB p3("Gintoki");
	std::cout  << std::endl;	

	p1.attack();
	p2.attack();
	p3.attack();
	// p3.setWeapon(w2);
	p3.attack();
	std::cout  << std::endl;
}

int main(){
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
		std::cout  << std::endl;	
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}