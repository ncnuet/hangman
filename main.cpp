
#include "lib/console.h"
#include <iostream>
#include <vector>
#include <string>

void play();
void getHighScore();
void showNewWord();
void manageUsers();
void switchMenu(int menuChoice);

void switchMenu(int menuChoice)
{
    switch (menuChoice)
    {
    case 1:
        play();
        break;
    case 2:
        getHighScore();
        break;
    case 3:
        showNewWord();
        break;
    case 4:
        manageUsers();
        break;
    case 0:
        std::cout << "Exit" << std::endl;
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}

int main()
{
    int choice = 0;
    const std::vector<std::string> menuList = {
        "1. Play",
        "2. Get high score",
        "3. Show new word",
        "4. Manage users",
        "0. Exit"
    };

    do
    {
        choice = console::printMenu("Main Menu", menuList);
        switchMenu(choice);
    } while (choice != 0);

    return 0;
}