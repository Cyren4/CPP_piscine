#include <iostream>
#include <locale>

char    *ft_toupper(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);
        i++;
    }
    return (str);
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
    while (i < ac)
    {
        std::cout << ft_toupper(av[i]) ;
        i++;
    }
    std::cout << std::endl;
    return (0);
}
