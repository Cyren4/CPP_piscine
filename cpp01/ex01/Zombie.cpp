#include "Zombie.hpp"

Zombie::Zombie(std::string zname) {
	this->name = zname ;
	// this->announce();
}

Zombie::Zombie(): name(""){}

Zombie::~Zombie() {
	std::cout << "<" << this->name << ">" << " UUghhfdf .. *got shot by a hunter*" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << "<" << this->name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string zname) {
	this->name = zname ;
}
