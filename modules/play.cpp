#include <iostream>
#include <string>
#include <cstdlib>
#include "../lib/console.h"
#include "../lib/verify.h"

const int MAX_GUESS_COUNT = 7;

void printLogo();
std::string getSecretWord(int wordLength);
std::string compareWord(char userGuess, std::string currentGuess, std::string secretWord);
std::string initialWord(int wordLength);

std::string getSecretWord(int wordLength)
{
    std::string secretWord = "nghia";
    return secretWord;
}

std::string compareWord(char userGuess, std::string currentGuess, std::string secretWord)
{
    std::string result = currentGuess;
    for (int i = 0; i < secretWord.length(); i++)
        if (userGuess == secretWord[i] && currentGuess[i] == '_')
            result[i] = userGuess;
    return result;
}

std::string initialWord(int wordLength)
{
    std::string result = "";
    for (int i = 0; i < wordLength; i++)
        result += '_';
    return result;
}

void printEndGame(bool isWinned, std::string secretWord)
{
    std::system("cls");
    printLogo();
    console::printTextCenter("");
    console::printSeparateLine();
    console::printTextCenter("");
    console::printTextCenter("");
    console::printTextCenter("");
    if (isWinned)
        console::printTextCenter("You winned! The secret word is '" + secretWord + "'. Congratulations!");
    else
        console::printTextCenter("You lose! The secret word is " + secretWord + "'. Better luck next time!");
}

void play()
{
    std::string secretWord = getSecretWord(5);
    std::string currentGuess = initialWord(secretWord.length());
    int guessCount = 1;
    do
    {
        std::string statusText[] = {
            "USER: nghia",
            "Guess count: " + std::to_string(guessCount)};

        std::system("cls");
        printLogo();
        console::printTextCenter("");
        console::printSeparateLine();
        console::printTextJustify(statusText, 2);
        console::printTextCenter("");
        console::printTextCenter("");
        console::printTextCenter("");
        console::printTextCenter("Tu can doan: " + currentGuess);
        console::printTextCenter("");
        console::printTextCenter("");
        console::printTextCenter("");
        std::cout << "--------" << std::endl;
        char userGuess = verify::verifyChar("Your guess: ", "abcdefghijklmnopqrstuvwxyz");
        currentGuess = compareWord(userGuess, currentGuess, secretWord);
        guessCount++;
    } while (secretWord != currentGuess && guessCount <= MAX_GUESS_COUNT);
    printEndGame(secretWord == currentGuess, secretWord);
}