#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int x = 0, y = 0, length;
string sentence = "";
string reversed = "";
string letter = "";

int main (void)
{

system("cls");

cout << "Enter a sentence to reverse: ";
getline(cin, sentence);
cout << "Normal: " << sentence << endl;

length = sentence.length();

while(x <= length)
{
    if(sentence.substr(x, 1) == " ")
    {
        y = 0;

        letter = sentence.substr(x, 1);

        reversed.insert(y, letter);
    }
    else{

        letter = sentence.substr(x, 1);

        reversed.insert(y, letter);

        y++;
    }


    x++;
}

cout << "Reversed: " << reversed << endl;

system("pause");
system("cls");
return 0;
}