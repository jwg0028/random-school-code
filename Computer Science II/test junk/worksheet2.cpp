#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;



int main()
{
    int *array1 = new int[5];
    int *array2 = new int[5];
    // fill first array with some data
    for (int j = 0; j < 6; j++) 
    {
    array1[j] = j;
    }
    //... user writes some code to do some things with array1...
    // user wants to copy array1 into array2
    array2 = array1;
    // ...user goes on and does other work

    for (int j = 0; j < 6; j++) 
    {
    cout << array1[j] << endl;
    }

    cout << endl;

    for (int j = 0; j < 6; j++) 
    {
    cout << array2[j] << endl;
    }

    return 0;
}

