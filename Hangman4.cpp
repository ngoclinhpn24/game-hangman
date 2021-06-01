#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_BAD_GUESSES =7;
const char DATA_FILE[] = "Ogden_Picturable_200.txt";

void textcolor(int x);
string chooseWordList();
void PrintMessage(string message, bool printTop, bool printBottom);
void DrawHangman(int guessCount = 0);
void PrintLetters(string input, char from, char to);
void PrintAvailableletters(string taken);
bool PrintWordAndCheckWin(string word, string &guessed );

void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

string chooseWordList()
{
    string word_list[400];
    ifstream file("Ogden_Picturable_200.txt", ios::in);
    if(!file.fail())
    {
        int i = 0;
        while(!file.eof())
        {
            file >> word_list[i];
            i++;
        }
        file.close();
        int random = rand()%i;
        return word_list[random];
    }
    return "";
}

void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if(printTop)
    {
        cout << "+------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for(int i = message.length();i < 30; i++) // cộng từ giữa xang hai bên
    {
        if(front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front =! front;
    }
    cout << message.c_str();// chuyen tu string sang char

    if(printBottom)
    {
        cout << "|" << endl;
        cout << "+------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

void DrawHangman(int guessCount)
{
    if(guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount >= 2)
        PrintMessage("0", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount == 3)
        PrintMessage("/ ", false, false);

    if(guessCount == 4)
        PrintMessage("/|", false, false);

    if(guessCount >= 5)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if(guessCount == 6)
        PrintMessage("/ ", false, false);

    if(guessCount >= 7)
        PrintMessage("/ \\", false, false);
}

void PrintLetters(string input, char from, char to)
{
    string s;
    for(char i = from; i <= to; i++)
    {
        if(input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
        {
            s += " ";
        }
    }
    PrintMessage(s, false, false);
}

void PrintAvailableletters(string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'a', 'm');
    PrintLetters(taken, 'n', 'z');
}

bool PrintWordAndCheckWin(string word, string& guessed)
{
    bool won = true;
    string s;
    for(int i =0; i< word.length(); i++)
    {
        if(guessed.find(word[i]) == string::npos)
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

int TriesLeft(string word, string guessed)
{
    int error = 0;
    for(int i = 0; i< guessed.length(); i++)
    {
        if(word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}

int main()
{
    ifstream FileIn;
    FileIn.open("Gioithieu.txt", ios::in);
    while(!FileIn.eof())
    {
        char c;
        FileIn.get(c);
        Sleep(80);
        textcolor(14);
        cout << c;
    }
    FileIn.close();

    ifstream MyFile;
    MyFile.open("HinhHangman.txt", ios::in);
    while(!MyFile.eof())
    {
        char c;
        MyFile.get(c);
        textcolor(10);
        cout << c;
    }
    MyFile.close();
    srand(time(0));
    string word = chooseWordList();
    if(word == "")
    {
        cout << "ChooseWordList";
        return 0;
    }
    string guesses;
    int tries = 0;
    bool win = false;
    //cout << "Hello !!!" << endl;
    textcolor(11);
    do
    {
        tries = TriesLeft(word, guesses);
        system("cls");
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableletters(guesses);
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(word, guesses);
        if(tries == MAX_BAD_GUESSES)
            break;
        if(win)
            break;
        char x;
        cout << "---->";
        cin >> x;
        if(guesses.find(x) == string::npos)
        {
            guesses += x;
        }
        tries = TriesLeft(word, guesses);
    }while(tries <= MAX_BAD_GUESSES);
    if(win == true)
    {
        cout << "Congratulation! You win!";
    }
    else
    {
        cout << "You lost. The correct word is " << word;
    }
    return 0;
}
