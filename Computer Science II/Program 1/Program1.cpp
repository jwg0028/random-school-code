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



class playerStats                                   //initializing class
{
    public:                                         //Public
        void initialize()                           //Resets the variables and strings when called
        {
            firstname = "Unknown";
            lastname = "Unknown";
            for(int i = 0; i < 7; i++)              //all of the variables are in an array. This just sets everything in the array to be 0 (which would be all variables used in the class)
            {
                *stats[i] = 0;
            }
            
        }

        void setVariables(istream& input)           //Passes through user input to define every variable and string in the class
        {
            input >> firstname;
            input >> lastname;

            for(int i = 0; i < 7; i++)
            {
                input >> *stats[i];
            }


        }

        double calculateFF(double x)                //Calculates the FF% using the inputed variables
        {
            x = ((((double)shotsTargetFor + (double)missedShotsFor)/(((double)shotsTargetFor + (double)missedShotsFor) - ((double)shotsTargetAgainst + (double)missedShotsAgainst))) * 100.00);
            return x;
        }

        double calculateCal(double y)               //Calculates the burned calories using the inputed variables
        {
            y = ((((double)met * (double)bodyWeight) * 3.5)/(200));
            return y;
        }

        string getName()                            //Gets the name that is stored to be used in the main function
        {
            return firstname + " " + lastname;
        }


    private:                                        //declares private variables that contain the player stats and name
    string firstname, lastname;
    int age, shotsTargetFor, shotsTargetAgainst,  missedShotsFor, missedShotsAgainst, met, bodyWeight;
    int* stats[7] = {&age, &shotsTargetFor, &shotsTargetAgainst, &missedShotsFor, &missedShotsAgainst, &met, &bodyWeight};

    

};

int main()                                      //main function
{
    system("cls");                              //clears the terminal so it looks nice

    playerStats playerData;
    double x, y;                                //doubles that are used for displaying the calculated data
    char i = 'y';                               //Char used for user input to decide if the program will run again

    cout << "welcome to the hockey player test program." << endl
    << "When prompted, please enter the player's data in the form of " << endl
    << "Firstname Lastname Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET BodyWeight" << endl;


    while (i == 'y' || i == 'Y')                //While loop where all the actual code happens
    {
        cout << "Enter Player Data: ";

        playerData.initialize();
        playerData.setVariables(cin);

        x = playerData.calculateFF(x);
        y = playerData.calculateCal(y);
        cout << fixed << setprecision(1) << playerData.getName() << "'s FF% = " << x << " and calories burned = " << y << endl;

        cout << "Do you wish to test another [y/n]? ";

        cin >> i;
    }
    

    cout << "Thank you for your time." << endl;                  //Goodbye message



    


    return 0;
}
