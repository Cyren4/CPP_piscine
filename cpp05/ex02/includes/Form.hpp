#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        std::string const	_name;
        int const			_sRequired;//grade to sign
        int const			_xRequired;//grade to execute
        bool				_signed;
    public:
        Form();
		Form(std::string name, int s_req, int x_req);
        Form(Form const & src);
        ~Form();

        Form&    operator=(Form const & src);

		//------- member  function
		void	beSigned(Bureaucrat const & b);
		virtual void	execute(Bureaucrat const & b);

		//-------getter
		const std::string     getName(void) const;
		int	getExecGrade()const;
		int	getSignGrade()const;

//--------Exceptions 
		class GradeTooHighException : public std::exception{
			private:
				static const int max = 1;
			public :
				GradeTooHighException();
				virtual const char * what () const throw ();
		};


		class GradeTooLowException : public std::exception{
			private:
				static const int max = 1;
			public :
				GradeTooLowException();
				virtual const char * what () const throw ();
		};

		class notSignedException : public std::exception{
			private:
				static const int max = 1;
			public :
				notSignedException();
				virtual const char * what () const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, Form const & bur); //operateur

#endif