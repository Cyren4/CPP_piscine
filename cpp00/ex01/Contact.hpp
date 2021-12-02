#ifndef  CONTACT_CLASS_H
# define  CONTACT_CLASS_H

#include <iostream>

class Contact{

public:
    Contact();
    Contact(const std::string fname, const std::string lname, std::string nname,std::string phone,std::string secret);
    ~Contact(void);
    
private:
    const std::string   _firstName;
    const std::string   _lastName;
    std::string         _nickname;
    std::string         _phoneNb;
    std::string         _secret;
};

#endif