#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>

class Converter{

	private:
		std::string const &literal;
		Converter();
	public:
		Converter(std::string literal);
		Converter(Converter const & src);
		~Converter();

		Converter&	operator=(Converter const & src);

// 		//------- getter
		const std::string     getLiteral(void) const;
        
// 		//------- member  function
		// void	execute(Converter const & b) const;

// 		//-------  Exception 
		// class openFileException : public std::exception{
		// 	public :
		// 		openFileException();
		// 		virtual const char * what () const throw ();
		// };

};

#endif