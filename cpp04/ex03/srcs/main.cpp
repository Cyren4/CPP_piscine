#include "../includes/header.hpp"

int main() {
	{
		std::cout << "---- Test main sujet ----" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "----  Complete Tests ----" << std::endl;
		
		std::cout << std::endl << "----  create tests ----" << std::endl;

		std::cout << std::endl << "####  Constructor called ####" << std::endl;
		IMateriaSource* src = new MateriaSource();
		AMateria *i1 = new Ice();
		AMateria *c1 = new Cure();
		ICharacter *p1 = new Character("Jim");
		ICharacter *p2 = new Character("Bob");

		std::cout << std::endl << "----  MateriaSource tests ----" << std::endl;
		std::cout << "----  learn tests ----" << std::endl;
		src->learnMateria(i1);
		src->learnMateria(c1);
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *i2 = src->createMateria("ice");
		AMateria *i3 = src->createMateria("ice");
		AMateria *c2 = src->createMateria("cure");
		AMateria *c3 = src->createMateria("cure");

		std::cout << std::endl << "----  Materia present ----" << std::endl;
		std::cout << i1->getType() << std::endl;
		std::cout << i2->getType() << std::endl;
		std::cout << c1->getType() << std::endl;
		std::cout << c2->getType() << std::endl;
		std::cout << std::endl << "----  Character present ----" << std::endl;
		std::cout << p1->getName()<< std::endl;
		std::cout << p2->getName()<< std::endl;

		std::cout << std::endl << "----  Character with Materia ----" << std::endl;
		std::cout <<"----  equip tests ----" << std::endl;
		p1->equip(i1);
		p1->equip(i2);
		p1->equip(i3);
		p1->equip(c2);
		p2->equip(c3);

		std::cout << std::endl << "----  equip/unequip tests ----" << std::endl;
		p1->unequip(0);
		p1->equip(i2);
		p1->unequip(0);
		p1->equip(i2);
		p2->unequip(2); // not supposed to remove since empty

		std::cout << std::endl << "----  use tests ----" << std::endl;
		p2->use(0, *p1);
		p1->use(0, *p1);
		p1->use(1, *p2);
		p1->use(2, *p2);
		p1->use(3, *p1);
		p2->use(10, *p1); // not supposed to use since invalid index
		p1->use(0, *p1);

		std::cout << std::endl << "####  Destructor called ####" << std::endl;
		delete p1;
		delete p2;
		delete src;
	}
	return 0; 
}
