#include <string>
#include <iostream>

const int MAX_GUESS_COUNT = 7;
std::string getSecretWord(int wordLength);
std::string compareWords(std::string secretWord, std::string guessWord);
std::string initialWord(int wordLength);
void printLogo();

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

void play()
{
    std::string secretWord = getSecretWord(5);
    std::string currentGuess = initialWord(secretWord.length());
    int guessCount = 1;
    do
    {
        std::cout << "Lan doan thu: " << guessCount << std::endl;
        std::cout << "Tu can doan: " << currentGuess << std::endl;
        std::cout << "Nhap 1 ky tu: ";
        char userGuess;
        std::cin >> userGuess;
        currentGuess = compareWord(userGuess, currentGuess, secretWord);
        guessCount++;
    } while (secretWord != currentGuess && guessCount <= MAX_GUESS_COUNT);

    if (guessCount > MAX_GUESS_COUNT)
        std::cout << "Ban da thua! Tu can doan la: " << secretWord << std::endl;
    else
        std::cout << "Ban da doan dung! Tu can doan la: " << secretWord << std::endl;
}

int main()
{
    printLogo();
    play();
    return 0;
}