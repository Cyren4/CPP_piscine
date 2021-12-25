#include "Fixed.hpp"

//	Constructor
Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int const val){
	// std::cout << "Int constructor called" << std::endl;
	this->_value = val << this->_fractBit;
}

Fixed::Fixed(float const val){
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(val * (1 << this->_fractBit));
}

Fixed::Fixed(Fixed const & src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//	Destructor
Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

//  operator overload

Fixed& Fixed::operator=(Fixed const & fix){
	//  std::cout << "Assignation operator called" << std::endl;
	 if (this != &fix)
	 	this->_value = fix.getRawBits();
	return *this;
}

// Comparison
bool Fixed::operator>(Fixed const & fix) const{
	return this->getRawBits() > fix.getRawBits();
}

bool Fixed::operator>=(Fixed const & fix) const{
	return this->getRawBits() >= fix.getRawBits();
}

bool Fixed::operator<(Fixed const & fix) const{
	return this->getRawBits() < fix.getRawBits();
}

bool Fixed::operator<=(Fixed const & fix) const{
	return this->getRawBits() <= fix.getRawBits();
}

bool Fixed::operator==(Fixed const & fix) const{
	return this->getRawBits() == fix.getRawBits();
}

bool Fixed::operator!=(Fixed const & fix) const{
	return this->getRawBits() != fix.getRawBits();
}

// Arithmetic 
Fixed Fixed::operator+(Fixed const & fix){
	return Fixed(this->toFloat() + fix.toFloat()); //moins precis
}

Fixed Fixed::operator-(Fixed const & fix){
	return Fixed(this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(Fixed const & fix){
	return Fixed(this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(Fixed const & fix){
	return Fixed(this->toFloat() / fix.toFloat());
}

//Increment / decrement 
Fixed Fixed::operator++(int){ //postfix
	Fixed tmp;
	tmp._value = this->_value++;
	return tmp;
}

Fixed Fixed::operator++(){//prefix
	Fixed tmp;
	tmp._value = ++this->_value;
	return tmp;
}

Fixed Fixed::operator--(int){//postfix
	Fixed tmp;
	tmp._value = this->_value--;
	return tmp;;
}

Fixed Fixed::operator--(){//prefix
	Fixed tmp;
	tmp._value = --this->_value;
	return tmp;
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

// static member function
Fixed & Fixed::min(Fixed & op1, Fixed & op2){
	if (op1 < op2)
		return op1;
	return op2;
}

Fixed & Fixed::max(Fixed & op1, Fixed & op2){
	if (op1 < op2)
		return op2;
	return op1;
}

// overload
Fixed const& min(Fixed const & op1, Fixed const & op2){
	if (op1 < op2)
		return op1;
	return op2;
}

Fixed const& max(Fixed const & op1, Fixed const & op2){
	if (op1 < op2)
		return op2;
	return op1;
}

std::ostream& operator<<(std::ostream& o, Fixed const & fix){
	o << fix.toFloat();
	return o;
}