#include <iostream>
#include <optional>
#include "ContactsBook.h"

static std::string trim(const std::string& str) {
    // 1. Find first character that is NOT a whitespace
    const size_t first = str.find_first_not_of(" \t\r\n\v\f");
    
    // If the entire string is whitespace or empty, return empty string
    if (first == std::string::npos) {
        return "";
    }

    // 2. Find last character that is NOT a whitespace
    const size_t last = str.find_last_not_of(" \t\r\n\v\f");

    // 3. Substring takes (starting_index, length_of_substring)
    // Length is: (last - first + 1)
    return str.substr(first, (last - first + 1));
}

static std::string toLower(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });
    return name;
}

static bool equalsIgnoreCase(const std::string& name1, const std::string& name2)
{
    return toLower(name1) == toLower(name2);
}

static bool isNumeric(std::string phoneNumber)
{
    if (phoneNumber.empty())
        return false;
    return std::all_of(phoneNumber.begin(), phoneNumber.end(), [](unsigned char c)
    {
        return std::isdigit(c);        
    });
}

static std::optional<std::string> askForInputOrCancel(std::string requierdData)
{
    std::string input;
    while (true)
    {
        std::cout << "Please Enter " << requierdData << " Or Enter 0 To Cancel: ";
        std::getline(std::cin, input);

        input = trim(input); // Clean whitespace
        
        if (input == "0")
        {
            std::cout << "Canceled!" << std::endl;
            return std::nullopt;
        }

        if (!input.empty())
        {
            return input;
        }

        std::cout << "Error: Field cannot be empty. Please try again.\n";
    }
    
}

static std::optional<std::string> askForInputOrCancel(const std::string& fieldName, bool& outCancelled) {
    outCancelled = false;
    std::string input;

        std::cout << "Enter " << fieldName << " [Optional, press Enter to skip or '0' to cancel]: ";
        std::getline(std::cin, input);
        
        input = trim(input); // Clean whitespace

        // Cancel signal
        if (input == "0") {
            outCancelled = true;
            return std::nullopt;
        }

        // Skipped by user
        if (input.empty()) {
            return std::nullopt; // Means "no value provided"
        }
        return input;
}

std::optional<Contact> ContactsBook::addContactFromUserInput()
{

    std::cout << "\n===============================\n";
    std::cout << "       ADD NEW CONTACT         \n";
    std::cout << "===============================\n";

    // 1. Get First Name
    auto firstName = askForInputOrCancel("First Name");
    if (!firstName.has_value()) return std::nullopt;

    // 2. Get Last Name
    auto lastName = askForInputOrCancel("Last Name");
    if (!lastName.has_value()) return std::nullopt;

    // 3. Get Primary Number
    std::string number;
    while (true)
    {
        auto primaryNumber = askForInputOrCancel("Primary number");
        if (!primaryNumber.has_value()) return std::nullopt;
        if (isNumeric(primaryNumber.value()))
        {
            number = primaryNumber.value();
            break;
        }
        std::cout << "Error: Phone number must contain digits only! Try again." << std::endl;
    }

    // 4. Get secondry Number (optional)
    bool canceled = false;
    std::string secNum;
    while (true)
    {
        auto secondaryNumber = askForInputOrCancel("secondary number", canceled);
        if (canceled) return std::nullopt;
        if (!secondaryNumber.has_value()) 
        {
            break; 
        }
        if (isNumeric(secondaryNumber.value()))
        {
            secNum = secondaryNumber.value_or("");
            break;
        }
        std::cout << "Error: Phone number must contain digits only! Try again." << std::endl;
    }

    // 5. Get Email Address
    auto email = askForInputOrCancel("Email Address");
    if (!email.has_value()) return std::nullopt;

    // 6. Get Address
    canceled =false;
    auto address = askForInputOrCancel("Address", canceled).value_or("");
    if (canceled) return std::nullopt;

    // 7. Get Company
    canceled =false;
    auto company = askForInputOrCancel("Company", canceled).value_or("");
    if (canceled) return std::nullopt;

    // 8. Get Group
    Group contactGroup;
    while (true)
    {
        auto inputGroup = askForInputOrCancel("press the number for the right group\n1. Friends\n2. Family\n3. Coworker\n4. Acquaintance");
        if (!inputGroup.has_value()) return std::nullopt;

        std::string choiceStr = inputGroup.value();
        if (choiceStr == "1") {
            contactGroup = Group::Friends;
            break;
        } else if (choiceStr == "2") {
            contactGroup = Group::Family;
            break;
        } else if (choiceStr == "3") {
            contactGroup = Group::Coworker;
            break;
        } else if (choiceStr == "4") {
            contactGroup = Group::Acquaintance;
            break;
        }

        std::cout << "Error: Wrong Group number." << std::endl;
    }
    saved_contacts.emplace_back(firstName.value(), lastName.value(), number, secNum, email.value(), address,
    company, contactGroup);
    return Contact{firstName.value(), lastName.value(), number, secNum, email.value(), address,
    company, contactGroup};
    
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
