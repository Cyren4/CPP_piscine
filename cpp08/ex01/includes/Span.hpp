#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

class Span{
    private:
        std::vector<int>  _myvector;
        unsigned int _maxSize;

        void    isSpan();
    public:
        Span();
        Span(unsigned int N);
        Span(Span const & src);
        ~Span();

        Span& operator=(Span const & src);

        //member function
        void    addNumber(int num);
        void    addNumbers(std::vector<int>  newElements);
        void    addNumRand(int nbElem, int maxVal);
        void    addNumRange(int from, int to, int step);
        int     shortestSpan();
        int     longestSpan();
        void    print_vect();

        //  Exception
        class fullSpanException : public std::exception{
			public :
				fullSpanException();
				virtual const char * what () const throw ();
		};

        class noSpanException : public std::exception{
			public :
				noSpanException();
				virtual const char * what () const throw ();
		};
};

#endif
