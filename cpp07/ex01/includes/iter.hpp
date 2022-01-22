#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename U>
void	iter(const T *a, const U & len, void (&func)(const T&)){
	for (U i = 0; i < len; i++)
		(func)(a[i]);
}


#endif
