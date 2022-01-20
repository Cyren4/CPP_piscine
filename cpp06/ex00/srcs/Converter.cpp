#include "../includes/Converter.hpp"

Converter::Converter():literal("0"){}

Converter::Converter(char const & literal):
	literal(literal)
{}

Converter::Converter(Converter const & src):
	literal(src.literal)
{
	*this = src;
}

Converter::~Converter(){}

Converter&	Converter::operator=(Converter const & src){
	(void)src;
	return *this;
}

// 		//------- getter
const std::string     Converter::getLiteral(void) const{
	return this->literal;
}
        
// 		//------- member  function
char		Converter::getChar(void) const{
	std::string ret;	
	return *static_cast<char>(this->literal.c_str()));
}

int		Converter::getInt(void) const{
	return static_cast<char>(this->literal);
}

float		Converter::getFloat(void) const{
	return static_cast<char>(this->literal);
}

double		Converter::getDouble(void) const{
	return static_cast<char>(this->literal);
}

// 		//-------  Exception 

Converter::convertImpossibleException::convertImpossibleException(){}

const char* Converter::convertImpossibleException::what() const throw()
{
	return "impossible";
}

Converter::nonDisplayableException::nonDisplayableException(){}

const char* Converter::nonDisplayableException::what() const throw()
{
	return "Non displayable";
}

std::ostream& operator<<(std::ostream& o, Converter const & c){
	o << "char : "; 
	try{
		o << c.getChar() << std::endl;
	} catch (std::exception & e){
		o << e.what() << std::endl;
	}
	o << "int : ";
	try{
		o << c.getInt() << std::endl;
	} catch (std::exception & e){
		o << e.what() << std::endl;
	}
	o << "float : " ;
	try{
		o << c.getFloat() << std::endl;
	} catch (std::exception & e){
		o << e.what() << std::endl;
	}
	o << "double : ";
	try{
		o << c.getDouble() << std::endl;
	} catch (std::exception & e){
		o << e.what() << std::endl;
	}
	return o;
}
