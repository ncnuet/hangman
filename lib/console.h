#pragma once
#define Console_H

#include <iostream>
#include <string>
#include <vector>

const int MAX_WIDTH = 120;

struct console
{
public:
    static void printTextCenter(std::string text);
    static void printSeparateLine(char c = '-');
    static void printTextJustify(std::string text[], int textNum);
    static void printSeparateLineInput();
    static void printLogo();
    static void printSpaceLines(int lines);
    static int printMenu(std::string title, const std::vector<std::string> text);
};