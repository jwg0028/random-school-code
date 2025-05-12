#ifndef PlayerList_H
#define PlayerList_H
#include <string>
#include "playerStats.cpp"
using namespace std;
//***************************************************************************//
/* FILE: PlayerList.h    
Class: PlayerList
This class maintains a player list with flexible capacity specified at
creation time.  It uses a dynamically allocated array for storage

Public Methods:
PlayerList	- default constructor
add     	- add a player to the list
resetIteration - to start at the beginning of the list array
getNext     - get a copy of the next player in the list
hasNext     - true/false if there is another player to get
clear		- initialize the list to a clean state, including deleting the allocated nodes
getCount    - gets the count of items in the list
isEmpty     - test to see if list is empty
isFull      - test to see if list is full
calculateTotalCaloriesBurned   - perform computations related to the calories burned
getTotalCaloriesBurned  - get the total calories burned of all players
~PlayerList - default deconstructor

*/


class PlayerList {
	playerStats* m_Items;				// list of players, size determined at creation time
	int      m_PlayerCount;				// number of items stored in the list
	int      m_Current;					// index of the current player in a list iteration operations
	int      m_Capacity;				// limit to size of list
	float    m_TotalCaloriesBurned;     // overall team total calories burned

public:
	PlayerList(int);
	// ~PlayerList();

	bool	 add(const playerStats&);

	void	 resetIteration();
	playerStats getNext();
	bool	 hasNext();

	void	 clear();
	int		 getCount();
	bool	 isEmpty();
	bool     isFull();

	void	 calculateTotalCaloriesBurned();
	float    getTotalCaloriesBurned();
};

#endif