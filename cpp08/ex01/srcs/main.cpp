#include "../includes/Span.hpp"
#define SIZE_VECT 10000
#define RAND_LIM 1000000


int main()
{
    srand(time(NULL));
    {
        std::cout << "--------Test subject span --------" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "In  vector : ";
        sp.print_vect();
        std::cout << std::endl << "Shortest span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span = " << sp.longestSpan() << std::endl;
    }
    {
        std::cout << std::endl << "--------Test bigger Span --------" << std::endl;
        Span sp = Span(SIZE_VECT);

        for (int i = 0; i < SIZE_VECT; i++)
            sp.addNumber(rand() % RAND_LIM);

        std::cout << "In  vector  of size : "<< SIZE_VECT<< " with value from 0 to " << RAND_LIM << std::endl ;
        std::cout << "Shortest span = " <<  sp.shortestSpan() << std::endl;
        std::cout << "Longest span = " << sp.longestSpan() << std::endl;
    }
    return 0;
}
