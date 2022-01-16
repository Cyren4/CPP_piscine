#include "../includes/AMateria.hpp"

AMateria::AMateria(): _type("undefined"), _isAvailable(true){
}

AMateria::AMateria(std::string const & type): _type(type), _isAvailable(true){}

AMateria::AMateria(AMateria const & src){
	*this = src;
}

AMateria::~AMateria(){}

AMateria& AMateria::operator=(AMateria const & a){
	if (this == &a)
		return *this;
	this->_type = a.getType();
	this->_isAvailable = a._isAvailable;
	return *this;
}

void	AMateria::setAvailable(bool state){
	this->_isAvailable = state;
}

bool	AMateria::getAvailable(void) const{
	return this->_isAvailable;
}

std::string const & AMateria::getType() const{
	return this->_type;
}

void		AMateria::use(ICharacter& target)
{
	std::cout <<  "* "<< this->_type << " materia used against " << target.getName() << "*"<< std::endl;
}
