#include "../includes/easyfind.hpp"
#define SIZE_VECT 100
#define RAND_LIM 100

notInContainerException::notInContainerException(){}
const char * notInContainerException::what() const throw() {
    return "not in the list";
}

int main()
{
	std::vector<int>	v;
	int value;
	int tmp;

	srand(time(NULL));
	for (size_t i = 0; i < SIZE_VECT; i++)
    {
        tmp = rand() % RAND_LIM;
        std::cout << tmp << " ";
		v.push_back(tmp);
    }
	value = rand() % RAND_LIM;
	std::cout << std::endl << std::endl;


	std::cout << value << " : " ;
	try {
		::easyfind(v, value);
		std::cout << "in the list" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
