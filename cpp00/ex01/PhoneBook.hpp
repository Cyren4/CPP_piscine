#ifndef  PHONEBOOK_CLASS_H
# define  PHONEBOOK_CLASS_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook{

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    add_contact(void);
    void    search(void);
    void    print_list_contact(void);
    void    print_contact(int index);

private:
    Contact _contact[8];
    static int  _nb_contact;

    // Contact hello;
    // contact[1] = &(hello);

};

#endif