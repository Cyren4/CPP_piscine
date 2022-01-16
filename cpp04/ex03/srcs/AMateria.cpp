#include "../includes/AMateria.hpp"

AMateria::AMateria(): _type("undefined"){}

AMateria::AMateria(std::string const & type): _type(type){}

AMateria::AMateria(AMateria const & src){
	*this = src;
}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(AMateria const & a){
	if (this == &a)
		return *this;
	this->_type = a.getType();
	return *this;
}


std::string const & AMateria::getType() const{
	return this->_type;
}

void		AMateria::use(ICharacter& target)
{
	std::cout <<  "* "<< this->_type << " materia used against " << target.getName() << "*"<< std::endl;
}
