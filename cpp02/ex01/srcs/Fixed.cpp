#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const val){
	std::cout << "Int constructor called" << std::endl;
	this->_value = val << this->_fractBit;
}

Fixed::Fixed(float const val){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(val * (1 << this->_fractBit));
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & fix){
	 std::cout << "Assignation operator called" << std::endl;
	 if (this != &fix)
	 	this->_value = fix.getRawBits();
	return *this;
}

int     Fixed::getRawBits( void ) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void    Fixed::setRawBits( int const raw ){
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const{
	return this->_value / (float)(1 << this->_fractBit);
	// return this->_value / pow(2.0, this->_fractBit); // equivalent
}

int Fixed::toInt( void ) const{
	return this->_value >> this->_fractBit;
}

std::ostream& operator<<(std::ostream& o, Fixed const & fix){
	o << fix.toFloat();
	return o;
}