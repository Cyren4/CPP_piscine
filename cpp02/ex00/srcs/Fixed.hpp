#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed{
	public:
//  constructeur & destructeur
		Fixed(); //defaut
		Fixed(Fixed const & src); // copie
		~Fixed();
		Fixed& operator=(Fixed const & fix); //operateur
//  member function
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int	_value;
		static const int _fractBit = 8;
};

#endif