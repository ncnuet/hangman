#include "utils.h"
#include <string>

std::string utils::trim(std::string text)
{
    int start = 0;
    int end = text.length() - 1;

    while (start < text.length() && text[start] == ' ')
        start++;

    while (end >= 0 && text[end] == ' ')
        end--;

    return text.substr(start, end - start + 1);
}