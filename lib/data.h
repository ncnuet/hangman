#pragma once
#define Data_H

#include <string>
#include <vector>

const int MAX_FILE_INDEX = 24;
const std::string DATA_FILE = "data/data/data-";
const std::string NEW_WORD_FILE = "data/configs/new-word.txt";

struct word_data
{
    std::string word;
    std::string meaning;
    std::string examples;
};

struct data
{
public:
    static word_data *readWordList(int numWords);
    static void addNewWord(word_data new_word);
    static std::vector<word_data> getNewWords();
};
