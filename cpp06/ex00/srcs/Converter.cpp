#include "../includes/Converter.hpp"

Converter::Converter():_literal("0"){}

Converter::Converter(char const *literal):
	_literal(literal), _value(0)
{
	this->_type = this->getType();
	if (this->_type == NOT_TYPE)
		this->_value = static_cast<long double>(strtold("nan", NULL));
	else if (this->_type == CHAR_TYPE) 
		this->_value = static_cast<long double>(this->_literal[0]);
	else
		this->_value = static_cast<long double>(strtold(this->_literal, NULL));
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
			this->_floatL = static_cast<float>(strtof(specF[i], NULL));
			this->_type = FLOAT_TYPE;
			return true;
		} else if (strcmp(specD[i], this->_literal) == 0)
		{
			this->_doubleL = static_cast<double>(strtod(specD[i], NULL));
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
		this->_doubleL = static_cast<long double>(strtold(this->_literal, NULL));
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
	else if (this->is_numeral())
		return this->_type;
	return this->is_char();
}

const std::string     Converter::getLiteral(void) const{
	return this->_literal;
}
     
// 		//------- utils  function
bool Converter::inRange(long double num, double bottom, double top) const
{
	// std::cout << std::endl << num <<std::endl;
	// std::cout << bottom <<std::endl;
	// std::cout << top <<std::endl;
	return (num >= bottom && num <= top);
}

// 		//------- member  function
void	Converter::getChar(long double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max()))
			throw convertImpossibleException();
		int tmp = static_cast<int>(num);
		if (!isprint(static_cast<int>(tmp))) 
			throw nonDisplayableException();	
		std::cout  << "'" << static_cast<char>(tmp)<< "'";
	} catch (std::exception & e) {
		std::cout << e.what(); 
	}
	std::cout << std::endl;
}

void		Converter::getInt(long double num) const{
	try{
		if (!this->inRange(num, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
			throw convertImpossibleException();	
		std::cout << static_cast<int>(num);
	} catch (std::exception & e) {
		std::cout << e.what(); 
	}
	std::cout << std::endl;
}

void		Converter::getFloat(long double num) const{
	try{
		if (!this->inRange(num, -std::numeric_limits<float>::max(), std::numeric_limits<float>::max()))
		{
			if (num < std::numeric_limits<float>::min())
				std::cout  << static_cast<float>(strtof("-inf", NULL));
			else if (num > std::numeric_limits<float>::max())
				std::cout  << static_cast<float>(strtof("inf", NULL));
			else
				std::cout  << static_cast<float>(strtof("nan", NULL)); 
		}
		else
			std::cout  << static_cast<float>(num);
		if (this->_type == INT_TYPE || this->_type == CHAR_TYPE || (num - floor(num) == 0))
			std::cout << ".0";
	} catch (std::exception & e) {
		std::cout << e.what(); 
	}
	std::cout << "f" << std::endl;
}

void		Converter::getDouble(long double num) const{
	try{
		if (!this->inRange(num, -std::numeric_limits<double>::max(), std::numeric_limits<double>::max()))
		{
			if (num < 0)
				std::cout  << static_cast<double>(strtod("-inf", NULL));
			else if (num > 0)
				std::cout  << static_cast<double>(strtod("inf", NULL));
			else
				std::cout  << static_cast<double>(strtod("nan", NULL));
		}
		else{
			std::cout  << static_cast<double>(num);
			if (this->_type == INT_TYPE || this->_type == CHAR_TYPE || (num - floor(num) == 0))
				std::cout << ".0";
		}
	} catch (std::exception & e) {
		std::cout << e.what(); 
	}
	std::cout << std::endl;
}


void		Converter::print(void) const{
	std::cout << "char : ";
	this->getChar(this->_value);
	std::cout << "int : ";
	this->getInt(this->_value);
	std::cout <<  "float : " ;
	this->getFloat(this->_value);
	std::cout << "double : ";
	this->getDouble(this->_value);
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
