#pragma once

#include <unordered_map>
#include <string>

class NumeralSystemConverter
{
public:
    int RomanToHinduArabic(std::string roman);
    std::string HinduArabicToRoman(int hindu_arabic);

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

    std::unordered_map<int, std::string> hindu_arabic_to_roman =
    {
        {1   , "I"},
        {10  , "X"},
        {100 , "C"},
        {1000, "M"},
        {4   , "IV"},
        {40  , "XL"},
        {400 , "CD"},
        {5   , "V"},
        {50  , "L"},
        {500 , "D"},
        {9   , "IX"},
        {90  , "XC"},
        {900 , "CM"},
    };

    bool RomanCharToHinduArabic(char roman, int& out);
};
