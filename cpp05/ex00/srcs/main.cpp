#include "../includes/Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat b1("Grezette1", 149);
		std::cout << b1;
		b1.worseGrade();
		Bureaucrat b3("Grezette3", 0);
	} catch (std::exception & e){
		std::cout << e.what();
	}
}