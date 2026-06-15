#include "NumeralSystemConverter.h"

#include <iostream>
#include <string>

int NumeralSystemConverter::RomanToHinduArabic(std::string roman)
{
    int result = 0;
    for (size_t i = 0; i < roman.length(); ++i)
    {
        char letter = roman.at(i);
        int value = 0, next_value = 0;
        if (!RomanCharToHinduArabic(letter, value))
        {
            std::cout << "\nERROR: Invalid Roman digit detected!";
            return 0;
        }
        result += value;
        if (i == roman.length() - 1)
        {
            continue;
        }
        char next_letter = roman.at(i + 1);
        if (!RomanCharToHinduArabic(next_letter, next_value))
        {
            std::cout << "\nERROR: Invalid Roman digit detected!";
            return 0;
        }
        if (next_value > value)
        {
            result -= value * 2;
        }
    }
    return result;
}

bool NumeralSystemConverter::RomanCharToHinduArabic(char roman, int& out)
{
    auto it = roman_to_hindu_arabic.find(roman);
    if (it == roman_to_hindu_arabic.end())
    {        
        return false;
    }
    out = it->second;
    return true;
}
