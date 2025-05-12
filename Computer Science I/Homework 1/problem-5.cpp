#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main(void)
{	
	float start;
	float end;
	float i;
	float x = 0;
	float kelvin;
	float fahrenheit;
	system("CLS");

	cout << "Enter the starting temperature, ending temperature, and value to increment by (all in celsius):" << endl;
	cin >> start >> end >> i;

	system("CLS");

	x = start;

	cout << "WHILE LOOP" << endl;

	while(x <= end)
	{
		fahrenheit = ((9.0/5.0) * x) + 32.0;
		kelvin = x + 273.15;
		cout << fixed << left << setw(10) << setprecision(2) << x << setw(10) << fahrenheit  << setw(10) << kelvin << endl;

		x = x + i;
	}

	system("pause");
	system("CLS");

	cout << "DO WHILE LOOP" << endl;

	x = start;

	do
	{
		fahrenheit = ((9.0/5.0) * x) + 32.0;
		kelvin = x + 273.15;
		cout << fixed << left << setw(10) << setprecision(2) << x << setw(10) << fahrenheit  << setw(10) << kelvin << endl;

		x = x + i;
	} while (x <= end);
	
	system("pause");
	system("CLS");

	cout << "FOR LOOP" << endl;

	for(float y = start; y <= end; y = y + i)
	{
		fahrenheit = ((9.0/5.0) * y) + 32.0;
		kelvin = y + 273.15;
		cout << fixed << left << setw(10) << setprecision(2) << y << setw(10) << fahrenheit  << setw(10) << kelvin << endl;
	}

	system("pause");
	system("CLS");

	return 0;
}