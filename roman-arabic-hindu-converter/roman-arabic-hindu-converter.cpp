#include <iostream>

#include "NumeralSystemConverter.h"
#include <string>

enum class UserOption
{
    None = 0,
    Exit = 1,
    ConvertRoman = 2,
    ConvertHinduArabic = 3
};

int main()
{    
    NumeralSystemConverter converter;
    UserOption option = UserOption::None;
    do
    {
        std::cout << "\nChoose a action:";
        std::cout << "\nExit (1), Convert roman to hindu-arabic (2), Convert hindu-arabic to roman (3)\n";
        int raw_option = 0;
        std::cin >> raw_option;
        option = static_cast<UserOption>(raw_option);

        std::string output = "";
        
        std::string roman;
        std::string hindu_arabic;
        switch (option)
        {
            case UserOption::ConvertRoman:
                std::cout << "Enter a roman number: ";
                std::cin >> roman;
                output = std::to_string(converter.RomanToHinduArabic(roman));
                std::cout << roman << " = ";
                break;
            case UserOption::ConvertHinduArabic:
                std::cout << "Enter a hindu-arabic number: ";
                std::cin >> hindu_arabic;
                output = converter.HinduArabicToRoman(std::stoi(hindu_arabic));
                std::cout << hindu_arabic << " = ";
                break;
        };        
        if (!output.empty())
        {
            std::cout << output;
            std::cout << "\nBazinga!";
        }
    } while (option != UserOption::Exit);
    std::cout << "Program finished.";
}
