#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("randomB"), _grade(10){}
Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name)
{
	if (grade < Bureaucrat::max)
		throw Bureaucrat::GradeTooHighException();
	if (grade >  Bureaucrat::min)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src._name){
	this->_grade = src._grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src){
	if (this != &src)
		this->_grade = src._grade;
	return  *this;
}
//------------Member function

void	Bureaucrat::signForm(Form & f){
	try{
		f.beSigned(*this);
		std::cout << "<"<< this->_name << "> signs <" << f.getName() << ">" << std::endl;
	}catch (std::exception & e){
		std::cout << "<"<< this->_name << "> cannot sign <" << f.getName() << "> because (" << e.what() << ")"<< std::endl;
	}
}
//------------Getter

const std::string     Bureaucrat::getName(void) const{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void	Bureaucrat::betterGrade() 
{
	if (this->_grade <= Bureaucrat::max)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::worseGrade() 
{
	if (this->_grade >= Bureaucrat::min)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const & bur){
	o << "<" <<bur.getName() << "> bureaucrat grade " << bur.getGrade();
	return o;
}

//------------Classe exception------------//

Bureaucrat::GradeTooHighException::GradeTooHighException(){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat exception : grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(){}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat exception : grade is too low";
}
