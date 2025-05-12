class playerStats                                   //initializing class
{
    public:                                         //Public
        ofstream outfile;

        void initialize()                           //Resets the variables and strings when called
        {
            firstname = "Unknown";
            lastname = "Unknown";
            for(int i = 0; i < 7; i++)              //all of the variables are in an array. This just sets everything in the array to be 0 (which would be all variables used in the class)
            {
                *stats[i] = 0;
            }
            
        }
        
        void initializeFile(int n, double x)
        {
            outfile.open("output.txt");
            outfile.clear();
            outfile << "BASKETBALL TEAM REPORT --- " << n <<" PLAYERS FOUND IN FILE\nTOTAL CALORIES BURNED: " << x << "\n\n";
            outfile << "PLAYER NAME              :  FF%        Calories burned  \n";
            outfile << "----------------------------------------------------------" << endl;
        }

        void fileOutput()
        {
            double x, y;
            outfile.open("output.txt", ios::app);
            lastname = lastname + ", " + firstname;
            outfile << left << setw(25) << lastname << setw(3) << ":";

            //27

            x = ((((double)shotsTargetFor + (double)missedShotsFor)/(((double)shotsTargetFor + (double)missedShotsFor) - ((double)shotsTargetAgainst + (double)missedShotsAgainst))) * 100.00);
            y = ((((double)met * (double)bodyWeight) * 3.5)/(200));

            outfile << setw(11) << x;
            outfile << y;

            outfile << "\n";
            outfile.close();
        }

        void closeFile()
        {
            outfile.close();
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



        char getName()                            //Gets the name that is stored to be used in the main function
        {
            char c = lastname[0];
            c = tolower(c);
            cout << c;
            return c;
        }


    private:                                        //declares private variables that contain the player stats and name
    
    string firstname, lastname;
    int age, shotsTargetFor, shotsTargetAgainst,  missedShotsFor, missedShotsAgainst, met, bodyWeight;
    int* stats[7] = {&age, &shotsTargetFor, &shotsTargetAgainst, &missedShotsFor, &missedShotsAgainst, &met, &bodyWeight};
    
    

};