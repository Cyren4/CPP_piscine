#include "../includes/Character.hpp"

Character::Character(): _name("unknown"){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name):  _name(name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(){}
		
Character&		Character::operator=(Character const & src){
	if (this == &src)
		return *this;
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i]; 
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone(); 
	}
	return *this;
} 

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	for(int i = 0; i < 4 ; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " got a new equipment : "<< m->getType() << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " inventory is full you can't add more materia" << std::endl;
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3)
		std::cout << idx << " : invalid index. Inventory materia only between 0 - 3" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << idx << " : invalid index. This inventory index is empty" << std::endl;
	else 
	{
		this->_inventory[idx] = NULL;
		std::cout << idx << " :  inventory index got emptied" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
		std::cout << idx << " : invalid index. Inventory materia only between 0 - 3" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << idx << " : invalid index. This inventory index is empty" << std::endl;
	else 
		this->_inventory[idx]->use(target);
}
