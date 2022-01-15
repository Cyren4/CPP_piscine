#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
    {
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
    }
    {
		const Animal farm[100];
		for (int i = 0; i < 100; i++)
		{
			if (i < 50)
				farm[i] = new Cat();
			else
				farm[i] = new Dog();
		}
		delete [] farm;
    }
}