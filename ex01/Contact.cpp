#include "Contact.hpp"


void Contact::add_name(ContactNameFields field){

    std::string name;
    while(1)
    {
        if (!std::getline(std::cin, name))
            exit(1);
        if(name.empty())
        {
            std::cout << "First name cannot be empty. Please enter again: " << std::endl;
            continue;
        }
        if(name.find_first_of("0123456789") != std::string::npos && field != nick)
        {
            std::cout << "First name cannot contain numbers. Please enter again: " << std::endl;
            continue;
        }
        break;
    }
    if (field == first)
        first_name = name;
    else if (field == last)
        last_name = name;
    else if (field == nick)
        nickname = name;
}

void Contact::add_phone_number(){
    std::string number;
    while(1)
    {
        if (!std::getline(std::cin, number))
            exit(1);
        if(number.empty())
        {
            std::cout << "Phone number cannot be empty. Please enter again: " << std::endl;
            continue;
        }
        if(number.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Phone number must contain only digits. Please enter again: " << std::endl;
            continue;
        }
        if (number.length() != 10)
        {
            std::cout << "Phone number must be exactly 10 digits. Please enter again: " << std::endl;
            continue;
        }
        break;
    }
    phone_number = number;
}

void Contact::add_darkest_secret(){
    std::string secret;
    while(1)
    {
        if (!std::getline(std::cin, secret))
            exit(1);
        else if(secret.empty())
        {
            std::cout << "Darkest secret cannot be empty. Please enter again: " << std::endl;
            continue;
        }
        break;
    }
    darkest_secret = secret;
}

void Contact::display_contact_details(){
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret <<  std::endl;
}
std::string& Contact::get_first_name()
{
    return first_name;
}

std::string& Contact::get_last_name()
{
    return last_name;
}

std::string& Contact::get_nickname()
{
    return nickname;
}

std::string& Contact::get_phone_number()
{
    return phone_number;
}

std::string& Contact::get_darkest_secret()
{
    return darkest_secret;
}