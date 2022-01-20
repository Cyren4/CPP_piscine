#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>

class Converter{

	private:
		std::string const & literal;
		char	charL; 
		int		intL; 
		float	floatL
		double	doubleL; 

		Converter();
	public:
		Converter(char const &literal);
		Converter(Converter const & src);
		~Converter();

		Converter&	operator=(Converter const & src);

// 		//------- getter
		const std::string     getLiteral(void) const;
        
// 		//------- member  function
		char 		getChar(void) const;
		int		getInt(void) const;
		float		getFloat(void) const;
		double	getDouble(void) const;

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