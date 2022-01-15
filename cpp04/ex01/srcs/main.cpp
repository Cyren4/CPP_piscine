#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
	// system("leaks");
	{
		std::cout << "-------Big test-------" << std::endl;
		std::cout << std::endl << "==== Dog Construction ====" << std::endl << std::endl;
		const Animal *farm[100];
		for (int i = 0; i < 100; i++)
		{
			if (i == 50)
				std::cout << std::endl << "==== Cat Construction ====" << std::endl << std::endl;
			if (i < 50)
				farm[i] = new Dog();
			else
				farm[i] = new Cat();
		}
		std::cout << std::endl << "==== Destruction test ====" << std::endl << std::endl;
		for (int i = 0; i < 100; i++)
			delete farm[i];
	}

	{
		std::cout << "-------Small test-------" << std::endl;
		const Animal* j = new Dog();
   		const Animal* i = new Cat();

		std::cout << "Destruction test" << std::endl;
		delete j;//should not create a leak
    	delete i;
	}
	{
		std::cout << std::endl << "-------Deep test-------" << std::endl;
		const Dog* realD = new Dog();
   		const Cat* realC = new Cat();
		const Dog* copyD = new Dog(*realD);
   		const Cat* copyC = new Cat(*realC);	

		std::cout << std::endl << "-------show adress test-------" << std::endl << std::endl;
		std::cout << "Address original Dog :\t" << realD->getBrainA() << std::endl;
		std::cout << "Address copy Dog :\t" << copyD->getBrainA() << std::endl;
		std::cout << "Address original Cat :\t" << realC->getBrainA() << std::endl;
		std::cout << "Address copy Cat :\t" << copyC->getBrainA() << std::endl;

		std::cout << std::endl << "-------Destruction test-------" << std::endl << std::endl;
		delete realD; 
		delete realC; 
		delete copyD;
		delete copyC;
	}
}