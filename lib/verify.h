#pragma once
#define Verify_H

#include <string>

struct verify
{
public:
    static int verifyNumber(std::string text, int min, int max);
    static char verifyChar(std::string text, std::string charSet = "abcdefghijklmnopqrstuvwxyz");
    static bool verifyYesNo(std::string text);
    static std::string verifyUsername(std::string text);
    static void anykey();
};