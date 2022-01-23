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
        unsigned int _nbElem;
        void    isSpan();
    public:
        Span();
        Span(unsigned int N);
        Span(Span const & src);
        ~Span();

        Span& operator=(Span const & src);

        //member function
        void    addNumber(int num);
        void    addNumber(std::vector<int>  newElements);
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
