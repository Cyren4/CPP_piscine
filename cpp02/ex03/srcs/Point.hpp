#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point{
    private:
        Fixed const x;
        Fixed const y;
    public:
    //  constructeur & destructeur
		Point(); //defaut
		// Point(float const x, float const y); 
		Point(Point const & src); // copie
		~Point();
		
//  operator overload
		Point& operator=(Point const & fix); //operateur
};
#endif