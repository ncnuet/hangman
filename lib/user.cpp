#include "user.h"
#include "config.h"

#include <string>
#include <fstream>
#include <vector>
#include <ctime>

std::string generateID(int length)
{
    std::string id = "";
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        id += (char)(rand() % 26 + 97);
    }
    return id;
}

void rewriteUserId(std::vector<std::string> uids)
{
    std::fstream file;
    file.open(USERS_PATH, std::ios::out);
    for (int i = 0; i < uids.size(); i++)
        file << uids[i] << std::endl;
    file.close();
}

// Static function class
user::user(std::string uid, std::string name, int highScore, int resolvedWordCount, int totalPlayedTime)
{
    this->uid = uid;
    this->name = name;
    this->highScore = highScore;
    this->resolvedWordCount = resolvedWordCount;
    this->totalPlayedTime = totalPlayedTime;
    this->winningPercentage = (totalPlayedTime > 0)
                                  ? (resolvedWordCount * 100) / totalPlayedTime
                                  : 0;
}

user::~user()
{
}

user *user::loadFromFile(std::string filename)
{
    std::ifstream file;
    file.open(filename, std::ios::in);

    if (!file.is_open())
        return NULL;

    int highScore, resolvedWordCount, totalPlayedTime;
    std::string name, uid;

    std::getline(file, uid);
    std::getline(file, name);
    file >> highScore;
    file >> resolvedWordCount;
    file >> totalPlayedTime;

    return new user(uid, name, highScore, resolvedWordCount, totalPlayedTime);
}

std::vector<user> user::readAllUser()
{
    std::vector<user> users;
    std::ifstream ifile;
    std::ofstream ofile;

    ifile.open(USERS_PATH, std::ios::in);

    if (ifile.is_open())
    {
        std::vector<std::string> uid;

        // Read all user id
        while (!ifile.eof())
        {
            std::string id;
            ifile >> id;
            user *user_tmp = user::loadFromFile(USER_PATH + id + ".txt");
            if (user_tmp != NULL)
            {
                users.push_back(*user_tmp);
                uid.push_back(id);
            }
        }
        ifile.close();

        // Rewrite file with all correct user id
        rewriteUserId(uid);
    }
    return users;
}

bool user::isUserExist(std::string userName)
{
    std::vector<user> users = readAllUser();
    for (int i = 0; i < users.size(); i++)
        if (users[i].getName() == userName)
            return true;
    return false;
}

user *user::getCurrentUser()
{
    std::ifstream file;
    std::string uid;

    file.open(CONFIG_PATH, std::ios::in);
    if (!file.is_open())
        return NULL;
    std::getline(file, uid);
    file.close();
    return user::loadFromFile(USER_PATH + uid + ".txt");
}

user *user::createUser(std::string userName)
{
    std::cout << "Creating new user... " << userName << std::endl;
    std::fstream file;
    std::fstream file2;
    std::string uid = generateID(10);
    user *user_tmp = new user(uid, userName, 0, 0, 0);

    file.open(USERS_PATH, std::ios::app);
    file << uid << std::endl;
    file.close();

    file2.open(USER_PATH + uid + ".txt", std::ios::out);
    file2 << user_tmp->getUid() << std::endl;
    file2 << user_tmp->getName() << std::endl;
    file2 << user_tmp->getHighScore() << std::endl;
    file2 << user_tmp->getResolvedWordCount() << std::endl;
    file2 << user_tmp->getTotalPlayedTime() << std::endl;
    file2.close();

    return user_tmp;
}

void user::deleteUser(std::string uid)
{
    // Delete user file
    std::remove((USER_PATH + uid + ".txt").c_str());

    // Delete user id from users file
    std::ifstream ifile;
    std::ofstream ofile;
    ifile.open(USERS_PATH, std::ios::in);

    if (ifile.is_open())
    {
        std::vector<std::string> uids;

        // Read all user id
        while (!ifile.eof())
        {
            std::string id;
            ifile >> id;
            if (id != uid)
                uids.push_back(id);
        }
        ifile.close();

        // Rewrite file with all correct user id
        rewriteUserId(uids);
    }
}

void user::updateUser(std::string uid, std::string username)
{
    std::fstream file;
    file.open(USER_PATH + uid + ".txt", std::ios::out | std::ios::in);

    std::string tmp;
    int highScore;
    int resolvedWordCount;
    int totalPlayedTime;

    file >> tmp;
    file >> tmp;
    file >> highScore;
    file >> resolvedWordCount;
    file >> totalPlayedTime;

    file << uid << std::endl;
    file << username << std::endl;
    file << highScore << std::endl;
    file << resolvedWordCount << std::endl;
    file << totalPlayedTime << std::endl;

    file.close();
}

// End of static function class

void user::show()
{
    std::system("cls");
    console::printLogo();
    console::printSeparateLine();
    console::printTextCenter("User Information");
    console::printTextCenter(" ");
    std::cout << "Name: " << name << std::endl;
    std::cout << "High Score: " << highScore << std::endl;
    std::cout << "Resolved Word Count: " << resolvedWordCount << std::endl;
    std::cout << "Total Played Time: " << totalPlayedTime << std::endl;
    std::cout << "Winning Percentage: " << winningPercentage << std::endl;
    verify::anykey();
}

void user::save()
{
    std::ofstream file;
    file.open(USER_PATH + this->uid + ".txt", std::ios::out);

    file << this->uid << std::endl;
    file << this->name << std::endl;
    file << this->highScore << std::endl;
    file << this->resolvedWordCount << std::endl;
    file << this->totalPlayedTime << std::endl;

    file.close();
}

void user::updateParameters(bool isWin)
{
    if (isWin)
    {
        this->totalPlayedTime += 1;
        this->resolvedWordCount += 1;
    }
    else
    {
        this->totalPlayedTime += 1;
    }
    this->winningPercentage = (this->resolvedWordCount / this->totalPlayedTime) * 100;
}

void user::updateHighScore(int highScore)
{
    this->highScore = (highScore > this->highScore) ? highScore : this->highScore;
}

std::string user::getName()
{
    return this->name;
}

std::string user::getUid()
{
    return this->uid;
}

int user::getHighScore()
{
    return this->highScore;
}

int user::getResolvedWordCount()
{
    return this->resolvedWordCount;
}

int user::getTotalPlayedTime()
{
    return this->totalPlayedTime;
}

double user::getWinningPercentage()
{
    return this->winningPercentage;
}