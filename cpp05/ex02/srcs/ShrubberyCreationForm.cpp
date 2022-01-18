
#include "../includes/ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::asciiForest[3] = {
'          .     .  .      +     .      .          .' \
'     .       .      .     #       .           .' \
'        .      .         ###            .      .      .' \
'      .      .   "#:. .:##"##:. .:#"  .      .' \
'          .      . "####"###"####"  .' \
'       .     "#:.    .:#"###"#:.    .:#"  .        .       .' \
'  .             "#########"#########"        .        .' \
'        .    "#:.  "####"###"####"  .:#"   .       .' \
'     .     .  "#######""##"##""#######"                  .' \
'                ."##"#####"#####"##"           .      .' \
'    .   "#:. ...  .:##"###"###"##:.  ... .:#"     .' \
'      .     "#######"##"#####"##"#######"      .     .' \
'    .    .     "#####""#######""#####"    .      .' \
'            .     "      000      "    .     .' \
'       .         .   .   000     .        .       .',
'    _\\/_'
'     /\\'
'     /\\'
'    /  \\'
'    /~~\\o'
'   /o   \\'
'  /~~*~~~\\'
' o/    o \\'
' /~~~~~~~~\\~`'
'/__*_______\\'
'     ||'
'   \\====/'
'    \\__/'
};


ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", 145, 137),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm", 145, 137);
	_target(target)
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

void    ShrubberyCreationForm::writeTree(std::ostream& o){

}

void	ShrubberyCreationForm::execute(Bureaucrat & b){
	if (this->_signed == false)
		throw notSignedException();
	if (b.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::string file = this->_target + "_shrubbery";
	std::ofstream ofs(file);
	if (!ofs.is_open(file))
	{
		std::cout << "Error : Can't open " << file << std::endl;
		std::cout << "<Shrubbery_Creation_Form> : couldn't draw an Ascii tree." << std::endl;
		return ;
	}
	this->writeTree(ofs);
	ofs.close();
	std::cout << "<Shrubbery_Creation_Form> : " << this->_name << "got executed." << std::endl;
}
