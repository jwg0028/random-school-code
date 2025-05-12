/* File: HockeyPlayer.h
   Program 2: Vidhi Bhatia
              Fall 2022 Solutiom
   The interface and structure definition of the HockeyPlayer class
   A few additions have been made since the program 1 version. This one
   adds a compareByName function to use for ordering.

*/

using namespace std;
#include <iostream>			// used for data streams
#include <cstring>
#include <string>

class HockeyPlayer {
    string m_firstName;              // First Name of hockey player
    string m_lastName;               // Last Name of hockey player
    float  m_fenwickForPercentage;   // stores calculated value of Fenwick For percentage
    float  m_caloriesBurned;         // stores calculated value of Calories Burned
    int    m_statsArray[7];          // hardcoding the size of the stats array for 7 raw data values
    //m_statsArray[0]           // stores value of Age   
    //m_statsArray[1]           // stores value of Shots Target For
    //m_statsArray[2]           // stores value of Shots Target Against
    //m_statsArray[3]           // stores value of Missed Shots For
    //m_statsArray[4]           // stores value of Missed Shots Against
    //m_statsArray[5]           // stores value of MET
    //m_statsArray[6]           // stores value of Body Weight
public:
    HockeyPlayer();					 // default constructor - sets all data to empty/default values
    void read(istream& input);		 // read a player's stats from an input stream (file or keyboard)
    void computeStats();			    // instructs the class object to compute its stats based on raw data

    // other interface methods required for get/set as needed
    string getDisplayFullName();
    string getFirstName();
    string getLastName();
    int getAge();
    int getShotsTargetFor();
    int getShotsTargetAgainst();
    int getMissedShotsFor();
    int getMissedShotsAgainst();
    int getMET();
    int getBodyWeight();
    float getFenwickForPercentage();
    float getCaloriesBurned();

    string getLowerCaseName() const;
    
    int compareByName(const HockeyPlayer& other) const;
};

