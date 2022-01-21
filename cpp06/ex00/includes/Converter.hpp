#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cfloat>

#define	NOT_TYPE 0
#define	CHAR_TYPE 1
#define	INT_TYPE 2
#define	FLOAT_TYPE 3
#define	DOUBLE_TYPE 4

class Converter{

	private:
		char const * literal;
		char	charL; 
		long int		intL; 
		float	floatL;
		long double	doubleL; 
		int	type;

		Converter();
// 		//------- utils member  function
		bool	check_special(void);
		int	getType(void);
	public:
		Converter(char const *literal);
		Converter(Converter const & src);
		~Converter();

		Converter&	operator=(Converter const & src);

// 		//------- getter
		const std::string     getLiteral(void) const;
        
// 		//------- member  function
		void	getChar(void) const;
		void	getInt(void) const;
		void	getFloat(void) const;
		void	getDouble(void) const;

		void	print(void) const;

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

#endif