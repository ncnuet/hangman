#include <iostream>
#include "lib/verify.h"
#include "lib/console.h"

void printLogo()
{
    console::printTextCenter(" __ __   ____  ____    ____  ___ ___   ____  ____   ");
    console::printTextCenter("|  |  | /    ||    \\  /    ||   |   | /    ||    \\ ");
    console::printTextCenter("|  |  ||  o  ||  _  ||   __|| _   _ ||  o  ||  _  |");
    console::printTextCenter("|  _  ||     ||  |  ||  |  ||  \\_/  ||     ||  |  |");
    console::printTextCenter("|  |  ||  _  ||  |  ||  |_ ||   |   ||  _  ||  |  |");
    console::printTextCenter("|  |  ||  |  ||  |  ||     ||   |   ||  |  ||  |  |");
    console::printTextCenter("|__|__||__|__||__|__||___,_||___|___||__|__||__|__|");
};

int printMenu()
{
    printLogo();
    console::printTextCenter("");
    console::printTextCenter("");
    console::printTextCenter("");

    console::printTextCenter("1. Play            ");
    console::printTextCenter("2. High Score      ");
    console::printTextCenter("3. My Words        ");
    console::printTextCenter("0. Exit            ");

    console::printTextCenter("");
    console::printTextCenter("");
    console::printTextCenter("");

    std::cout << "----------" << std::endl;
    return verify::verifyNumber("Enter your choice (0 - 3): ", 0, 3);
}