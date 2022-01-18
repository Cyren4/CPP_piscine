#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const & a); 

		//------- member  function
		void	signForm(Form const & b);
		void	betterGrade();
		void	worseGrade();

		//-------getter
		const std::string     getName(void) const;
		int     getGrade(void) const;

		class GradeTooHighException : public std::exception{
			public :
				GradeTooHighException();
				virtual const char * what () const throw ();
		};

		class GradeTooLowException : public std::exception{
			public :
				GradeTooLowException();
				virtual const char * what () const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & bur); //operateur

#endif
