#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <time.h> 
#include "Form.hpp"


class RobotomyRequestForm : public Form{
    private:
        std::string const	_target;
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm&    operator=(RobotomyRequestForm const & src);

// 		//------- getter
		const std::string     getTarget(void) const;
        
// 		//------- member  function
		void	execute(Bureaucrat const & b) const;

};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const & bur); //operateur

#endif