#include <iostream>
#include "Integer.h"


//Integer::Integer()
//{
//    std::cout << "Integer()" << std::endl;
//    pValue = new int(0);
//}

Integer::Integer(int value)
{
    std::cout << "Integer(int value)" << std::endl;
    pValue = new int(value);
}
Integer::Integer(const Integer& other)
{
    std::cout << "Integer(const Integer& other)" << std::endl;
    pValue = new int(*other.pValue);
}
Integer::Integer(Integer&& other) noexcept
{
    std::cout << "Integer(Integer&& other)" << std::endl;
    pValue = other.pValue;
    other.pValue = nullptr;
}
Integer::~Integer()
{
    std::cout << "Integer::~Integer()" << std::endl;
    delete pValue;
}
Integer& Integer::operator=(const Integer& other)
{
    std::cout << "Integer& Integer::operator=(const Integer& other)" << std::endl;
    if (this != &other)
    {
        *pValue = *other.pValue;
    }
    return *this;
}
Integer& Integer::operator=(Integer&& other) noexcept
{
    std::cout << "Integer& Integer::operator=(Integer&& other)" << std::endl;
    if (this != &other)
    {
        delete pValue;
        pValue = other.pValue;
        other.pValue = nullptr;
    }
    return *this;
}

int Integer::getValue() const
{
    return *pValue;
}

void Integer::setValue(int value)
{
    *pValue = value;
}