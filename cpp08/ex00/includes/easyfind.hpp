#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>

class notInContainerException : public std::exception{
	public :
		notInContainerException();
		virtual const char * what () const throw ();
};

template<typename T>
int    easyfind(T & fp, int sp){
    typename T::iterator it = std::find(fp.begin(), fp.end(), sp);
    if (it == fp.end())
        throw notInContainerException();
    return *it;
}





#endif
