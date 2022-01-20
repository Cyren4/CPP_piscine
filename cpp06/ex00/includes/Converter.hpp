#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>

class Converter{

	private:
		std::string const literal;
		std::string const charL;
		std::string const intL;
		std::string const floatL;
		std::string const doubleL;
		Converter();
		// void* getChar(void) const;
	public:
		Converter(std::string literal);
		Converter(Converter const & src);
		~Converter();

		Converter&	operator=(Converter const & src);

// 		//------- getter
		const std::string     getLiteral(void) const;
        
// 		//------- member  function
		const std::string		getChar(void) const;
		const std::string		getInt(void) const;
		const std::string		getFloat(void) const;
		const std::string		getDouble(void) const;

// 		//-------  Exception 
		class convertImpossibleException : public std::exception{
			public :
				convertImpossibleException();
				virtual const char * what () const throw ();
		};

		class nonDisplayableException : public std::exception{
			public :
				nonDisplayableException();
				virtual const char * what () const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, Converter const & bur); //operateur

#endif