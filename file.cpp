#include "file.h"


//void renderGame(const std::string& guessedWord, int badGuessCount)
//{
//	std::cout << FIGURE[badGuessCount] << std::endl;
//	std::cout << guessedWord << std::endl;
//	std::cout << "Number of wrong guesses: " << badGuessCount << std::endl;
//}
//
//char readAGuess()
//{
//	char input;
//	std::cout << "Your guess: ";
//	std::cin >> input;
//	return input;
//}
//
//bool contains(const std::string& word, char c)
//{
//	return (word.find_first_of(c) != std::string::npos);
//}
//
//void updateGuessedWord(std::string& guessedWord, const std::string& word, char guess)
//{
//	for (int i = word.length() - 1; i >= 0; i--) {
//        if (word[i] == guess) {
//            guessedWord[i] = guess;
//        }
//    }
//}

std::string chooseWordList(const std::string& file_word, const int& number_or_word)
{
    std::string word_list[number_or_word];
    std::ifstream file_input(file_word);
    if(!file_input.fail())
    {
        int i = 0;
        while(!file_input.eof()){
            file_input >> word_list[i];
            i++;
        }
        file_input.close();
        int random_index = rand() % i;
        return word_list[random_index];
    }
    return "";
}

void PrintMessage(std::string message, bool printTop , bool printBottom )
{
    if(printTop)
    {
        std::cout << "+------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
    {
        std::cout << "|";
    }
    bool front = true;
    for(int i = message.length(); i<30; i++)
    {
        if(front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    std::cout << message.c_str();

    if(printBottom)
    {
        std::cout << "|" << std::endl;
        std::cout << "+------------------------------+" << std::endl;
    }
    else
    {
        std::cout << "|" << std::endl;
    }
}
void DrawHangman(int guessCount)
{
    if(guessCount>=1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount>=2)
        PrintMessage("0", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount==3)
        PrintMessage("/", false, false);

    if(guessCount==4)
        PrintMessage("/|", false, false);

    if(guessCount>=5)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount==6)
        PrintMessage("/", false, false);

    if(guessCount>=7)
        PrintMessage("/ \\", false, false);
}
void PrintLetters(std::string input, char from, char to)
{
    std::string s;
    for(char i = from; i<=to; i++)
    {
        if(input.find(i) == std::string::npos){
            s += i;
            s += " ";
        }
        else
            s += " ";
    }
    PrintMessage(s, false, false);
}
void PrintAvailableletters(std::string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'a', 'm');
    PrintLetters(taken, 'n', 'z');
}
bool PrintWordAndCheckWin(std::string word, std::string& guessed)
{
    bool won = true;
    std::string s;
    for(int i=0; i<word.length(); i++)
    {
        if(guessed.find(word[i]) == std::string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}
int TriesLeft(std::string word, std::string guessed)
{
    int error = 0;
    for(int i=0; i<guessed.length(); i++)
    {
        if(word.find(guessed[i]) == std::string::npos)
            error++;
    }
    return error;
}
