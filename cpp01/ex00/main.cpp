#include "Zombie.hpp"

int main(){
    // randomChump("Zbreu");
    std::cout << "Let's create some static zombies" << std::endl;
	randomChump("Zstat0");
	randomChump("Zstat1");

    std::cout << std::endl << "Let's create one dynamic zombie" << std::endl;
	{
		Zombie	*newZ1 = newZombie("newZbreu");
		newZ1->announce();
		delete newZ1;
	}

	std::cout << std::endl << "Let's create both " << std::endl;
	Zombie	*nZ = newZombie("newZbreu2");
	nZ->announce();
	randomChump("Zstat2");
	delete nZ;
}