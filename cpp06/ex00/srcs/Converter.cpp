#include "../includes/Converter.hpp"

Converter::Converter():_literal("0"){}

Converter::Converter(char const *literal):
	_literal(literal)
{
	this->_type = this->getType();
	if (this->_type == NOT_TYPE)
		return ;
}

Converter::Converter(Converter const & src):
	_literal(src._literal)
{
	*this = src;
}

Converter::~Converter(){}

Converter&	Converter::operator=(Converter const & src){
	(void)src;
	if (this == &src)
		return *this;
	this->_charL = src._charL;
	this->_intL = src._intL;
	this->_floatL = src._floatL;
	this->_doubleL = src._doubleL;
	this->_type = src._type;
	return *this;
}

// 		//------- check _type 
bool     Converter::is_special(void) {
	const char *specF[4] = {"inff", "+inff", "-inff", "nanf"};
	const char *specD[4] = {"inf", "+inf", "-inf", "nan"};

	for (int i = 0; i < 4; i++)
	{
		if (strcmp(specF[i], this->_literal) == 0)
		{
			this->_floatL = static_cast<float>(atof(specF[i]));
			this->_type = FLOAT_TYPE;
			return true;
		} else if (strcmp(specD[i], this->_literal) == 0)
		{
			this->_doubleL = static_cast<double>(atof(specF[i]));
			this->_type = DOUBLE_TYPE;
			return true;
		}
	}
	return false;
}

bool     Converter::is_numeral(void) {
	int i = 0;
	this->_type = INT_TYPE;
	if (this->_literal[i] == '-')
		i++;
	while(this->_literal[i] && (isdigit(this->_literal[i]) || this->_literal[i] == '.'))
	{
		if (this->_literal[i] == '.')
			this->_type = DOUBLE_TYPE;
		i++;
	}
	if (this->_literal[i] == 'f' && this->_literal[i + 1] == '\0')
	{
		this->_type = FLOAT_TYPE;
		this->_floatL = static_cast<double>(strtod(this->_literal, NULL));
	}
	else if (this->_literal[i] != '\0')
		this->_type = NOT_TYPE;
	if (this->_type == INT_TYPE)
		this->_intL = strtol(this->_literal, NULL, 10);
	if (this->_type == DOUBLE_TYPE)
		this->_doubleL = static_cast<double>(strtod(this->_literal, NULL));
	return (this->_type != NOT_TYPE);
}

int	Converter::is_char(void) {
	if (this->_literal[0] != '\0' && this->_literal[1] == '\0')
	{
		this->_type = CHAR_TYPE;
		this->_charL = static_cast<char>(this->_literal[0]);
	}
	else 
		this->_type = NOT_TYPE;
	return this->_type;
}

int		Converter::getType(void) {
	if (this->is_special())
		return this->_type;
	if (this->is_numeral())
		return this->_type;
	return this->is_char();
}

const std::string     Converter::getLiteral(void) const{
	return this->_literal;
}
     
// 		//------- utils  function
bool Converter::inRange(double num, double bottom, double top) const
{
  return (num >= bottom && num <= top);
}

// 		//------- member  function
void	Converter::getChar(double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()))
			throw convertImpossibleException();
		if (!isprint(static_cast<int>(num))) 
			throw nonDisplayableException();	
		std::cout  << "'" << static_cast<char>(num)<< "'" << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl; 
	}
}

void		Converter::getInt(double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
			throw convertImpossibleException();	
		std::cout  << static_cast<int>(num) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl; 
	}
}

void		Converter::getFloat(double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<float>::min(), std::numeric_limits<float>::max()))
		{
			if (num < std::numeric_limits<float>::min())
				std::cout  << static_cast<float>(strtof("-inff", NULL)) << std::endl;
			else if (num > std::numeric_limits<float>::max())
				std::cout  << static_cast<float>(strtof("inff", NULL)) << std::endl;
			else
				std::cout  << static_cast<float>(strtof("nanf", NULL)) << std::endl;
		}
		else
			std::cout  << static_cast<float>(num) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl; 
	}
}

void		Converter::getDouble(double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<double>::min(), std::numeric_limits<double>::max()))
		{
			if (num < std::numeric_limits<double>::min())
				std::cout  << static_cast<double>(strtod("-inf", NULL)) << std::endl;
			else if (num > std::numeric_limits<double>::max())
				std::cout  << static_cast<double>(strtod("inf", NULL)) << std::endl;
			else
				std::cout  << static_cast<double>(strtod("nan", NULL)) << std::endl;
		}
		else
			std::cout  << static_cast<double>(num) << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl; 
	}
}


void		Converter::print(void) const{
	double	num;

	try{
		switch (this->_type)
		{
		case CHAR_TYPE:
			num =  static_cast<double>(this->_charL);
			break;
		case INT_TYPE:
			num =  static_cast<double>(this->_intL);
			break;
		case FLOAT_TYPE:
			num =  static_cast<double>(this->_floatL);
			break;
		case DOUBLE_TYPE:
			num =  static_cast<double>(this->_doubleL);
			break;
		default:
			// throw convertImpossibleException();
			num =  static_cast<double>(strtof("nan", NULL));
			break;
		}
	}catch (std::exception e) {
		std::cout << e.what(); 
	}
	std::cout << "char : ";
	this->getChar(num);
	std::cout << "int : ";
	this->getInt(num);
	std::cout <<  "float : " ;
	this->getFloat(num);
	std::cout << "double : ";
	this->getDouble(num);
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
