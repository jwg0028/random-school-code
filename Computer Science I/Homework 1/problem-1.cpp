#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main(void)
{
	float x, y;
	float result;

	//clear screen and ask for input for equation 1
	system("CLS");
	cout << "Input the value of x in the equation 3x^2 + 5x + 1" << endl;
	cin >> x;

	result = 3*x*x + 5*x + 1;
	cout << fixed << setprecision(3) << result << endl;
	system("pause");

	//Equation 2
	system("CLS");
	cout << "Input the value of x in the equation (x^2 - 12x + 27) / (x - 6)^2" << endl;
	cin >> x;

	result = (x*x - 12*x + 27) / ((x - 6) * (x-6));
	cout << fixed << setprecision(3) << result << endl;
	system("pause");

	//Equation 3
	system("CLS");
	cout << "Input the value of x in the equation ((x^2 + 3) / (y^3)) + ((x + 2) / (y^2)) + (1 / y)" << endl;
	cin >> x >> y;

	result = ((x*x + 3) / (y*y*y)) + ((x + 2) / (y*y)) + (1 / y);
	cout << fixed << setprecision(3) << result << endl;


	return 0;
}