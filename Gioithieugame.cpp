#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//Hàm tô màu
void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
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

    return 0;
}
