/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malak <malak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:58:43 by malak             #+#    #+#             */
/*   Updated: 2025/11/01 01:19:36 by malak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
}

void PhoneBook::addContact()
{
    if (index >= 8)
        index %= 8;   
    std::cout << "Enter first name: " << std::endl;
    contacts[index].add_name(first);
    std::cout << "Enter last name: " << std::endl;
    contacts[index].add_name(last);
    std::cout << "Enter nickname: " << std::endl;
    contacts[index].add_name(nick);
    std::cout << "Enter phone number: " << std::endl;
    contacts[index].add_phone_number();
    std::cout << "Enter darkest secret: " << std::endl;
    contacts[index].add_darkest_secret();
    index++;
}

void PhoneBook::searchContacts()
{
    if (index == 0)
    {
        std::cout << "Phonebook is empty. Please add contacts first." << std::endl;
        return;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < index; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i + 1;
        check_and_replace(contacts[i].get_first_name());
        printCol(contacts[i].get_first_name());
        check_and_replace(contacts[i].get_last_name());
        printCol(contacts[i].get_last_name());
        check_and_replace(contacts[i].get_nickname());
        printCol(contacts[i].get_nickname());
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Enter the index of the contact to display: " << std::endl;
    check_and_display();
}

void PhoneBook::printCol(std::string str)
{
    std::cout << "|" << std::setw(10) << std::right << str;
}
void PhoneBook::check_and_replace(std::string& str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9) + ".";
    }
}

void PhoneBook::check_and_display()
{
    int input;
    while (1)
    {
        if (!(std::cin >> input))
        {
            if(std::cin.eof())
                exit(1);
            else if (std::cin.fail())
                std::cout << "Invalid input. index should be a number: " << std::endl;
            else
                std::cout << "An error occurred. Please enter again: " << std::endl;
            std::cin.clear(); 
            continue;     
        }
        if (input < 0 || input > index)
        {
            std::cout << "Index out of range. Please enter a valid index "<< std::endl;
            continue;
        }
        contacts[input - 1].display_contact_details();
        break;       
    }
}