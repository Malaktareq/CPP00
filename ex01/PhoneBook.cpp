/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malak <malak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:58:43 by malak             #+#    #+#             */
/*   Updated: 2025/11/01 15:51:58 by malak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    num_contacts = 0;
}

void PhoneBook::addContact()
{
    if (num_contacts >= 8)
        index = num_contacts % 8;  
    std::cout << "Adding a new contact: "<< index + 1 << std::endl; 
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
    num_contacts++;
    index++;
}

void PhoneBook::searchContacts()
{
    int end;
    if (index == 0)
    {
        std::cout << "Phonebook is empty. Please add contacts first." << std::endl;
        return;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    if (num_contacts > 8)
        end = 8;
    else
        end = num_contacts;
    for (int i = 0; i < end; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i + 1;
        contacts[i].display_summary();
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Enter the index of the contact to display: " << std::endl;
    check_and_display();
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
        }
        else if (input < 0 || input > index)
        {
            std::cout << "Index out of range. Please enter a valid index "<< std::endl;
            continue;
        }
        else
        { 
            contacts[input - 1].display_contact_details();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');       
    }
}