#include "file.h"
#include<thread>
#include<chrono>


int main(int argc, char* argv[])
{
//	srand(time(0));
//	std::string word = chooseWordList(DATA_FILE, 300);
//	if(word == "")
//    {
//        std::cout << "ChooseWordList";
//        return 0;
//    }
//	std::string guessedWord = std::string(word.length(), '-');
//	int badGuessCount = 0;
//
//	do {
//		renderGame(guessedWord, badGuessCount);
//		char guess = readAGuess();
//		if (contains(word, guess))
//			updateGuessedWord(guessedWord, word, guess);
//		else badGuessCount++;
//	} while (badGuessCount < MAX_BAD_GUESSES && word != guessedWord);
//
//	renderGame(guessedWord, badGuessCount);
//	if (badGuessCount < MAX_BAD_GUESSES)
//    {
//        for(int i = 0; i<4; i++){
//            for(int i=0; i<30; i++){
//                std::cout << std::endl;
//            }
//            std::cout << figure_win[i];
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        }
//		std::cout << "Congratulations! You win!";
//    }
//	else{
//        for(int i = 0; i<4; i++){
//            for(int i=0; i<30; i++){
//                std::cout << std::endl;
//            }
//            std::cout << figure_lost[i];
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        }
//		std::cout << "You lost. The correct word is " << word;
//	}

//ban hop
	srand(time(0));
	std::string word = chooseWordList(DATA_FILE, 300);
	if(word == "")
    {
        std::cout << "ChooseWordList";
        return 0;
    }
    std::string guesses;
    int tries = 0;
    bool win = false;
    std::cout << "Hello !!!" <<std::endl;
    do{
        tries = TriesLeft(word, guesses);
        system("cls");
        PrintMessage("HANG MAN");
        DrawHangman(tries);
        PrintAvailableletters(guesses);
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(word, guesses);
        if(tries == MAX_BAD_GUESSES)
            break;
        if(win)
            break;
        char x;
        std::cout << "---->";
        std::cin >> x;
        if(guesses.find(x) == std::string::npos)
        {
            guesses += x;
        }
        tries = TriesLeft(word, guesses);

    }while(tries <= MAX_BAD_GUESSES);

    if(win == true)
    {
        std::cout << "Congratulations! You win!";
    }
    else
    {
		std::cout << "You lost. The correct word is " << word;
    }

	return 0;
}
/*
    +------------------------------+
    |           HANG MAN           |
    +------------------------------+
    |              |               |
    |              |               |
    |              0               |
    |             /|\              |
    |             / \              |
    |          +--------+          |
    |          |        |          |
    +------------------------------+
    |       Available letters      |
    +------------------------------+
    |   A B C D E F G H I J K L M  |
    |   N O P Q R S T U V W X Y Z  |
    +------------------------------+
    |       Guess the word         |
    +------------------------------+
    |- - - - - - - - - - - - - - - |
    +------------------------------+
*/

