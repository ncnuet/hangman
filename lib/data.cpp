#include "data.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>

int random(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

std::string randomFileName(int max)
{
    int randomIndex = random(0, max);
    std::string fileName = DATA_FILE + std::to_string(randomIndex) + ".txt";
    return fileName;
}

std::string toLowerString(std::string str)
{
    std::string result = "";
    for (int i = 0; i < str.length(); i++)
        result += tolower(str[i]);
    return result;
}

word_data parse(std::string text)
{
    word_data data;
    std::string delimiter = "|";
    size_t pos = 0;
    std::string token;
    int part = 0;
    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        token = text.substr(0, pos);
        text.erase(0, pos + delimiter.length());
        part++;
        if (part == 1)
            data.word = toLowerString(token);
        else if (part == 2)
            data.meaning = token;
        else if (part == 3)
            data.examples = token;
    }
    return data;
}

word_data *data::readWordList(int numWords)
{
    std::fstream file;
    word_data *wordListReturn = new word_data[numWords];
    std::vector<std::string> wordList;

    int index = 0;
    std::string tmp;
    file.open(randomFileName(MAX_FILE_INDEX), std::ios::in);

    while (std::getline(file, tmp))
    {
        index++;
        wordList.push_back(tmp);
    }

    // Dam bao random ko trung nhau
    for (int i = 0; i < numWords; i++)
    {
        int randomIndex = random(0, index);
        wordListReturn[i] = parse(wordList[randomIndex]);
        wordList[randomIndex] = wordList[index - 1];
        index--;
    }

    file.close();
    return wordListReturn;
}

bool isHasNewWord(std::string word)
{
    std::fstream file;
    file.open(NEW_WORD_FILE, std::ios::in);

    std::string tmp;
    while (std::getline(file, tmp))
    {
        word_data wd = parse(tmp);
        if (wd.word == word)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void data::addNewWord(word_data new_word)
{
    if (!isHasNewWord(new_word.word))
    {
        std::fstream file;
        file.open(NEW_WORD_FILE, std::ios::app);
        file << new_word.word << "|" << new_word.meaning << "|" << new_word.examples << "|" << std::endl;
        file.close();
    }
}

std::vector<word_data> data::getNewWords()
{
    std::fstream file;
    file.open(NEW_WORD_FILE, std::ios::in);
    std::vector<word_data> newWords;
    std::string tmp;
    while (std::getline(file, tmp))
        newWords.push_back(parse(tmp));
    file.close();
    return newWords;
}