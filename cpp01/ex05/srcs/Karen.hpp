#ifndef KAREN_H
#define KAREN_H

#include <iostream>
#include <fstream>
#include <string>


class Karen{
	public:
		Karen();
		~Karen();
		void    complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
