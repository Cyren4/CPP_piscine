#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span{
    private:
        std::vector<int>  _myvector;

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

        //  Exception
        class fullSpanException : public std::exception{
			private:
				static const int max = 1;
			public :
				fullSpanException();
				virtual const char * what () const throw ();
		};

        class noSpanException : public std::exception{
			private:
				static const int max = 1;
			public :
				noSpanException();
				virtual const char * what () const throw ();
		};
};

#endif
