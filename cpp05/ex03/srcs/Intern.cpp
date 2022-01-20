#include "../includes/Intern.hpp"

const std::string	Intern::_knownForm[3] = {
	"shrubbery creation", 
	"robotomy request", 
	"presidential pardon"
};

Intern::Intern(){
	std::cout << "Intern just got hired, give him some work! "<< std::endl;
}

Intern::Intern(Intern const & src){
	std::cout << "Intern just got hired, give him some work! "<< std::endl;
	*this = src;
}

Intern::~Intern(){}

Intern&	Intern::operator=(Intern const & a){
	(void)a;
	return *this;
}

typedef	Form*	(Intern::*formType[3])(std::string& target) const;

Form*	Intern::makeForm(std::string& name, std::string& target){
	formType createF = {&Intern::shrubbery, &Intern::robotomy, &Intern::pardon};

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(_knownForm[i]) == 0)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*(createF[i]))(target);
		}
	}
	std::cout << name <<" form doesn't exist " << std::endl;
	throw unknownFormException();
	return NULL;
}

Form*	Intern::makeForm(const char* name, const char* target){
	std::string tmpName = name;
	std::string tmpTarget = target;
	return this->makeForm(tmpName, tmpTarget);
}

Form*	Intern::shrubbery(std::string& target) const
{
	Form *f = new ShrubberyCreationForm(target);
	return f;
}

Form*	Intern::robotomy(std::string& target) const
{
	Form *f = new RobotomyRequestForm(target);
	return f;
}

Form*	Intern::pardon(std::string& target) const
{
	Form *f = new PresidentialPardonForm(target);
	return f;
}

//------------Classe exception------------//

Intern::unknownFormException::unknownFormException(){}

const char* Intern::unknownFormException::what() const throw()
{
	return "Intern exception : this form is unknown";
}
