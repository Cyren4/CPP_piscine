#include "../includes/Brain.hpp"

Brain::Brain(){
	std::cout << "Brain - default constructor called" << std::endl;
	this->_nbideas = 0;
}

Brain::Brain(std::string idea){
	std::cout << "Brain - constructor called" << std::endl;
	this->_nbideas = 0;

	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = idea;
		this->_nbideas++;
	}
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain - copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(){
	std::cout << "Brain - destructor called" << std::endl;
}

void	Brain::addIdea(std::string idea)
{
	if (this->_nbideas == 100)
		std::cout << "This brain is full of thoughs you can add any more ideas!"<<std::endl;
	else
	{
		this->_ideas[this->_nbideas] = idea;
		this->_nbideas++;
	}
}

void	Brain::showIdeas(void) const
{
	if (this->_nbideas == 0)
	{
		std::cout << "This brain is empty so there is nothing to show!"<<std::endl;
		return ;
	}
	for (int i = 0; i < this->_nbideas; i++)
		std::cout << this->_ideas[i] << std::endl;
}

std::string	*Brain::getIdeas(void){
	return this->_ideas;
}

Brain& Brain::operator=(Brain const & b){
	if (this != &b)
		for (int i = 0; i < b._nbideas; i++)
			this->_ideas[i] = b._ideas[i];
	return *this;
}