#include <iostream>
#include <locale>

void    ft_toupper(char *str)
{
    int i = 0;

    while (str[i])
    {
        std::cout << static_cast<char>(toupper(str[i]));
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    while (i < ac)
    {
        ft_toupper(av[i]) ;
        i++;
    }
    std::cout << std::endl;
    return (0);
}
