#include "../includes/Form.hpp"

Form::Form():
	_name("random_form"),
	_sRequired(Form::min),
	_xRequired(Form::min),
	_signed(false)
{}

Form::Form(std::string name, int s_req, int x_req):
	_name(name),
	_sRequired(s_req),
	_xRequired(x_req),
	_signed(false)
{
	if (x_req < Form::max || s_req  < Form::max)
		throw Form::GradeTooHighException();
	if (x_req > Form::min || s_req  > Form::min)
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

bool	Form::getStatus(void) const{
	return (this->_signed);
}

//----------Member Function
void	Form::beSigned(Bureaucrat const & b){
	if (this->_signed)
		throw alreadySignedException();
	if (b.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
}

void	Form::tryExecute(Bureaucrat const & b) const{
	if (this->_signed == false)
		throw notSignedException();
	if (b.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "<" << this->_name << "> : is allowed to be executed." << std::endl;
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

Form::alreadySignedException::alreadySignedException(){}

const char* Form::alreadySignedException::what() const throw()
{
	return "Form exception : cannot sign an already signed form";
}

Form::notSignedException::notSignedException(){}

const char* Form::notSignedException::what() const throw()
{
	return "Form exception : unsigned form can't be executed";
}

std::ostream& operator<<(std::ostream& o, Form const & f){
	o << "<" << f.getName() << "> form needs grade " << f.getSignGrade() << " to be signed and grade "<< f.getExecGrade() << " to be executed" << std::endl;
	o << "Form status : ";
	if (f.getStatus())
		o << "Signed" << std::endl;
	else
		o << "Not signed" << std::endl;
	return o;
}