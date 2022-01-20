#include "../includes/Converter.hpp"
		// std::string const &literal;

Converter::Converter():literal(""){}

Converter::Converter(std::string literal):
	literal(literal)
{}

Converter::Converter(Converter const & src):
	literal(src.literal)
{
	*this = src;
}

Converter::~Converter(){}

Converter&	Converter::operator=(Converter const & src){
	return *this;
}

// 		//------- getter
const std::string     Converter::getLiteral(void) const{
	return this->literal;
}
        
// 		//------- member  function
		// void	execute(Converter const & b) const;

// 		//-------  Exception 
		// class openFileException : public std::exception{
		// 	public :
		// 		openFileException();
		// 		virtual const char * what () const throw ();
		// };
