#pragma once
#define User_H

#include "console.h"
#include "verify.h"
#include <string>
#include <vector>

const std::string USERS_PATH = "data/users/users.txt";
const std::string USER_PATH = "data/users/";

class user
{
private:
    std::string name;
    std::string uid;
    int highScore;
    int resolvedWordCount;
    int totalPlayedTime;
    double winningPercentage;

public:
    user(std::string uid, std::string name, int highScore, int resolvedWordCount, int totalPlayedTime);
    ~user();

    void show();
    void save();

    void updateHighScore(int highScore);
    void updateParameters(bool isWin);

    std::string getName();
    std::string getUid();
    int getHighScore();
    int getResolvedWordCount();
    int getTotalPlayedTime();
    double getWinningPercentage();

    static user *loadFromFile(std::string filename);
    static std::vector<user> readAllUser();
    static user *getCurrentUser();
    static bool isUserExist(std::string userName);
    static user *createUser(std::string userName);
    static void deleteUser(std::string uid);
    static void updateUser(std::string uid, std::string name);
};