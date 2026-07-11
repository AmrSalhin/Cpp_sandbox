#include "functions.h"
#include <cstring>
#include <stdexcept>

template<>
const char* Add<const char*>(const char* x, const char* y)
{

    int size = strlen(x) + strlen(y) + 1;
    char* result = new char[size];
    
    strcpy_s(result, size, x);
    strcat_s(result, size, y);

	return result;
}

template <>
const char* ArraySum(const char* const (&pArr)[4])
{
    int totalLength = 0;
    for (int i = 0; i < 4; ++i) // Hardcoded to 4 to match the specialization
    {
        totalLength += strlen(pArr[i]);
    }

    char* result = new char[totalLength + 1];
    result[0] = '\0'; 

    for (int i = 0; i < 4; ++i)
    {
        strcat_s(result, totalLength + 1, pArr[i]);
    }

    return result;
}

template<>
std::string Max(const std::string (&pArr)[4])
{
    if (sizeof(pArr) / sizeof(pArr[0]) == 0)
    {
        throw std::invalid_argument("Array is empty");
    }

    std::string max = pArr[0];
    for (int i = 1; i < 4; ++i) // Hardcoded to 4 to match the specialization
    {
        if (pArr[i].length() > max.length())
        {
            max = pArr[i];
        }
    }
    return max;
}