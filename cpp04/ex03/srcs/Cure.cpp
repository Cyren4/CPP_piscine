#include "../includes/Cure.hpp"

Cure::Cure():AMateria("cure"){}

Cure::Cure(Cure const & src){
	*(this) = src;
}

Cure::~Cure(){}

Cure&		Cure::operator=(Cure const & a){
	if (this != &a)
	{
		this->_type = a._type;
		this->_isAvailable = a._isAvailable;
	}
	return *this;
}

AMateria*	Cure::clone(void) const{
	return new Cure(*this);
}
void		Cure::use(ICharacter& target)
{
	std::cout <<  "* heals "<< target.getName() << "'s wounds *"<< std::endl;
}
