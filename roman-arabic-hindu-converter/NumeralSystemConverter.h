#pragma once

#include <unordered_map>
#include <string>

class NumeralSystemConverter
{
public:
    int RomanToHinduArabic(std::string roman);

private:
    std::unordered_map<char, int> roman_to_hindu_arabic =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    bool RomanCharToHinduArabic(char roman, int& out);
};

