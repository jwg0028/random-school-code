#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

unsigned int my_numbers[8] = {1, 2, 3 ,4 ,5 ,6 ,7 ,8};
unsigned int your_numbers[8] = {10, 11, 12 ,13 ,14 ,15 ,16 ,17};

int main (void)
{


for(int j = 0; j < 8; j++)
{ 
    your_numbers[j] = my_numbers[j] + your_numbers[j];
}


for(int j = 0; j < 8; j++)
{ 
    cout << your_numbers[j] << endl;
}


return 0;
}

void print_array();