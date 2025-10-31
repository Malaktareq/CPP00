#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        int index ;
        Contact contacts[8];
        void printCol(std::string str);
        void check_and_replace(std::string& str);
        void check_and_display();
    public:
         PhoneBook();
        void addContact();
        void searchContacts();

    
};

#endif