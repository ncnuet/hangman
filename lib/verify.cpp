#include "verify.h"
#include <string>
#include <iostream>
#include <limits>

int verify::verifyNumber(std::string text, int min, int max)
{
    int number;
    do
    {
        std::cout << text;
        std::cin >> number;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input must be a NUMBER. " << text;
            std::cin >> number;
        }
    } while (number < min || number > max);
    return number;
}

char verify::verifyChar(std::string text, std::string charSet)
{
    char charInput;
    do
    {
        std::cout << text;
        std::cin >> charInput;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input must be a CHARACTER. " << text;
            std::cin >> charInput;
        }
    } while (charSet.find(charInput) == std::string::npos);
    return charInput;
}