#include <iostream>

const int MAX_WIDTH = 80;

void printTextCenter(std::string text)
{
    int textLength = text.length();
    for (int i = 0; i < (MAX_WIDTH - textLength) / 2; i++)
        std::cout << ' ';
    std::cout << text;
    for (int i = 0; i < (MAX_WIDTH - textLength) / 2; i++)
        std::cout << ' ';
    std::cout << std::endl;
}

void printLogo()
{
    printTextCenter(" __ __   ____  ____    ____  ___ ___   ____  ____   ");
    printTextCenter("|  |  | /    ||    \\  /    ||   |   | /    ||    \\ ");
    printTextCenter("|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |");
    printTextCenter("|  _  ||     ||  |  ||  |  ||  \\_/  ||     ||  |  |");
    printTextCenter("|  |  ||  _  ||  |  ||  |_ ||   |   ||  _  ||  |  |");
    printTextCenter("|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |");
    printTextCenter("|__|__||__|__||__|__||___,_||___|___||__|__||__|__|");
};
