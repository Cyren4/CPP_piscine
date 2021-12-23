#include "Karen.hpp"

Karen::Karen(){
	std::cout << "A wild Karen appeared be careful!" << std::endl;
}
Karen::~Karen(){
	std::cout << "Yeay Karen just died!" << std::endl;
}

typedef	void	(Karen::*lvlPtr[4])(void);

void    Karen::complain(std::string level){
	std::string const lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};	
	lvlPtr bark = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(lvl[i]) == 0)
		{
			(this->*(bark[i]))();
			return ;
		}
	}
	std::cout << "Such a level doesn't exists yet you fool" << std::endl;
}

void    Karen::debug(void)
{
	std::cout << "<DEBUG> I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}
void    Karen::info(void)
{
	std::cout << "<INFO> I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}
void    Karen::warning(void)
{
	std::cout << "<WARNING> I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Karen::error(void)
{
	std::cout << "<ERROR> This is unacceptable, I want to speak to the manager now." << std::endl;
}
