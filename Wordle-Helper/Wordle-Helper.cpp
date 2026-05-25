#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "Database.h"
using namespace std;

void insertWord(Database db,const string& s)
{   
    cout << "\n<WORD RESULT>" << endl;
    db.searchWord(s) ;
    cout << "Press Enter To Back >>";
    getchar();
    return;
}

void howToUse()
{
    string s = "";
    cout << "\n=====================[Guide: How to Use]======================\n"<<endl;
    cout << "1. Choose option [1] (insert word)"<<endl;
    cout << "2. Insert your current word, example: a-p-e" << endl;
    cout << "3. unknown letter can be any characters ( '-' is only a example)\n" << endl;

    cout << "Press Enter To Back >>";
    getline(cin, s);
    getchar();
    return;
}

void ui()
{ 
    cout << "===========[Wordle Helper]============" << endl;
    cout << "||                                  ||" << endl;
    cout << "||   WW            WW HH      HH    ||" << endl;
    cout << "||    WW          WW  HH      HH    ||" << endl;
    cout << "||     WW   WW   WW   HHHHHHHHHH    ||" << endl;
    cout << "||      WW  WW  WW    HH      HH    ||" << endl;
    cout << "||       WW WW WW     HH      HH    ||" << endl;
    cout << "||        WW  WW      HH      HH    ||" << endl;
    cout << "||                                  ||" << endl;
    cout << "======================================" << endl;
    cout << "1. Insert Word" << endl;
    cout << "2. How to use" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose >> ";

}

int main(int argc, char* argv[]) {
    int option = -1;
    string s = "null";
    Database db;;


    do
    {
        ui();
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n');
            option = 0;
        }

        switch (option)
        {
        case 1:
            getchar();
            do {
                cout << "Input Word [must be 5 letter]: ";
                getline(cin, s);
            } while (s.size() < 5 || s.size() > 5);

            insertWord(db,s);

            cout << endl;
            break;

        case 2:
            cout << "case 2" << endl;
            howToUse();
            cout << endl;
            break;
        case 3:
            cout << "exiting program....." << endl;
            break;
        default:
            cout << "Please Input The Correct number (1-3)" << endl;
            break;
        }


    } while (option != 3);

}