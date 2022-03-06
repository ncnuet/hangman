#include "console.h"
#include "verify.h"

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

// Add white space to the left of the string in order to fit column width
std::string addWhiteSpace(int width, std::string text)
{
    int textLength = text.length();
    int whiteSpace = width - textLength;
    std::string result = text;
    for (int i = 0; i < whiteSpace; i++)
        result += " ";
    return result;
}

// Put a string in the center of the line
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

// Print the separator line
void console::printSeparateLine(char c)
{
    for (int i = 0; i < MAX_WIDTH; i++)
        std::cout << c;
    std::cout << std::endl;
}

// Print text as columns
void console::printTextJustify(std::string text[], int textNum)
{
    int spacePerCol = MAX_WIDTH / textNum;
    for (int i = 0; i < textNum; i++)
    {
        if (text[i].length() > spacePerCol - 2)
            text[i] = text[i].substr(0, spacePerCol - 5) + "...";
        std::cout << text[i];
        for (int j = 0; j < spacePerCol - text[i].length(); j++)
            std::cout << ' ';
    }
    std::cout << std::endl;
}

void console::printSeparateLineInput()
{
    std::cout << "--------" << std::endl;
}

void console::printLogo()
{
    console::printTextCenter(" __ __   ____  ____    ____  ___ ___   ____  ____   ");
    console::printTextCenter("|  |  | /    ||    \\  /    ||   |   | /    ||    \\ ");
    console::printTextCenter("|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |");
    console::printTextCenter("|  _  ||     ||  |  ||  |  ||  \\_/  ||     ||  |  |");
    console::printTextCenter("|  |  ||  _  ||  |  ||  |_ ||   |   ||  _  ||  |  |");
    console::printTextCenter("|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |");
    console::printTextCenter("|__|__||__|__||__|__||___,_||___|___||__|__||__|__|");
}

// Print more white lines
void console::printSpaceLines(int lines)
{
    for (int i = 0; i < lines; i++)
        std::cout << std::endl;
}

// Print a menu and get user choice
int console::printMenu(std::string title, const std::vector<std::string> text)
{
    int textNum = text.size();
    int max_content_length = 0;
    for (int i = 0; i < textNum; i++)
        max_content_length = (text[i].length() > max_content_length) ? text[i].length() : max_content_length;

    std::system("cls");
    console::printLogo();
    console::printSpaceLines(3);

    console::printTextCenter(title);
    console::printSpaceLines(2);
    for (int i = 0; i < textNum; i++)
        console::printTextCenter(addWhiteSpace(max_content_length, text[i]));

    console::printSpaceLines(3);
    std::cout << "----------" << std::endl;
    return verify::verifyNumber("Enter your choice (0 - " + std::to_string(textNum - 1) + "): ", 0, textNum - 1);
}