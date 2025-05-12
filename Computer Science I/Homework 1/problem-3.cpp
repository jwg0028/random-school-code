#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int main(void)
{	
	int x = 0;
	int n = 0;
	int position = 0;
	string sentence = "";
	string subst = "";
	system("CLS");

	cout << "Enter a sentence and a string to count the amount of:" << endl;
	getline(cin, sentence);
	getline(cin, subst);

	while (x < sentence.length())
	{
		sentence.at(x) = tolower(sentence.at(x));
		x++;
	}

	position = sentence.find(subst, position);
	


	while(position != string::npos)
	{
		position = sentence.find(subst, ++position);
		n++;
	}
	cout << "Ran into this " << n << " times." << endl;
	system("pause");

	return 0;
}