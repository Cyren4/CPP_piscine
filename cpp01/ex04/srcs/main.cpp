#include <iostream>
#include <fstream>
#include <string>

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
	if (!ifs.is_open())
	{
		std::cout << "Error : Can't open " << av[1] << std::endl;
		return (0);
	}
	std::string tmp, cat;
	std::string file = av[1];
	file +=  ".replace";
	std::ofstream ofs(file);
	if (!ofs.is_open())
	{
		std::cout << "Error : Can't open " << file << std::endl;
		ifs.close();
		return (0);
	}
	while (std::getline(ifs, tmp))
		cat += tmp + "\n" ;
	size_t i = 0;
	while (cat[i] != '\0')
	{
		if (cat.compare(i, s1.length(), s1) == 0)
		{
			ofs << s2;
			i += s1.length();
			continue ;
		}
		else
			ofs << cat[i];
		i++;
	}
	ifs.close();
	ofs.close();
	return(0);
}	