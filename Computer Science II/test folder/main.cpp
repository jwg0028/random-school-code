/* File: Program2.cpp
Vidhi Bhatia
CS221 Fall 2022
This program implements the program that uses the PlayerList class.
It opens a file containing many lines of player data, each player is read in from
the data file and added to the PlayerList.

The PlayerList in this version maintains the Players in sorted order by name.

*/

using namespace std;
#include <iostream>	
#include <fstream>
#include <iomanip>

#include "PlayerList.h"


//-----------------------------------------------------------------------------------------------//
// Main program
// Uses a single variable to store a player temporarily until it is added to the list.
// The loop reuses the variable over and over until all lines of the input file have been 
// retrieved.
//-----------------------------------------------------------------------------------------------//

int main(void) {
	string   inFileName, outFileName;		// names of the input and output data files supplied by the user
	ifstream inputFile;						// input file handle
	ofstream outputFile;					// output file handle
	HockeyPlayer  p1;					    // a temporary  object = the current player being read or printed
	PlayerList myTeamRoster(50);			// the list storage

	cout << "Welcome to the hockey player statistics calculator test program.  \n";
	cout << "I am going to read players from an input data file.  You will tell me the names ofyour input and output files.\n";
	cout << "I will store all of the players in a list, ";
	cout << "compute each player's stats and then write the resulting team report \n";
	cout << "to your output file.\n\n";

	cout << "\n\n";


	cout << "Enter the name of your input file:  ";  cin >> inFileName;
	cout << "Enter the name of your output file: ";  cin >> outFileName;

	// opening data files
	inputFile.open(inFileName.c_str());
	if (inputFile.fail()) {
		cout << "Sorry. I could not open your input file - " << inFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}
	outputFile.open(outFileName.c_str());
	if (outputFile.fail()) {
		cout << "Sorry. I could not open your output file - " << outFileName << "-\n";
		cout << "Exiting the program.\n";  return 1;
	}

	cout << "Reading Players from " << inFileName << endl;

	while (!inputFile.eof()) {  // as long as we are not at the end of the file, read a line
		p1.read(inputFile);
		p1.computeStats();
		myTeamRoster.add(p1);   // add this player to the list
	}

	myTeamRoster.calculateTotalCaloriesBurned();  // perform computations on roster
	outputFile << "HOCKEY TEAM REPORT --- " << myTeamRoster.getCount() << " PLAYERS FOUND IN FILE\n";
	outputFile << "TOTAL CALORIES BURNED:  " << fixed << setw(6) << setprecision(1) << myTeamRoster.getTotalCaloriesBurned() << endl;
	outputFile << endl << endl;

	outputFile << "    PLAYER NAME         :       FF%        Calories burned\n";
	outputFile << "---------------------------------------------------------------\n";

	myTeamRoster.resetIteration(); // get ready to visit each student
	while (myTeamRoster.hasNext()) {
		p1 = myTeamRoster.getNext();
		outputFile << setw(23) << p1.getDisplayFullName() << " :    ";
		outputFile << fixed << setw(6) << setprecision(1) << p1.getFenwickForPercentage() << "%";
		outputFile << "     " << setw(6) << setprecision(1) << p1.getCaloriesBurned();
		outputFile << endl;
	}

	cout << "The data has been written to your output file: " << outFileName << endl;

	inputFile.close();
	outputFile.close();

	cout << "\n\n";
	cout << "End of Program 2\n";

	return 0;
}