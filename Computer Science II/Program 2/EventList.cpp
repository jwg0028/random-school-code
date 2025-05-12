//-------------------------------------------------------------------------
// Class EventList - Ordered List Version 2
// File: EventList.cpp
// This verison of the EventList is ordered by the dates in events.
// 
// The only change from V1 is that the add method now uses an overloaded
// operator < to compare two events.
//------------------------------------------------------------------------
#include "EventList.h"

//-----------------------------------------------------------------------------
// Constructor to create list with a given size
//-----------------------------------------------------------------------------
EventList::EventList(int size)
{
	if (size < 1) size = 10;   // just to prevent bad data from tricky user

	m_items = new CalendarEvent[size];		// allocate the array
	
	m_count = 0;						    // a count of 0 means 0 items are stored
	m_capacity = size;                      // saved capacity tells us the max size of this array
	m_current = 0;                          // start of iteration
}
//----------------------------------------------------------------------------
// Destructor
// A class can have at most 1 default destructor
//----------------------------------------------------------------------------
EventList::~EventList() {
	if (m_items != NULL) {   // if memory was allocated then free it
		delete[] m_items;
	}
}
//----------------------------------------------------------------------------
// isEmpty()  returns true if this list is empty
//----------------------------------------------------------------------------
bool EventList::isEmpty() {
	return m_count == 0;
}
//----------------------------------------------------------------------------
// isFull()  returns true if this list is full
//----------------------------------------------------------------------------
bool EventList::isFull() {
	return m_count >= m_capacity;
}
//----------------------------------------------------------------------------
// getLength()  returns the count of values stored in the array
//----------------------------------------------------------------------------
int EventList::getLength() {
	return m_count;
}

//----------------------------------------------------------------------------
// add(e)  adds the event, e, to this list, returns true if successful
// THIS VERSION moves items over by comparing the new date (e) to the existing
// dates in the list. Each date is moved over 1 spot until the proper slot for
// event (e) is found.
// VERSION 2: UPDATED TO USE OVERLOADED OPERATOR FOR <
//----------------------------------------------------------------------------
bool EventList::add(const playerStats& e) {
	bool success = false;
	int  i;
	if (m_count < m_capacity) { // check for room in array
		i = m_count;   // potential slot
		while (i > 0 && !success) {
			if (m_items[i - 1] < e)   // if the item to the left is <, we stop here
				success = true;
			else {
				m_items[i] = m_items[i - 1];   // move the left item over to make room and try again
				i--;
			}
		}
		m_items[i] = e;     // place the new item where i was found to be
		m_count++;
		success = true;     // it's possible success is still false if i == 0
	}

	return success;
}

//----------------------------------------------------------------------------
// remove(e)  removes the first element with the date stored in e from the
// list and returns true if successful
// This version maintains an order by shifting the remaining values to the
// left when an item in the list needs to be removed.
//----------------------------------------------------------------------------
bool EventList::remove(const playerStats& e) {
	bool success = false;     // will become true if the event is found in list
	int  i = 0;               // will contain the index of the item located in list
	while (i < m_count && !success) {
		if (m_items[i].equals(e)) { // found it - stop the loop
			success = true;
		}
		else {
			i++;
		}
	}

	// if we get here and success is true, then we found the item. WE need to shift all of
	// the items to the right down by 1 slot.
	if (success) {
		m_count--;
		while (i < m_count) {
			m_items[i] = m_items[i + 1];
			i++;
		}
	}

	return success;
}


//-----------------------------------------------------------------------------
// hasNext() used with iteration, returns true if there are still more items
// to get from the list
//-----------------------------------------------------------------------------
bool EventList::hasNext() {
	return m_current < m_count;    // true if the iteration index is less than the max
}

//-----------------------------------------------------------------------------
// getNext() used with iteration, returns a copy of the next item in the list
//-----------------------------------------------------------------------------
playerStats EventList::getNext() {
	playerStats e;
	if (hasNext()) {
		e = m_items[m_current];
		m_current++;                   // move the current index over for the next get
	}
	return e;
}

//-----------------------------------------------------------------------------
// resetIteration() used with iteration, sets the list back to its beginning
// for another iteration pass
//-----------------------------------------------------------------------------
void EventList::resetIteration() {
	m_current = 0;
}