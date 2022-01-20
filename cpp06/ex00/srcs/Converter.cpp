#include "../includes/Converter.hpp"
		// std::string const &literal;

Converter::Converter():literal("0"){}

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
	(void)src;
	return *this;
}

// 		//------- getter
const std::string     Converter::getLiteral(void) const{
	return this->literal;
}
        
// 		//------- member  function
const std::string		Converter::getChar(void) const{
	std::string ret;	
	return ret;
}

const std::string		Converter::getInt(void) const{
	std::string ret;	
	return ret;
}

const std::string		Converter::getFloat(void) const{
	std::string ret;	
	return ret;
}

const std::string		Converter::getDouble(void) const{
	std::string ret;	
	return ret;
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
