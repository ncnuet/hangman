#pragma once
#define CONFIG_H

#include <string>
#include <vector>

const std::string CONFIG_PATH = "data/configs/config.txt";
struct config
{
public:
    static void saveConfigs(std::vector<std::string> configs);
    static void setCurrentUser(std::string uid);
};
