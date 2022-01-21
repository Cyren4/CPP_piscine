#include "../includes/Converter.hpp"

Converter::Converter():literal("0"){}

Converter::Converter(char const *literal):
	literal(literal)
{
	this->type = this->getType();

}

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
bool     Converter::check_special(void) {

}
int     Converter::getType(void) {
	if (this->check_special())
		return this->type;
	return NOT_TYPE;
}
const std::string     Converter::getLiteral(void) const{
	return this->literal;
}
        
// 		//------- member  function
void		Converter::getChar(void) const{
	if (this->type == NOT_TYPE)
		throw convertImpossibleException();
}

void		Converter::getInt(void) const{
	if (this->type == NOT_TYPE)
		throw convertImpossibleException();
}

void		Converter::getFloat(void) const{

	if (this->type == NOT_TYPE)
		throw convertImpossibleException();
}

void		Converter::getDouble(void) const{
	if (this->type == NOT_TYPE)
		throw convertImpossibleException();
}


void		Converter::print(void) const{
	std::cout << "char : "; 
	try{
		this->getChar();
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "int : ";
	try{
		this->getInt();
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl <<  "float : " ;
	try{
		this->getFloat();
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "double : ";
	try{
		this->getDouble();
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
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