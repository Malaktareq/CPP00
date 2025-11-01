#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>

enum ContactNameFields {
    first,
    last,
    nick,
};

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        void check_and_replace(std::string& str);
        void printCol(std::string str);
        std::string get_name_type(ContactNameFields field);
    public:
        void add_name(ContactNameFields field);
        void add_phone_number();
        void add_darkest_secret();
        void display_contact_details();
        void display_summary();
};



#endif