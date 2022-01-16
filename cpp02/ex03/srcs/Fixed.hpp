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
		
//  operator overload
		Fixed& operator=(Fixed const & fix); //operateur

		// Comparison
		bool operator>(Fixed const & fix) const; 
		bool operator>=(Fixed const & fix) const; 
		bool operator<(Fixed const & fix) const; 
		bool operator<=(Fixed const & fix) const; 
		bool operator==(Fixed const & fix) const; 
		bool operator!=(Fixed const & fix) const; 

		// Arithmetic 
		Fixed operator+(Fixed const & fix); 
		Fixed operator-(Fixed const & fix); 
		Fixed operator*(Fixed const & fix); 
		Fixed operator/(Fixed const & fix); 

		//Increment / decrement 
		Fixed operator++(int); 
		Fixed operator++(); 
		Fixed operator--(int); 
		Fixed operator--(); 

		//static member function
		static Fixed& min(Fixed & op1, Fixed & op2);
		static Fixed& max(Fixed & op1, Fixed & op2);
		static Fixed& max(Fixed const & op1, Fixed const & op2);

//  member function
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

//overload
std::ostream& operator<<(std::ostream& o, Fixed const & fix); //operateur
Fixed const & min(Fixed const & op1, Fixed const & op2);
Fixed const & max(Fixed const & op1, Fixed const & op2);

#endif