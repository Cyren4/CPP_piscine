#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack(){}
        MutantStack(MutantStack const & src){
            *this = src;
        }
        ~MutantStack(){}

        MutantStack&    operator=(MutantStack const & src){
            (void);
            return src;
        }

        T* begin(){
            return this->top();
        }
        T* end(){
            return this->;
        } 
};

#endif