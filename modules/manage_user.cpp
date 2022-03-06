#include <iostream>
#include <vector>
#include <string>

#include "../lib/user.h"
#include "../lib/verify.h"
#include "../lib/console.h"
#include "../lib/config.h"

std::vector<user> showUsers()
{
    std::vector<user> users;
    users = user::readAllUser();
    console::printTextCenter("User List");
    console::printSpaceLines(1);
    for (int i = 0; i < users.size(); i++)
        std::cout << std::to_string(i + 1) << " - " << users[i].getUid() << " - " << users[i].getName() << std::endl;
    console::printSpaceLines(3);
    return users;
}

void addUser()
{
    std::system("cls");
    std::string username;
    username = verify::verifyUsername("Enter your name: ");

    user *user_tmp = user::createUser(username);
    std::cout << "User created successfully" << std::endl;
    verify::anykey();
}

void deleteUser()
{
    std::system("cls");
    std::vector<user> userList = showUsers();
    console::printSeparateLineInput();
    int user_id = verify::verifyNumber("Enter user index: ", 1, userList.size());
    user::deleteUser(userList[user_id - 1].getUid());

    std::cout << "User deleted successfully" << std::endl;
    verify::anykey();
}

void updateUser()
{
    std::system("cls");
    std::vector<user> userList = showUsers();
    console::printSeparateLineInput();
    int user_id = verify::verifyNumber("Enter user index: ", 1, userList.size());
    std::string username;
    username = verify::verifyUsername("Enter new name: ");
    user::updateUser(userList[user_id - 1].getUid(), username);

    std::cout << "User updated successfully" << std::endl;
    verify::anykey();
}

void switchUser()
{
    std::system("cls");
    std::vector<user> userList = showUsers();
    console::printSeparateLineInput();
    int user_id = verify::verifyNumber("Enter user index: ", 1, userList.size());
    config::setCurrentUser(userList[user_id - 1].getUid());

    std::cout << "User switched successfully" << std::endl;
    verify::anykey();
}

void switch_command(int choice)
{
    switch (choice)
    {
    case 0:
        break;
    case 1:
        addUser();
        break;
    case 2:
        deleteUser();
        break;
    case 3:
        updateUser();
        break;
    case 4:
        std::system("cls");
        showUsers();
        console::printSeparateLineInput();
        verify::anykey();
        break;
    case 5:
        switchUser();
        break;

    default:
        break;
    }
}

void manageUsers()
{
    int choice = 0;
    const std::vector<std::string> menuList = {
        "1. Add User",
        "2. Delete User",
        "3. Edit User",
        "4. Show Users",
        "5. Switch User",
        "0. Back"};

    do
    {
        choice = console::printMenu("Manager Users", menuList);
        switch_command(choice);
    } while (choice != 0);
}