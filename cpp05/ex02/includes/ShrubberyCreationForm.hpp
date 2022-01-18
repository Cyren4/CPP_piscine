#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"


class ShrubberyCreationForm{
    private:
        std::string const	_target;
        std::string const	asciiForest[3];
        void    writeTree(std::ostream& o);
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm&    operator=(ShrubberyCreationForm const & src);

// 		//------- member  function
		void	execute(Bureaucrat const & b);

};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const & bur); //operateur

#endif