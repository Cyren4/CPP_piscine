#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int	_value;
		static const int _fractBit = 8;
	public:
//  constructeur & destructeur
		Fixed(); //defaut
		Fixed(int const val); 
		Fixed(float const val); 
		Fixed(Fixed const & src); // copie
		~Fixed();
		Fixed& operator=(Fixed const & fix); //operateur
//  member function
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const & fix); //operateur

#endif