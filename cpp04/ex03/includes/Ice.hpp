#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
	public:
		Ice();
		Ice(Ice const & i);
		~Ice();

		Ice&		operator=(Ice const & a); 
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif