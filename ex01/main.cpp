#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook Phonebook;
    std::string command;

    std::cout << "Welcome to my creppy awesome phonebook!" << std::endl;
    while(1)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): " << std::endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nInput interrupted (EOF). Type EXIT to quit.\n";
            std::cin.clear(); 
            continue;     
        }
        if (command == "ADD")
            Phonebook.addContact();
        else if (command == "SEARCH")
            Phonebook.searchContacts();
        else if (command == "EXIT")
            break;
    }
}