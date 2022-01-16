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
		if (src.learnedMateria[i] != NULL)
			this->learnedMateria[i] = src.learnedMateria[i]->clone(); 
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* mat){
	if (mat == NULL || mat->getAvailable() == false)
	{
		std::cout << mat->getType() << " already used" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMateria[i] == NULL)
		{
			mat->setAvailable(false);
			this->learnedMateria[i] = mat;
			return;
		}
	}
	std::cout << "MateriaSource is full you can't learn more materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
		if (this->learnedMateria[i] != NULL && type.compare(this->learnedMateria[i]->getType()) == 0)
		{
			AMateria* tmp = this->learnedMateria[i]->clone(); 
			tmp->setAvailable(true);
			return tmp;
		}
	std::cout << type << " : unknown materia" << std::endl;
	return NULL;
}
