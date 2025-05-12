// #pragma once
#include "playerstats.cpp"

//-------------------------------------------------------------------------
// Class EventList - Ordered List Version 2
// File: EventList.h
// This verison of the EventList is ordered by the dates in events.
// 
// The only change from V1 is that the add method now uses an overloaded
// operator < to compare two events.
//------------------------------------------------------------------------
class EventList {
	playerStats*   m_items;  // to be allocated as an array of events
	int              m_count;  // the count of elements used up in the list
	int              m_capacity;   // the max capacity (size) of the array
	int              m_current;    // used to keep track of the current item in an iteration pass
public:
	EventList(int size);
	~EventList();
	bool isEmpty();
	bool isFull();
	int getLength();
	bool add(const playerStats& e);
	bool remove(const playerStats& e);

	// iterator support
	bool hasNext();
	playerStats getNext();
	void resetIteration();
};