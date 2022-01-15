#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
	std::cout << "-------Small test-------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const Animal* meta = Animal();	
	// const Animal* meta1;	

	std::cout << "Destruction test" << std::endl;
	delete j;//should not create a leak
   	delete i;
}