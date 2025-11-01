#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

class PhoneBook
{
    private:
        int index ;
        int num_contacts;
        Contact contacts[8];
        void check_and_display();
    public:
        PhoneBook();
        void addContact();
        void searchContacts();
};

#endif