#include "config.h"
#include <string>
#include <fstream>
#include <vector>

// Save game configs to file
void config::saveConfigs(std::vector<std::string> configs)
{
    std::ofstream file;
    file.open(CONFIG_PATH, std::ios::out);

    if (!file.is_open())
        return;

    for (int i = 0; i < configs.size(); i++)
        file << configs[i] << std::endl;

    file.close();
}

// Set default user when playing game
void config::setCurrentUser(std::string uid)
{
    std::ifstream ifile;
    std::vector<std::string> configs;

    ifile.open(CONFIG_PATH, std::ios::in);

    if (!ifile.is_open())
        return;

    while (!ifile.eof())
    {
        std::string config;
        ifile >> config;
        configs.push_back(config);
    }

    configs[0] = uid;
    config::saveConfigs(configs);
}