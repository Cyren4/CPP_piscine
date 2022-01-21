#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstring>
// #include <limits>

#define	NOT_TYPE 0
#define	CHAR_TYPE 1
#define	INT_TYPE 2
#define	FLOAT_TYPE 3
#define	DOUBLE_TYPE 4

class Converter{

	private:
		char const * _literal;

		char		_charL; 
		long int	_intL; 
		float		_floatL;
		double	_doubleL; 
		int			_type;

		Converter();
// ------- utils member  function
		bool inRange(double num, double bottom, double top) const;
 		//get type 
		bool	is_special(void);
		bool	is_numeral(void);
		int		is_char(void);
		int		getType(void);
 		// convert 
	public:
		Converter(char const *literal);
		Converter(Converter const & src);
		~Converter();

		Converter&	operator=(Converter const & src);

// 		//------- getter
		const std::string     getLiteral(void) const;
        
// 		//------- member  function
		void	getChar(double num) const;
		void	getInt(double num) const;
		void	getFloat(double num) const;
		void	getDouble(double num) const;

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
