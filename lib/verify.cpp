#include "verify.h"
#include "user.h"
#include "utils.h"

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

bool verify::verifyYesNo(std::string text)
{
    char charInput;
    do
    {
        charInput = verify::verifyChar(text, "yYnN");
    } while (charInput != 'y' && charInput != 'Y' && charInput != 'n' && charInput != 'N');
    return charInput == 'y' || charInput == 'Y';
}

std::string verify::verifyUsername(std::string text)
{
    std::string userInput;
    bool isValid = false;
    do
    {
        std::cout << text;
        std::cin >> userInput;

        if (utils::trim(userInput) == "")
        {
            std::cout << "Username cannot be empty. " << text;
            isValid = false;
        }
        else if (user::isUserExist(userInput))
        {
            std::cout << "Username already exists. " << text;
            isValid = false;
        }
        else
            isValid = true;
    } while (!isValid);
    return userInput;
}

void verify::anykey()
{
    std::cout << "Press any key to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::getchar();
}