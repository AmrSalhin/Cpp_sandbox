#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Contact.h"

class ContactsBook
{
    std::vector<Contact> saved_contacts;

    std::string trim(const std::string& str);
    std::string toLower(std::string name); /*helper function convert all string to lower case*/
    bool equalsIgnoreCase(const std::string& name1, const std::string& name2); /*convert two strings to lower case then compare them*/
    bool isNumeric(std::string phoneNumber); /*check if the entered input is valid number*/
    public:

    enum class DisplayBy 
    {
        FirstName = 1,
        LastName
    };

    void addContact(Contact newContact);
    void displayContacts(DisplayBy userChoice);

};

