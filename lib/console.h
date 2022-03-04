#pragma once
#define Console_H

#include <iostream>
#include <string>

const int MAX_WIDTH = 80;

struct console
{
public:
    static void printTextCenter(std::string text);
    static void printSeparateLine();
    static void printTextJustify(std::string text[], int textNum);
};