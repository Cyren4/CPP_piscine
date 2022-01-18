
#include "../includes/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():
	Form("default_shrubbery", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):
	Form(name + "_shrubbery", 145, 137)
{}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src){
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src){
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}
