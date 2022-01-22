#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <stdlib.h>     
#include <time.h> 

Base::~Base(){}

Base*	generate(void){
	srand(time(NULL));
	int num = rand() % 90 + 1;
	if (num < 30)
		return new A;
	else if (num < 60)
		return new B;
	else
		return new C;
}

void	identify(Base *p){
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
	else
		std::cout << "unknown";
}
void	identify(Base &p){
	try{
		A &tmp = dynamic_cast<A&>(p);
		std::cout << "A";
		(void)tmp;
	}catch (std::exception & e){
		// std::cout << "not A" << std::endl;
	}
	try{
		B &tmp = dynamic_cast<B&>(p);
		std::cout << "B";
		(void)tmp;
	}catch (std::exception & e){
		// std::cout << "not B" << std::endl;
	}
	try{
		C &tmp = dynamic_cast<C&>(p);
		std::cout << "C";
		(void)tmp;
	}catch (std::exception & e){
		// std::cout << "not C" << std::endl;
	}

}

int	main(){
	Base* tmp;
	for (int i = 0; i < 1; i++)
	{
		tmp = generate();
		std::cout << i << " - Test pointer : \t" ;
		identify(tmp);
		std::cout << std::endl;
		std::cout  << i << " - Test reference : \t";
		identify(*tmp);
		std::cout << std::endl;
		delete tmp;
	}
	return 0;
}
