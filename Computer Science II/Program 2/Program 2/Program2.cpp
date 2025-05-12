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

#include "playerStats.h"

int add(int x, string file);
// void alphabetize(int n, playerStats* Array[n]);






int main()                                      //main function
{
    system("cls");                              //clears the terminal so it looks nice
    string dataline, inputFile, outputFile;
    int n = 0;

    cout << "Enter the input file name";
    cin >> inputFile;

    n = add(n, inputFile);

    cout << n << endl;

    playerStats playerData;
    double x, y, tc;                                //doubles that are used for displaying the calculated data
    tc = 0;
    

    ifstream infile;
    ofstream outfile;

    infile.open(inputFile);


    playerStats* dynamicArray;
    dynamicArray = new playerStats[n];



    
    infile.clear();
    infile.seekg(0, ios::beg);
    

    
    for (int i = 0; i < n; i++)
    {
        dynamicArray[i].initialize();
        dynamicArray[i].setVariables(getline(infile, dataline));
    }




    for (int i = 0; i < n; i++)
    {
        tc = tc + dynamicArray[i].calculateCal(y);
    }

    playerData.initializeFile(n, tc);

    for (int i = 0; i < n; i++)
    {
        dynamicArray[i].fileOutput();
    }
    
    
    system("pause");


    cout << "Thank you for your time." << endl;                  //Goodbye message
    infile.close();
    return 0;
}

int add(int x, string file)
{
    ifstream infile;
    string data;
    infile.open(file);


    
    while (!infile.eof())
    {
        getline(infile, data);
        x++;
    }
    infile.close();
    return x - 1;
}



// void alphabetize(int n, playerStats* Array[n])
// {
//     playerStats* dummyArray;
//     dummyArray = new playerStats[n];
//     string name1, name2;
//     for (int i = 0; i < n; i++)
//     {
//         dummyArray[i] = Array[i];
//     }
// }