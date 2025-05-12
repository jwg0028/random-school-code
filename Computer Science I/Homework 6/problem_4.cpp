//
// CS 121 Textbook Example of a Class - Chapter 12.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Create Class timeofday here

class timeofday
{
public:
	timeofday();
	timeofday(int hours, int minutes, int seconds);
	timeofday increment();
	void write();
	bool equal(timeofday othertime);
	bool lessthan(timeofday othertime);
private:
	int hours;
	int minutes;
	int seconds;
};


int main(void) 
{

	// Instantiate a couple of objects of type timeofday
	
	timeofday time1(5, 30, 0);
	timeofday time2;
	// Perform some operations with the objects
	// Write out the times time1 and time2

	cout << "time1 = " ;
	time1.write();
	cout << "time2 = " ;
	time2.write();
	cout << endl;

	// Compare the times time1 and time2 for equality

	if (time1.equal(time2))
		cout << "The times are equal " ;
	else
		cout << "The times are different " << endl;

	// Make the times equal and do the operations again

	time2 = time1; // Agragate copy

	if (time1.equal(time2))
		cout << "The times are equal ";
	else
		cout << "The times are different " << endl;

	// Increment time2 and compare again

	time2 = time2.increment();

	cout << "time1 = " ;
	time1.write();
	cout << "time2 = " ;
	time2.write();
	cout << endl;

	// Compare the times time1 and time2 for equality

	if (time1.equal(time2))
		cout << "The times are equal ";
	else
		cout << "The times are different " << endl;

	// Compare the times using the lessthan function

	if (time1.lessthan(time2))
		cout << "Time1 is less than time2" << endl;
	else
		cout << "Time1 is NOT less than time2" << endl;

	if (time2.lessthan(time1))
		cout << "Time2 is less than time1" << endl;
	else
		cout << "Time2 is NOT less than time1" << endl;

	// Instantiate a time near end of day

	timeofday time3(23, 59, 50);
	cout << "time3 = ";
	time1.write();

	// Increment the time by one second in a loop 

	cout << "Incrementing time1 from 23:59:55 " << endl;
	for (int k = 0; k < 10; k++)
	{
		time3.increment(); // Add one second
		time3.write();
		cout << endl;
	}

	cout << endl << endl;
	system("pause");
}

// Write Code for Constructors Here

timeofday::timeofday()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
};

timeofday::timeofday(int inithours, int initminutes, int initseconds)
{
	hours = inithours;
	minutes = initminutes;
	seconds = initseconds;
};

// ----------------------------------------------------------------- //
// Write the Code for the Member Functions here
// ----------------------------------------------------------------- //

// Function write
void timeofday::write()
{
	char colon = ':';
	cout << setfill('0');
	cout << setw(2) << hours << colon 
		 << setw(2) << minutes << colon
		 << setw(2) << seconds << endl;
	cout << setfill(' ');
};

// Function test Equal
bool timeofday::equal(timeofday othertime)
{
	bool value;

	value = (hours == othertime.hours) &&
		(minutes == othertime.minutes) &&
		(seconds == othertime.seconds);
	return value;
}

// Function Test Less Than

bool timeofday::lessthan(timeofday othertime)
{
	bool value;

	value = (hours < othertime.hours) ||
		(hours == othertime.hours && minutes < othertime.minutes) ||
		(hours == othertime.hours && minutes == othertime.minutes && seconds < othertime.seconds);

	return (value);
}

timeofday timeofday::increment()
{
	timeofday result(hours, minutes, seconds); // Make an instance called result
	result.seconds = result.seconds++;
	if (result.seconds > 59)
	{
		result.seconds = 0;
		result.minutes = result.minutes++;
		if (result.minutes > 59)
		{
			result.minutes = 0;
			result.hours = result.hours++;
			if (result.hours > 23)
			{
				result.hours = 0;
			}
		}
	}
	return result;
}