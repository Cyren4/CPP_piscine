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

		static const int max = 1;
		static const int min = 150;
    public:
        Form();
		Form(std::string name, int s_req, int x_req);
        Form(Form const & src);
        virtual ~Form();

        Form&    operator=(Form const & src);

		//------- member  function
		void	beSigned(Bureaucrat const & b);
		virtual void	execute(Bureaucrat const & b) const = 0;
		virtual void	tryExecute(Bureaucrat const & b) const;

		//-------getter
		const std::string     getName(void) const;
		int		getExecGrade()const;
		int		getSignGrade()const;
		bool	getStatus()const;

//--------Exceptions 
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

		class notSignedException : public std::exception{
			public :
				notSignedException();
				virtual const char * what () const throw ();
		};

		class alreadySignedException : public std::exception{
			public :
				alreadySignedException();
				virtual const char * what () const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, Form const & bur); //operateur

#endif