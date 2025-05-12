/* File: HockeyPlayer.cpp
   Program 2: Vidhi Bhatia
			  Fall 2022 Solution
   Implementation of the class HockeyPlayer
   All of the methods are contained in this file.
*/
#include "HockeyPlayer.h"

//-----------------------------------------------------------------------------------------------//
// Default Constructor
// Sets numberic values to zeros, and other values to either empty strings or default values
//-----------------------------------------------------------------------------------------------//
HockeyPlayer::HockeyPlayer() {

	m_firstName = "unknown";
	m_lastName = "unknown";
	for (int i = 0; i < 7; i++)
		m_statsArray[i] = 0;
	m_fenwickForPercentage = 0.0;		// set default values in case of no data
	m_caloriesBurned = 0.0;
}
//-----------------------------------------------------------------------------------------------//
// read(input)
// This method reads the Hockey player's data from a single line on an input stream.
// Some special restrictions - the player's first name and last name can each only consist of
// a single word (no embedded spaces), other wise the input will be read in incorrectly.
// There must also be all the statistics data values on the line.
// The order of input is firstname lastname age shotsTargetFor shotsTargetAgainst  missedShotsFor missedShotsAgainst met bodyWeight
//
// NOTE: This assumes the input is on the stream and is valid data.  We can update this with
// more error checking later.
//
// Parameters:
//    input   : a variable representing the input stream to read data from
//-----------------------------------------------------------------------------------------------//
void HockeyPlayer::read(istream& input) {
	input >> m_firstName >> m_lastName;
	for (int i = 0; i < 7; i++)
		input >> m_statsArray[i];				// read in each stat from input stream
}
//-----------------------------------------------------------------------------------------------//
// getFullName()
// This get method is used to get the player's full name built as a single string from the
// names stored in the class.
//-----------------------------------------------------------------------------------------------//
string HockeyPlayer::getDisplayFullName() {
	return m_lastName + ", " + m_firstName;
}
//-----------------------------------------------------------------------------------------------//
// getLowerCaseName()
// This get method is used to get the player's full name in lowercase
//-----------------------------------------------------------------------------------------------//
string HockeyPlayer::getLowerCaseName() const {
	string name = m_lastName + m_firstName;
	for (int i = 0; i < name.size(); i++) {
		name.at(i) = tolower(name.at(i));
	}
	return name;
}
//-----------------------------------------------------------------------------------------------//
// compareByName()
// case insensitive comparison of players by their full name, returns
// 0 if the same, -1 if the first is less than the other, +1 if this is greater than the other 
//-----------------------------------------------------------------------------------------------//
int HockeyPlayer::compareByName(const HockeyPlayer& other) const {
	string myfullname, otherfullname;   // useful to simplify comparisons
	myfullname = getLowerCaseName();
	otherfullname = other.getLowerCaseName();

	return strcmp(myfullname.c_str(), otherfullname.c_str());  // strcmp compares 2 c-style char strings case insensitive
}
//------------------------------------------------------------------------------
// getFirstName() : returns string value
// gets the internal firstName attribute according to value entered by the user
//------------------------------------------------------------------------------
string HockeyPlayer::getFirstName() { return m_firstName; }
//------------------------------------------------------------------------------
// getLastName() : returns string value
// gets the internal lastName attribute according to value entered by the user
//------------------------------------------------------------------------------
string HockeyPlayer::getLastName() { return m_lastName; }
//------------------------------------------------------------------------------
// getAge() : returns int value
// gets the value of Age from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getAge() { return m_statsArray[0]; }
//------------------------------------------------------------------------------
// getShotsTargetFor() : returns int value
// gets the value of Shots Target For from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getShotsTargetFor() { return m_statsArray[1]; }
//------------------------------------------------------------------------------
// getShotsTargetAgainst() : returns int value
// gets the value of Shots Target Against from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getShotsTargetAgainst() { return m_statsArray[2]; }
//------------------------------------------------------------------------------
// getMissedTargetFor() : returns int value
// gets the value of Missed Shots For from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getMissedShotsFor() { return m_statsArray[3]; }
//------------------------------------------------------------------------------
// getMissedTargetAgainst() : returns int value
// gets the value of Missed Shots Against from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getMissedShotsAgainst() { return m_statsArray[4]; }
//------------------------------------------------------------------------------
// getMET() : returns int value
// gets the value of MET from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getMET() { return m_statsArray[5]; }
//------------------------------------------------------------------------------
// getBodyWeight() : returns int value
// gets the value of Body Weight from internal statsArray attribute according to
// value entered by the user
//------------------------------------------------------------------------------
int HockeyPlayer::getBodyWeight() { return m_statsArray[6]; }
//------------------------------------------------------------------------------
// getFenwickForPercentage() : returns float value
// gets the calculated value of Fenwick For Percentage according to
// value entered by the user
//------------------------------------------------------------------------------
float HockeyPlayer::getFenwickForPercentage() {
	return m_fenwickForPercentage * 100;
}
//------------------------------------------------------------------------------
// getCaloriesBurned() : returns float value
// gets the calculated value of Calories Burned according to
// value entered by the user
//------------------------------------------------------------------------------
float HockeyPlayer::getCaloriesBurned() {
	return m_caloriesBurned;
}
//-----------------------------------------------------------------------------------------------//
// computeStats()
// This function currently computes the player's fenwick for percentage and calories burned.
//-----------------------------------------------------------------------------------------------//
void HockeyPlayer::computeStats() {

	float m_sumFor = getShotsTargetFor() + getMissedShotsFor();
	float m_sumAgainst = getShotsTargetAgainst() + getMissedShotsAgainst();
	m_fenwickForPercentage = m_sumFor / (m_sumFor - m_sumAgainst);


	m_caloriesBurned = getMET() * getBodyWeight() * 3.5;
	m_caloriesBurned = (float)m_caloriesBurned / 200;
}

