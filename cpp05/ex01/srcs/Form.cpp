#include "../includes/Form.hpp"

Form::Form():
	_name("random_form"),
	_sRequired(1),
	_xRequired(1),
	_signed(false)
{}

Form::Form(std::string name, int s_req, int x_req):
	_name(name),
	_sRequired(s_req),
	_xRequired(x_req),
	_signed(false)
{
	if (x_req < 1 || s_req  < 1)
		throw Form::GradeTooHighException();
	if (x_req > 150 || s_req  > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src):
	_name(src._name),
	_sRequired(src._sRequired),
	_xRequired(src._xRequired)
{
	*this = src;
}

Form::~Form(){}

Form&    Form::operator=(Form const & src){
	if(this != &src)
		this->_signed = src._signed;
	return *this;
}

//-----------Getters
const std::string	Form::getName(void) const{
	return (this->_name);
}

int	Form::getExecGrade(void) const{
	return (this->_xRequired);
}

int	Form::getSignGrade(void) const{
	return (this->_sRequired);
}

//----------Member Function
void	Form::beSigned(Bureaucrat const & b){
	if (b.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
}

//------------Classe exception------------//

Form::GradeTooHighException::GradeTooHighException(){}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form exception : grade is too high";
}

Form::GradeTooLowException::GradeTooLowException(){}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form exception : grade is too low";
}


std::ostream& operator<<(std::ostream& o, Form const & f){
	o << "<" << f.getName() << "> form needs grade " << f.getSignGrade() << " to be signed and grade "<< f.getExecGrade() << " to be executed";
	return o;
}
