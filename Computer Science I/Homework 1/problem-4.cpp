#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main(void)
{	
	system("CLS");
	int hour;
	string time = "";
	string conversion = "";
	string period = "";

	cout << "Enter your time in 12 hour format (HH:MM:SS AM/PM)" << endl;
	getline(cin, time);

	if(time.find("PM", 9) != string::npos)
	{
		period = time.substr(0, 2);
		hour = stoi(period);
		hour = hour + 12;
		string h = to_string(hour);

		conversion.insert(0, time);
		conversion.erase(9, 3);

		conversion.replace(0, 2, h);
		cout << "Your time in 24 hour format is " << conversion << endl;
	}
	else
	{
		time.erase(9, 3);
		cout << "Your time in 24 hour format is " << time << endl;
	}

	system("pause");



	return 0;
}