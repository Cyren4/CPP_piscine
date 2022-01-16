#include "../includes/Bureaucrat.hpp"

int main()
{
    try{
        /* do some stuff with bureaucrats */
        Bureaucrat("Grezette", 180);
    } catch (std::exception & e){
        e.what();
        /* handle exception */
    }
}