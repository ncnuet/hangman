#include <iostream>
#include <string>
#include <cstdlib>
#include "../lib/console.h"
#include "../lib/verify.h"
#include "../lib/data.h"
#include "../lib/user.h"
#include "../lib/config.h"

const int MAX_GUESS_COUNT = 7;

bool checkCorrectGuess(char userGuess, std::string secretWord)
{
    for (int i = 0; i < secretWord.length(); i++)
        if (secretWord[i] == userGuess)
            return true;
    return false;
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

void printHangman(int failedGuess = 0)
{
    const std::string img[] = {
        "  |             ",
        "  |      (_)    ",
        "  |       |     ",
        "  |      /|     ",
        "  |      /|\\    ",
        "  |       |     ",
        "  |      /      ",
        "  |      / \\    "};

    console::printTextCenter("  _________     ");
    console::printTextCenter("  |/      |     ");

    if (failedGuess > 0)
        console::printTextCenter(img[1]);
    else
        console::printTextCenter(img[0]);

    if (failedGuess > 1)
        console::printTextCenter(img[(failedGuess > 4) ? 4 : failedGuess]);
    else
        console::printTextCenter(img[0]);

    if (failedGuess > 4)
        console::printTextCenter(img[5]);
    else
        console::printTextCenter(img[0]);

    if (failedGuess > 5)
        console::printTextCenter(img[failedGuess]);
    else
        console::printTextCenter(img[0]);

    console::printTextCenter("  |             ");
    console::printTextCenter("  |             ");
    console::printTextCenter("__|__           ");
}

void printEndGame(bool isWinned, word_data secretWord)
{
    std::system("cls");
    console::printLogo();
    console::printTextCenter("");
    console::printSeparateLine();
    console::printTextCenter("");
    console::printTextCenter("");
    console::printTextCenter("");
    if (isWinned)
        console::printTextCenter("You winned! The secret word is '" + secretWord.word + "'. Congratulations!");
    else
        console::printTextCenter("You lose! The secret word is '" + secretWord.word + "'. Better luck next time!");
    console::printTextCenter("Example: " + secretWord.examples);
}

void printScreen(std::string statusText[], word_data secretWord, std::string currentGuess, int guessFail)
{
    std::system("cls");
    console::printLogo();
    console::printSpaceLines(1);
    console::printSeparateLine();
    console::printTextJustify(statusText, 4);
    console::printSpaceLines(3);
    console::printTextCenter(secretWord.word);
    console::printTextCenter(secretWord.meaning);
    console::printTextCenter("Current guess: " + currentGuess);
    console::printSpaceLines(1);
    printHangman(guessFail);
    console::printSpaceLines(1);
}

int CalcScore(bool isCorrect)
{
    return (isCorrect) ? 10 : -5;
}

user *initialUser()
{
    user *cur = user::getCurrentUser();
    if (cur == NULL)
    {
        std::string username = verify::verifyUsername("Enter your username: ");
        user *user_tmp = user::createUser(username);

        std::vector<std::string> configs = {
            user_tmp->getUid()};
        config::saveConfigs(configs);
        return user_tmp;
    }
    return cur;
}

void play()
{
    // Initialize data for game
    int score = 0;
    user *curUser = initialUser();

    do
    {
        // Initialize data for turn of game
        word_data secretWord = data::readWordList(1)[0];
        std::string currentGuess = initialWord(secretWord.word.length());

        int guessCount = 0;
        int guessFail = 0;

        do
        {
            // Print screen
            std::string statusText[] = {
                "USER: " + curUser->getName(),
                "Guess count: " + std::to_string(guessCount++),
                "Guess fail: " + std::to_string(guessFail),
                "Score: " + std::to_string(score)};
            printScreen(statusText, secretWord, currentGuess, guessFail);
            console::printSeparateLineInput();
            char userGuess = verify::verifyChar("Your guess: ");

            // Process input
            currentGuess = compareWord(userGuess, currentGuess, secretWord.word);
            bool isGuessCorrect = checkCorrectGuess(userGuess, secretWord.word);
            score += CalcScore(isGuessCorrect);
            guessFail += (isGuessCorrect) ? 0 : 1;

        } while (secretWord.word != currentGuess && guessFail < MAX_GUESS_COUNT);

        // End game
        printEndGame(secretWord.word == currentGuess, secretWord);
        data::addNewWord(secretWord);

        // Record high score
        curUser->updateHighScore(score);
        curUser->updateParameters(secretWord.word == currentGuess);
        curUser->save();

        // Continue game
        console::printSpaceLines(3);
        console::printSeparateLineInput();
    } while (verify::verifyYesNo("Do you want to play again? (y/n): "));
    curUser->~user();
}