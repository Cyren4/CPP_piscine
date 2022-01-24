#include "../includes/MutantStack.hpp"
#define RAND_LIM INT32_MAX

int main()
{
    {
        std::cout << "---Test sujet mutantStack" << std::endl;   
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite){
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "---Test sujet list" << std::endl;   
        std::list<int> mlist;

        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mlist);
    }
    {
        std::cout << std::endl << "---Deep test mutantStack" << std::endl;   
        MutantStack<int> mstack;

        int start = -12, stop = 60, step = 3;
        for (int i = start; i <= stop; i+= step)
            mstack.push(i);
        std::cout <<"Size of mutantStack : " << mstack.size() << std::endl;

        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
            std::cout << *it << std::endl;
        std::stack<int> s(mstack);
    }
    return 0;
}
