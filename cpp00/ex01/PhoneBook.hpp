#ifndef  PHONEBOOK_CLASS_H
# define  PHONEBOOK_CLASS_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook{

public:
    PhoneBook(void);
    ~PhoneBook(void);

private:
    Contact (*_nul)[8];

    // Contact hello;
    // contact[1] = &(hello);

};

#endif