#include "ContactsBook.h"

std::string ContactsBook::trim(const std::string& str) {
    const size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    const size_t last = str.find_last_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

std::string ContactsBook::toLower(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });
    return name;
}

bool ContactsBook::equalsIgnoreCase(const std::string& name1, const std::string& name2)
{
    return toLower(name1) == toLower(name2);
}

bool ContactsBook::isNumeric(std::string phoneNumber)
{
    if (phoneNumber.empty())
        return false;
    return std::all_of(phoneNumber.begin(), phoneNumber.end(), [](unsigned char c)
    {
        return std::isdigit(c);        
    });
}

void ContactsBook::addContact(Contact newContact)
{
    saved_contacts.push_back(newContact);
}

void ContactsBook::displayContacts(DisplayBy userChoice)
{
    switch (userChoice)
    {
    case DisplayBy::FirstName:
        break;
    case DisplayBy::LastName:

        break;
    default:
        break;
    }
    
}
