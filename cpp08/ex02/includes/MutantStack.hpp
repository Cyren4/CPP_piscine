#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack() : std::stack<T>(){}
        MutantStack(MutantStack<T> const & src){
            *this = src;
        }
        ~MutantStack(){}

        MutantStack<T>&    operator=(MutantStack<T> const & src){
            if (this != &src)
                this->c = src.c;
            return *this;
        }


        iterator    begin(){
            return this->c.begin();
        }
        iterator    end(){
            return this->c.end();
        } 
 
        const_iterator    cbegin(){
            return this->c.cbegin();
        }
        const_iterator    cend(){
            return this->c.cend();
        }       
        
        reverse_iterator    rbegin(){
            return this->c.rbegin();
        }

        reverse_iterator    rend(){
            return this->c.rend();
        }
        
        const_reverse_iterator    crbegin(){
            return this->c.crbegin();
        }

        reverse_iterator    crend(){
            return this->c.crend();
        }  
};

#endif
