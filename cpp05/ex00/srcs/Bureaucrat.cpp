#include "../includes/Bureaucrat.hpp"

        // std::string const _name;
        // int _grade;

Bureaucrat::Bureaucrat(): _name("randomB"), _grade(10){}
Bureaucrat::Bureaucrat(std::string name, int grade) throw() :
	_name("randomB")
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src._name){
	this->_grade = src._grade;
}

Bureaucrat::~Bureaucrat(){}

std::string     Bureaucrat::getName(void) const{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void	Bureaucrat::betterGrade() throw(){
	if (this->_grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::worseGrade() throw(){
	if (this->_grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const & bur){
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return o;
}
