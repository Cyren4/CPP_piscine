#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain{
	private:
		std::string _ideas[100];
		int _nbideas;
	public:
		Brain();
		Brain(std::string ideas);
		Brain(Brain const & src);
		~Brain();

		Brain& operator=(Brain const & a);
		
		void	addIdea(std::string idea);
		void	showIdeas(void) const;
		std::string	*getIdeas(void);
};

#endif