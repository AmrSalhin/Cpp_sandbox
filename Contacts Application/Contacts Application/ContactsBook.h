#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include "Contact.h"

class ContactsBook
{
    std::vector<Contact> saved_contacts;

    public:

    enum class DisplayBy 
    {
        FirstName = 1,
        LastName
    };

    std::optional<Contact> addContactFromUserInput();
    void displayContacts(DisplayBy userChoice);

};

