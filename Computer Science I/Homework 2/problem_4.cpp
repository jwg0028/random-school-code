#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


float C, F, K;


int main (void)
{

system("cls");

ofstream table;
ifstream temps;

table.open("Table.txt");
temps.open("temps.txt");

system("cls");

if(!temps)
{
    cout << "Error" << endl;
    system("pause");
    return 1;
}
else{
    cout << "input file opened" << endl;
}
if(!table)
{
    cout << "Error opening output file" << endl;
    system("pause");
    return 1;
}
else{
    cout << "output file opened" << endl;
}



while(!temps.eof())
{
    temps >> C;

    F = (9.0/5.0) * C + 32.0;
    K = C + 273.15;

    table << left << fixed << setprecision(2) << setw(15) << C << setw(15) << F << setw(15) << K << endl;
    cout << left << fixed << setprecision(2) << setw(15) << C << setw(15) << F << setw(15) << K << endl;
}



system("pause");
system("cls");
return 0;
}