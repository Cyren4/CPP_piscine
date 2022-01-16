#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		bool		_isAvailable;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & mat);
		virtual ~AMateria();
		AMateria& operator=(AMateria const & a); 


	std::string const & getType(void) const; //Returns the materia type
	bool	getAvailable(void) const;
	void	setAvailable(bool state);

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

#endif