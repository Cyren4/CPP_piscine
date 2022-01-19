
#include "../includes/ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::asciiForest[2] = {
"          .     .  .      +     .      .          .			\n"  \
"     .       .      .     #       .           .				\n"  \
"        .      .         ###            .      .      .		\n"  \
"      .      .   \"#:. .:##\"##:. .:#\"  .      .					\n"  \
"          .      . \"####\"###\"####\"  .							\n"  \
"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .	\n"  \
"  .             \"#########\"#########\"        .        .		\n"  \
"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .			\n"  \
"     .     .  \"#######\"\"##\"##\"\"#######\"                  .		\n"  \
"                .\"##\"#####\"#####\"##\"           .      .		\n"  \
"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .			\n"  \
"      .     \"#######\"##\"#####\"##\"#######\"      .     .			\n"  \
"    .    .     \"#####\"\"#######\"\"#####\"    .      .				\n"  \
"            .     \"      000      \"    .     .					\n"  \
"       .         .   .   000     .        .       .			\n",
"    _\\/_		\n" \
"     /\\		\n" \
"     /\\		\n" \
"    /  \\		\n" \
"    /~~\\o		\n" \
"   /o   \\		\n" \
"  /~~*~~~\\	\n" \
" o/    o \\	\n" \
" /~~~~~~~~\\~`	\n" \
"/__*_______\\	\n" \
"     ||		\n" \
"   \\====/		\n" \
"    \\__/		\n" 
};


ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", 145, 137),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm", 145, 137),
	_target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	Form("ShrubberyCreationForm", 145, 137),
	_target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src){
	(void)src;
	return *this;
}

//-----------Getters
const std::string	ShrubberyCreationForm::getTarget(void) const{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & b)const{
	this->tryExecute(b);
	std::string file = this->_target + "_shrubbery";
	std::ofstream ofs(file);
	if (!ofs.is_open())
	{
		std::cout << "Can't open " << file << std::endl;
		throw openFileException();
		return ;
	}
	// this->writeTree(ofs);
	ofs << this->asciiForest[0] << this->asciiForest[1];
	ofs.close();
	std::cout << "<Shrubbery_Creation_Form> : " << this->getName() << " got executed by "<< b.getName() << std::endl;
}

//-------Exception

ShrubberyCreationForm::openFileException::openFileException(){}

const char* ShrubberyCreationForm::openFileException::what() const throw()
{
	return "<Shrubbery_Creation_Form> : couldn't open file and draw an ascii tree.";
}

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const & f){
	o << "<" << f.getName() << "> form needs grade " << f.getSignGrade() << " to be signed and grade "<< f.getExecGrade() << " to be executed" << std::endl;
	o << "Form status : ";
	if (f.getStatus())
		o << "Signed so you can plant a shruberry at " << f.getTarget() << std::endl;
	else
		o << "Not signed, you need to sign it first before plantinga shruberry at " << f.getTarget() << std::endl;
	return o;
}