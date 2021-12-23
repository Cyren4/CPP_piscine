#include "Karen.hpp"

int main(int ac, char **av){
	if (ac != 4)
	{
		std::cout << "Error : Incorrect number of arguments" << std::endl << "Usage : <filename> <str1> <str2>" << std::endl;
		return (0);
	}
	std::string s1, s2;
	s1 = av[2];
	s2 = av[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error : str1 and str2 can't be empy string" << std::endl << "Usage : <filename> <str1> <str2>" << std::endl;
		return (0);
	}
	std::ifstream ifs(av[1]);
	if (!ifs)
	{
		std::cout << "Error : Can't open " << av[1] << std::endl;
		return (0);
	}
	std::string tmp;
	std::string file = av[1];
	file +=  ".replace";
	std::ofstream ofs(file);
	size_t i = 0;
	while (std::getline(ifs, tmp))
	{
		while (tmp[i] != '\0')
		{
			if (tmp.compare(i, s1.length(), s1) == 0)
			{
				ofs << s2;
				i += s1.length();
				continue ;
			}
			else
				ofs << tmp[i];
			i++;
		}
	}
	ifs.close();
	ofs.close();
	return(0);
}	