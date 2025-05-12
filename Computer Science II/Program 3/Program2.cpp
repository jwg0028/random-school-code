// Name: Jacob Godwin
// Date: 9/14/2022
// Class: CS 221-02
// Purpose: Calculates the FF% and calories burned of a hockey player using user inputed stats
//
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "PlayerList.cpp"


//int add(int x, string file);
// void alphabetize(int n, playerStats* Array[n]);






int main()                                      //main function
{
    system("cls");                              //clears the terminal so it looks nice
    playerStats e1;

    e1.getName();

    int x = 5;

    PlayerList players(5);


    // string dummy;

    ifstream infile;
    infile.open("input.txt");







    return 0;
}