#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const & a); 

		std::string     getName(void) const;

		int     getGrade(void) const;
		void	betterGrade();
		void	worseGrade();

		class GradeTooHighException : public std::exception{
			private:
				static const int max = 1;
			public :
				GradeTooHighException(){}
				const char * what () const throw (){
					return "Bureaucrat exception : grade is too high";
				}
		};

		class GradeTooLowException : public std::exception{
			private:
				static const int max = 1;
			public :
				GradeTooLowException(){}
				const char * what () const throw (){
					return "Bureaucrat exception : grade is too low";
				}
		};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & bur); //operateur

#endif
