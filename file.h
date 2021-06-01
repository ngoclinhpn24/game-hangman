#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

const int MAX_BAD_GUESSES = 7;
const char DATA_FILE[] = "Ogden_Picturable_200.txt";
//const char LIST_WORD[] = "words.txt";
// ban hoat hinh
//string chooseWord();
//std::string chooseWordList(const std::string& file_word, const int& number_of_word);
//void renderGame(const std::string& guessedWord, int badGuessCount);
//char readAGuess();
//bool contains(const std::string& word, char guess);//
//void updateGuessedWord(std::string& guessedWord, const std::string& word, char guess);

// ban hop
void PrintMessage(std::string message, bool printTop = true, bool printBottom = true);
void DrawHangman(int guessCount = 0);
void PrintLetters(std::string input, char from, char to);
void PrintAvailableletters(std::string taken);
bool PrintWordAndCheckWin(std::string word, std::string& guessed);
int TriesLeft(std::string word, std::string guessed);
const std::string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };

const std::string figure_win[]{
        "          O          \n"
        "         /|\\        \n"
        "         | |         \n",
        "          O          \n"
        "         /|\\        \n"
        "         / \\        \n",
        "         _O_         \n"
        "          |          \n"
        "         / \\        \n",
        "         \\O/        \n"
        "          |          \n"
        "         / \\        \n",
        "         _O_         \n"
        "          |          \n"
        "         / \\        \n"
};
const std::string figure_lost[]{
        "-------------        \n"
        "  |       |          \n"
        "  |       O          \n"
        "  |      /|\\        \n"
        "  |      / \\        \n"
        "-----\n",
        "-------------        \n"
        "   |     |           \n"
        "   |     O           \n"
        "   |     /|\\        \n"
        "   |     / \\        \n"
        "------\n",
        "-------------        \n"
        "   |      |          \n"
        "   |      O          \n"
        "   |     /|\\        \n"
        "   |     / \\        \n"
        "------\n",
        "-------------        \n"
        "   |       |         \n"
        "   |       O         \n"
        "   |     /|\\        \n"
        "   |     / \\        \n"
        "------\n",
        "   |      |          \n"
        "   |      O          \n"
        "   |     /|\\        \n"
        "   |     / \\        \n"
        "-------\n"
};
#endif // FILE_H
