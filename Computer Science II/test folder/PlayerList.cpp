#include "PlayerList.h"
using namespace std;
//***************************************************************************//
/* FILE: PlayerList.cpp
Class: PlayerList
This is the implementation file for the methods defined in class
PlayerList. Please see PlayerList.h for a description of the interface
*/


//---------------------------------------------------------------------------//
// Constructor: Default
// This constructor initializes a PlayerList to a pristine state.
// The index reflects the fact that the internal array is empty.
// The size indicates the maximum capacity when creating the array
//---------------------------------------------------------------------------//	
PlayerList::PlayerList(int maxSize) {
	m_Capacity = maxSize;
	m_Current = 0;
	m_PlayerCount = 0;
	m_TotalCaloriesBurned = 0.0;
	m_Items = new HockeyPlayer[maxSize];   // allocate the storage
}


//---------------------------------------------------------------------------//
// Destructor: Default
// This destructor calls the clear() method when this list ceases to exist
// in a program scope.  Clear will handle deleting all of the necessary memory.
//---------------------------------------------------------------------------//	
PlayerList::~PlayerList() {
	clear();
	if (m_Items != NULL)
		delete[] m_Items;   // free the array
}
//---------------------------------------------------------------------------//
// add(player) : takes the input player and copies it into the list
//---------------------------------------------------------------------------//
bool PlayerList::add(const HockeyPlayer& player) {

	bool success = false;
	int  i = m_PlayerCount;     // use i to search for the insertion point for this player (potential slot)

	if (!isFull()) {
		while (i > 0 && !success)  // while current player is < left one
		{
			if (m_Items[i - 1].compareByName(player) < 0) { // if the item to the left is <, we stop here
				success = true;
			}
			else {
				m_Items[i] = m_Items[i - 1];   // copy left player to current spot
				i--;                           // move left one spot to consider
			}
		}
		m_Items[i] = player; // place the new item where i was found to be
		m_PlayerCount++; // count the addition
		success = true;
	}

	return success;
}

//---------------------------------------------------------------------------//
// resetIteration() - gets this list ready to begin an iteration through
// its data
//---------------------------------------------------------------------------//
void PlayerList::resetIteration() {
	m_Current = 0;    // starts at front of array for data retrieval
}

//---------------------------------------------------------------------------//
// getNext()
// Returns a copy of next item in the iteration. If the list is at the end, 
// do not move the index over anymore
// Returns one hockey player object
//---------------------------------------------------------------------------//
HockeyPlayer PlayerList::getNext() {
	HockeyPlayer temp;
	if (m_Current < m_PlayerCount) {
		temp = m_Items[m_Current];
		m_Current++;
	}
	return temp;
}

//---------------------------------------------------------------------------//
// hasNext()
// Returns true if there are more items in the list to be iterated through
//---------------------------------------------------------------------------//
bool PlayerList::hasNext()
{
	return (m_Current != m_PlayerCount);
}

//---------------------------------------------------------------------------//
// calculate()
// Instructs the list to perform internal, list wide computation(s) 
// Computes the overall team average
//---------------------------------------------------------------------------//
void PlayerList::calculateTotalCaloriesBurned() {
	m_TotalCaloriesBurned = 0.0;
	int i = 0;
	while (i < m_PlayerCount) {
		m_TotalCaloriesBurned = m_TotalCaloriesBurned + m_Items[i].getCaloriesBurned();
		i++;
	}
}
//---------------------------------------------------------------------------//
// getTotalCaloriesBurned() - returns the total calories burned of all players
//---------------------------------------------------------------------------//
float PlayerList::getTotalCaloriesBurned() {
	return m_TotalCaloriesBurned;
}
//---------------------------------------------------------------------------//
// clear() - sets the list to an empty state
//---------------------------------------------------------------------------//
void PlayerList::clear() {
	m_PlayerCount = 0;
	m_Current = 0;
	m_TotalCaloriesBurned = 0.0;
}
//---------------------------------------------------------------------------//
// getCount() - returns the count of players currently in this list
//---------------------------------------------------------------------------//
int  PlayerList::getCount() {
	return m_PlayerCount;
}
//---------------------------------------------------------------------------//
// isEmpty() - returns true if the list is empty, false otherwise 
//---------------------------------------------------------------------------//
bool PlayerList::isEmpty() {
	return (m_PlayerCount == 0);
}
//---------------------------------------------------------------------------//
// isFull() - returns true if the list is full, false otherwise 
//---------------------------------------------------------------------------//
bool PlayerList::isFull() {
	return (m_PlayerCount >= m_Capacity);
}