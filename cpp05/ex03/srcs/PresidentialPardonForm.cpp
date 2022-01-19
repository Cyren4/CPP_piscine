
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("PresidentialPardonForm", 25, 5),
	_target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	Form("PresidentialPardonForm", 25, 5),
	_target(src.getTarget())
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm&    PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
	(void)src;
	return *this;
}

//-----------Getters
const std::string	PresidentialPardonForm::getTarget(void) const{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & b)const{
	this->tryExecute(b);
	std::cout << "<" << this->getName() << "> : " << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const & f){
	o << "<" << f.getName() << "> form needs grade " << f.getSignGrade() << " to be signed and grade "<< f.getExecGrade() << " to be executed" << std::endl;
	o << "Form status : ";
	if (f.getStatus())
		o << "Signed so you can request a presidential pardon" << std::endl;
	else
		o << "Not signed, you need to sign it first before requesting a presidential pardon " << std::endl;
	return o;
}