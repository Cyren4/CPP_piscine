/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:02:40 by cramdani          #+#    #+#             */
/*   Updated: 2021/11/29 00:11:33 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Phonebook was created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Phonebook was destroyed" << std::endl;
	return ;
}