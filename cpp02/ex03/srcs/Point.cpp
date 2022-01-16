#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()){
}

Point::Point(Point const & p){
	// std::cout << "Int constructor called" << std::endl;
	*this = p;
}

Point& Point::operator=(Point const & p) : x(Fixed(p.x)), y(Fixed(p.y)) {
	return *this;
};

Point::~Point(){}