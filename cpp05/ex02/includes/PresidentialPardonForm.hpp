#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"


class PresidentialPardonForm : public Form{
    private:
        std::string const	_target;
    public:
        PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm&    operator=(PresidentialPardonForm const & src);

// 		//------- getter
		const std::string     getTarget(void) const;
        
// 		//------- member  function
		void	execute(Bureaucrat const & b) const;

};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const & bur); //operateur

#endif