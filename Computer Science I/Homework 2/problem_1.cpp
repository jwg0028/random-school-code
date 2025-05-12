#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int n, r, space;
float averg, add;
int i = 0;

int main (void)
{

system("cls");

cout << "How many grades will you enter?" << endl;
cin >> n;
int grades [n];


cout << "Enter the grades and press enter one at a time" << endl;


i = 0;
while (i < n)
{
    cin >> grades[i];
    i++;
}

i = 0;
while(i < n)
{
    cout << grades[i] << " ";
    i++;
}

cout << endl;

r = grades[0];

i = 0;
while(i < n)
{
    if(r > grades[i])
    {
        r = grades[i];
        space = i;
    }
    i++;
}

system("cls");

cout << "The lowest grade is, " << r << " and will be dropped" << endl;

grades[space] = -1;

i = 0;
while(i < n)
{
    if(grades[i] == -1)
    {
        grades[i] = grades[i+1];
        grades[i+1] = -1;
    }
    i++;
}

n = n-1;

i = 0;
while(i < n)
{
    cout << grades[i] << " ";
    i++;
}

cout << endl;

add = grades[0];

i = 1;
while(i < n)
{
    add = add + grades[i];
    i++;
}

averg = add / (n);

cout << fixed << setprecision(2) << "The average is " << averg << endl;

system("pause");
system("cls");
return 0;
}