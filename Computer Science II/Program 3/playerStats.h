#ifndef playerStats_H
#define playerStats_H


using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class playerStats
{
    
    string firstname, lastname;
    int age, shotsTargetFor, shotsTargetAgainst,  missedShotsFor, missedShotsAgainst, met, bodyWeight;
    int* stats[7] = {&age, &shotsTargetFor, &shotsTargetAgainst, &missedShotsFor, &missedShotsAgainst, &met, &bodyWeight};

    public:
    ofstream outfile;
    playerStats();
    // ~playerStats();
    void initializeFile(int n, double x);
    void fileOutput();
    void closeFile();
    void setVariables(istream& input);
    double calculateFF();
    double calculateCal();
    char getName();

};

#endif