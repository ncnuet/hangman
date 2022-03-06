#include "../lib/user.h"
#include <iostream>
#include <string>
#include <vector>

void getHighScore(){
    std::system("cls");
    std::vector <user> users = user::readAllUser();
    std::string headerTable[] = {"#", "Username", "Score"};
    console::printTextJustify(headerTable, 3);
    console::printSeparateLine('=');
    int i = 1;
    for (auto user : users){
        std::string row[] = {std::to_string(i), user.getName(), std::to_string(user.getHighScore())};
        console::printTextJustify(row, 3);
        i++;
    }
    console::printSpaceLines(3);
    console::printSeparateLineInput();
    verify::anykey();
}