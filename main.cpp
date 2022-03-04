#include <iostream>

int printMenu();
void switchMenu(int menuChoice);
void play();

void switchMenu(int menuChoice)
{
    switch (menuChoice)
    {
    case 1:
        play();
        break;
    case 2:
        std::cout << "High Score" << std::endl;
        break;
    case 3:
        std::cout << "My Words" << std::endl;
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
    int choice = printMenu();
    switchMenu(choice);
    return 0;
}