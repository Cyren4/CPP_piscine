#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"


class ShrubberyCreationForm : public Form{
    private:
        std::string const	_target;
        std::string	static const asciiForest[2];
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm&    operator=(ShrubberyCreationForm const & src);

// 		//------- getter
		const std::string     getTarget(void) const;
        
// 		//------- member  function
		void	execute(Bureaucrat const & b) const;

// 		//-------  Exception 
		class openFileException : public std::exception{
			public :
				openFileException();
				virtual const char * what () const throw ();
		};
};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const & bur); //operateur

#endif