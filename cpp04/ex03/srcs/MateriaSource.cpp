#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src){
	*this = src;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		if (this->learnedMateria[i] != NULL)
			delete this->learnedMateria[i]; 
}

MateriaSource& MateriaSource::operator=(MateriaSource const & src){

	if (this == &src)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i] != NULL)
			delete this->learnedMateria[i];
		this->learnedMateria[i] = NULL;
		if (mat.learnedMateria[i] != NULL)
			this->learnedMateria[i] = mat.learnedMateria[i]->clone(); 
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* mat){
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i] == NULL)
		{
			this->learnedMateria[i] = mat->clone();
			return;
		}
	}
	std::cout << "MateriaSource is full you can't learn more materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
		if (type.compare(this->learnedMateria[i]->getType()) == 0)
			return this->learnedMateria[i]->clone(); 
	std::cout << type << " : unknown materia" << std::endl;
	return NULL;
}
