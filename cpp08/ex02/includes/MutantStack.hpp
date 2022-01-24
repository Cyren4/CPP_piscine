#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(MutantStack const & src){
            *this = src;
        }
        ~MutantStack(){}

        MutantStack&    operator=(MutantStack const & src){
            *this = src;
            return *this;
        }

        typedef typename T::iterator
        // T*    easyfind(T & fp, int sp){
        //     typename T::iterator it = std::find(fp.begin(), fp.end(), sp);
        //     if (it == fp.end())
        //         throw notInContainerException();
        // return *it;
        // }

        <iterator> begin(){
            return this->begin();
        }
        <iterator> end(){
            return this->end();
        } 
};

#endif
