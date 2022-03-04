#pragma once
#define Verify_H

#include <string>

struct verify
{
public:
    static int verifyNumber(std::string text, int min, int max);
    static char verifyChar(std::string text, std::string charSet);
};