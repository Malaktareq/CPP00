#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>
int main() {
    PhoneBook Phonebook;
    std::string command;

    std::cout << "Welcome to my creppy awesome phonebook!" << std::endl;
    while(1)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): " << std::endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << " Goodbye! \n";
            break;
        }
        for (size_t i = 0; i < command.length(); i++)
            command[i] = toupper(command[i]);
        if (command == "ADD")
            Phonebook.addContact();
        else if (command == "SEARCH")
            Phonebook.searchContacts();
        else if (command == "EXIT")
        {
            std::cout << " Goodbye! see you later! \n";
            break;
        }
    }
}