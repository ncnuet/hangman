#include "../lib/data.h"
#include "../lib/console.h"
#include "../lib/verify.h"

#include <vector>

void showNewWord()
{
    std::vector<word_data> newWords = data::getNewWords();
    std::string headerTable[] = {"#", "Word", "Meaning", "Examples"};
    int index = 0;

    for (word_data wd : newWords)
    {
        if (index % 15 == 0)
        {
            console::printSpaceLines(3);
            console::printSeparateLineInput();
            bool choice = (index == 0)
                              ? true
                              : verify::verifyYesNo("Do you want to continue? (y/n)");
            if (!choice)
                break;
            else
            {
                std::system("cls");
                console::printTextJustify(headerTable, 4);
                console::printSeparateLine('=');
            }
        }

        index++;
        std::string rowTable[] = {std::to_string(index), wd.word, wd.meaning, wd.examples};
        console::printTextJustify(rowTable, 4);
        console::printSeparateLine();
    }

    console::printSpaceLines(3);
    console::printSeparateLineInput();
    verify::anykey();
}