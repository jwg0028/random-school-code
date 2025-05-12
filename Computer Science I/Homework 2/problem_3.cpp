#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string number1 = "",number2 = "", buffer = "", sentence = "";
float n1, n2;
int check = 0, y = 0;

int main(void)
{
	system("cls");

	cout << "What numbers would you like to add?" << endl;
	getline(cin, sentence);

	for (int i = 0; i < sentence.length(); i++)
	{
		if(isdigit(sentence[i]) || ispunct(sentence[i]))
		{
			buffer = sentence.substr(i, 1);

        	number1.insert(y, buffer);
			y++;
		

		if(isdigit(sentence[i]) && isspace(sentence[i + 1]) && check == 0)
		{
			number2 = number1;
			number1.clear();
			check++;
			y = 0;
		}
		}
	}

	n1 = stof(number1);
	n2 = stof(number2);

	n1 = n1 + n2;
	
	cout << fixed << setprecision(3);

	cout << "The sum of " << number2 << " and " << number1 << " is " << n1 << endl;

	system("pause");
	system("CLS");

	return 0;
}