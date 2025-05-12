#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;



class Triangle                                  //initializing class
{
    public:                                     //Public
        void initialize()
        {
            firstname = "Unknown";
            lastname = "Unknown";
            for(int i = 0; i < 7; i++)
            {
                stats[i] = 0;
            }
        }


        void display(int x, int y)
        {

            stats[age] = x;
            stats[missedShotsAgainst] = y;

            //std::cout << stats[age] << endl;
            //std::cout << stats[missedShotsAgainst] << endl;
        }


    private:                                    //declares private variables
    string firstname, lastname;
    int age, shotsTargetFor, shotsTargetAgainst,  missedShotsFor, missedShotsAgainst, met, bodyWeight;
    int stats[7] = {age, shotsTargetFor, shotsTargetAgainst,  missedShotsFor, missedShotsAgainst, met, bodyWeight};
    

};

int main()                                      //main function
{
    Triangle thing;
    int x, y;

    thing.display(x,y);
    cout << x << endl;
    cout << y << endl;

    cout << "word" << endl;


    return 0;
}
