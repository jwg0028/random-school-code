#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main(void)
{
	double PI_D = 3.14159256359;
	float PI_F = 3.14159256359;
	
	
	//setting the justificaton
	cout << left << fixed << setw(15);


	//clear screen
	system("CLS");

	cout << "     DOUBLE" << "      FLOAT" << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << "-------" << setw(15) << setfill('-') << setprecision(i + 1) << PI_D << PI_F << endl;
	}

	system("pause");
	system("CLS");

	return 0;
}