#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
	Bureaucrat b1("Grezette", 149);
	Bureaucrat b2("Zafod", 2);
	std::cout << "----Test exception too low----" << std::endl;
	try{
		std::cout << b1.getName() << " is the first bureaucrat with a grade of : " <<b1.getGrade() << std::endl;
		std::cout << b1 << std::endl;
		b1.worseGrade();
		std::cout << b1  << std::endl;
		b1.worseGrade();
		std::cout << b1  << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Test exception too high----" << std::endl;
	try{
		std::cout << b2.getName() << " is the second bureaucrat with a grade of : " <<b2.getGrade() << std::endl;
		std::cout << b2  << std::endl;
		b2.betterGrade();
		std::cout << b2  << std::endl;
		b2.betterGrade();
		std::cout << b2  << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	{
		std::cout << std::endl << "----Test ShrubberyCreationForm form----" << std::endl;
		Form *f1 = new ShrubberyCreationForm("home");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		delete f1;
	}
	{
		std::cout << std::endl << "----Test RobotomyRequestForm form----" << std::endl;
		Form *f1 = new RobotomyRequestForm("elevator");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		delete f1;
	}
	{
		std::cout << std::endl << "----Test PresidentialPardonForm form----" << std::endl;
		Form *f1 = new PresidentialPardonForm("Grezette");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		delete f1;
	}
	{
		std::cout << std::endl << "----Test Intern ----" << std::endl;
		Intern someRandomIntern;
		Form* rrf;
		Form* scf;
		Form* ppf;
		std::cout << std::endl << "----robotomy request test----" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b2.signForm(*rrf);
		b2.executeForm(*rrf);
		std::cout << std::endl << "----shrubbery creation test----" << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		b2.signForm(*scf);
		b2.executeForm(*scf);
		std::cout << std::endl << "----presidential pardon test ----" << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "grezette");
		b2.signForm(*ppf);
		b2.executeForm(*ppf);
		delete rrf;
		delete scf;
		delete ppf;
	}
}