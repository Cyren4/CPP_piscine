#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"


class ShrubberyCreationForm{
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm&    operator=(ShrubberyCreationForm const & src);

// 		//------- member  function
		void	beExecuted(Bureaucrat & b);

};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const & bur); //operateur

#endif