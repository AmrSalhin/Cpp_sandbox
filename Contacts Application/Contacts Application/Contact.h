#pragma once
#include<string>

enum class Group : char{Friends = 1, Family, Coworker, Acquaintance};

struct Contact
{
    std::string first_name;
    std::string last_name;
    std::string primary_phone_number;
    std::string secondary_phone_number;
    std::string email_id;
    std::string address;
    std::string company;
    Group group;
};


