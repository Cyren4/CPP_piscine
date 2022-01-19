
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", 72, 45),
	_target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	Form("RobotomyRequestForm", 72, 45),
	_target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	(void)src;
	return *this;
}

//-----------Getters
const std::string	RobotomyRequestForm::getTarget(void) const{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & b)const{
	this->tryExecute(b);
	srand(time(NULL));
	std::cout << "DRILLLLLLLLL DRILLLLLLLLL" << std::endl; 	
	if (rand() % 100 < 50)
		std::cout << "<" << this->getName() << "> :" << this->_target << " has been robotomized successfully by " << b.getName() << std::endl;
	else
		std::cout << "<" << this->getName() << "> :" << this->_target << " has been robotomization by " << b.getName() << " failed" << std::endl;
}

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const & f){
	o << "<" << f.getName() << "> form needs grade " << f.getSignGrade() << " to be signed and grade "<< f.getExecGrade() << " to be executed" << std::endl;
	o << "Form status : ";
	if (f.getStatus())
		o << "Signed so you can request a robotomization of " << f.getTarget() << std::endl;
	else
		o << "Not signed, you need to sign it first before requesting a robotomization of " << f.getTarget() << std::endl;
	return o;
}