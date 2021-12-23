#include "Zombie.hpp"

int main(){
	int nb_zombie = 10;
    std::cout << "Let's create a zombies horde" << std::endl;
	Zombie *ZHorde = zombieHorde(nb_zombie, "walkingDead");

	for (int i = 0; i < nb_zombie; i++)
	{
		std::cout << i << " : ";
		ZHorde[i].announce();
	}
	delete [] ZHorde;
}