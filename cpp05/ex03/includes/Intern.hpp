#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	private:
		static const std::string	_knownForm[3];
//	------- member function
		Form*	shrubbery(std::string& target)const;
		Form*	robotomy(std::string& target)const;
		Form*	pardon(std::string& target)const;
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern&	operator=(Intern const & a); 


		Form*	makeForm(std::string& name, std::string& target);
		Form*	makeForm(const char* name, const char* target);

//	------- Exception 
		class unknownFormException : public std::exception{
			public :
				unknownFormException();
				virtual const char * what () const throw ();
		};
};

#endif