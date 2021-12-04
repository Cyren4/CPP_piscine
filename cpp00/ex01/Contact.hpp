#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>

class Contact
{

public:
	Contact(void);
	~Contact(void);
	void set_info(std::string info[5]);
	void print_info(void);
	void print_head(int i);
	// void set_info(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret);

private:
	std::string	_infos[5];
	// std::string _firstName;
	// std::string _lastName;
	// std::string _nickname;
	// std::string _phoneNb;
	// std::string _secret;
};

#endif