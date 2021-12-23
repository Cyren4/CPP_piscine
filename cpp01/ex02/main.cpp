#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "address of str : " << &str << std::endl;
    std::cout << "address of stringPTR : " << stringPTR << std::endl;
    std::cout << "address of stringREF : " << &stringREF << std::endl << std::endl;

    std::cout << "str from stringPTR : " << *stringPTR << std::endl;
    std::cout << "str from stringREF : " << stringREF << std::endl;
    return (0);
}