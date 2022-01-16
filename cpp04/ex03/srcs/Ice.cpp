#include "../includes/Ice.hpp"

Ice::Ice():AMateria("ice"){}

Ice::Ice(Ice const & src){
	*(this) = src;
}

Ice::~Ice(){}

Ice&		Ice::operator=(Ice const & a){
	if (this != &a)
	{
		this->_type = a._type;
		this->_isAvailable = a._isAvailable;
	}
	return *this;
}

AMateria*	Ice::clone(void) const{
	return new Ice(*this);
}

void		Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at "<< target.getName() << "*"<< std::endl;
}
