#include <iostream>

namespace bla = std; 
int main(void)
{
    char    buf[10];
    bla::cout << "Wsh alors" << bla::endl;
    std::cin >> buf;
    std::cout << buf << std::endl;
}