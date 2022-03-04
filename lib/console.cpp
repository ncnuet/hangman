#include "console.h"
#include <iostream>
#include <string>
#include <iterator>

void console::printTextCenter(std::string text)
{
    int textLength = text.length();
    for (int i = 0; i < (MAX_WIDTH - textLength) / 2; i++)
        std::cout << ' ';
    std::cout << text;
    for (int i = 0; i < (MAX_WIDTH - textLength) / 2; i++)
        std::cout << ' ';
    std::cout << std::endl;
}

void console::printSeparateLine()
{
    for (int i = 0; i < MAX_WIDTH; i++)
        std::cout << '-';
    std::cout << std::endl;
}

void console::printTextJustify(std::string text[], int textNum)
{
    int spacePerCol = MAX_WIDTH / textNum;
    for (int i = 0; i < textNum; i++)
    {
        std::cout << text[i];
        for (int j = 0; j < spacePerCol - text[i].length(); j++)
            std::cout << ' ';
    }
    std::cout << std::endl;
}