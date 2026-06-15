#include "NumeralSystemConverter.h"

#include <iostream>
#include <string>
#include <cmath>

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

std::string NumeralSystemConverter::HinduArabicToRoman(int hindu_arabic)
{
    std::string result = "";
    std::string hindu_arabic_string = std::to_string(hindu_arabic);
    for (int i = 0; i < hindu_arabic_string.length(); ++i)
    {
        char digit_char = hindu_arabic_string.at(i);
        int  digit      = digit_char - '0';

        int column = std::pow(10, hindu_arabic_string.length() - i - 1);
        if (digit == 0)
        {
            continue;
        }
        if (digit >= 1 && digit <= 3)
        {
            for (int i = 0; i < digit; ++i)
            {
                result += hindu_arabic_to_roman.at(column);
            }
            continue;
        }
        if (digit >= 6 && digit <= 8)
        {
            result += hindu_arabic_to_roman.at(5 * column);
            for (int i = 0; i < digit; ++i)
            {
                result += hindu_arabic_to_roman.at(column);
            }
            continue;
        }
        std::string value = std::to_string(digit * column);
        result += hindu_arabic_to_roman.at(std::stoi(value));
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
