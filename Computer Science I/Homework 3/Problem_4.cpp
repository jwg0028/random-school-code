#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//initializing variables
string dataline = "";
string extra_string = "", date_s = "", prcp_s = "", tmax_s = "", tmin_s = "";

unsigned int pos_date = 0, pos_prcp = 0, pos_tmax = 0, pos_tmin = 0;

float date = 0, prcp = 0, tmax = 0, tmin = 0;
int input1 = 0, input2 = 0;

//arrays and functions
const unsigned int COL = 4;
const unsigned int ROWS = 4000;
void initialize(float array[][COL], int rows, int col);
void stringarray(string array[ROWS], int rows, int col);
void choice1(float array[][COL], int rows, int col, int find);
void choice2(float array[][COL], int rows, int col, int find1, int find2);
void choice3(string str_array[ROWS], float array[][COL], int rows, int col, string find);
void choice4(string str_array[ROWS], float array[][COL], int rows, int col, string find);
void choice5(string str_array[ROWS], float array[][COL], int rows, int col, string find, int date1, int date2);
float data[ROWS][COL] = {0};
string stations[ROWS] = {""};

ifstream infile;
ofstream outfile;


int main(void)
{
    system("cls");
    cout << "opening file..." << endl;
    infile.open("Final_AL_Weather_station.txt");
    if(!infile){
        cout << "could not open file" << endl;
        system("pause");
        return 1;
    }
    cout << "opened file" << endl;

    getline(infile, dataline);
    pos_prcp = dataline.find("PRCP");
    pos_tmax = dataline.find("TMAX");
    pos_tmin = dataline.find("TMIN");
    pos_date = dataline.find("DATE");
    
    initialize(data, ROWS, COL);
    stringarray(stations, ROWS, COL);

    cout << "What would you like to know?" << endl;
    cout << "1: Total precipitation from all stations on a specific date" << endl;
    cout << "2: Total precipitation from all stations over a period of time" << endl;
    cout << "3: Total precipitation from a specific station(s)" << endl;
    cout << "4: The maximum and minmum temps over the month of March" << endl;
    cout << "5: The maximum, minimum, and average temps over a period of time at specific station" << endl;

    cin >> input1;

    if (input1 == 1)
    {
        system("cls");
        cout << "Enter the date you want(Enter in MMDDYYYY format):" << endl;
        cin >> input1;
        choice1(data, ROWS, COL, input1);
    }
    if (input1 == 2)
    {
        system("cls");
        cout << "Enter the date you want to start at(Enter in MMDDYYYY format):" << endl;
        cin >> input1;
        cout << "Enter the date you want to end with(Enter in MMDDYYYY format):" << endl;
        cin >> input2;
        choice2(data, ROWS, COL, input1, input2);
    }
    if (input1 == 3)
    {
        system("cls");
        while (extra_string != "stop")
        {
            cout << "Enter the name of the station you want the data for(Only enter the city name. Enter 'stop' to quit):" << endl;
            cin >> extra_string;
        if(extra_string == "stop" || extra_string == "STOP")
        {
            break;
        }
            choice3(stations, data, ROWS, COL, extra_string);
        }
    }
    if (input1 == 4)
    {
        system("cls");
        while (extra_string != "stop")
        {
            cout << "Enter the name of the station you want the data for(Only enter the city name. Enter 'stop' to quit):" << endl;
            cin >> extra_string;
        if(extra_string == "stop" || extra_string == "STOP")
        {
            break;
        }
            choice4(stations, data, ROWS, COL, extra_string);
        }
    }
    if (input1 == 5)
    {
        system("cls");
        while (extra_string != "stop")
        {
            cout << "Enter the name of the station you want the data for(Only enter the city name. Enter 'stop' to quit):" << endl;
            cin >> extra_string;
            if(extra_string == "stop" || extra_string == "STOP")
            {
                break;
            }
            cout << "Enter the date you want to start at(Enter in MMDDYYYY format):" << endl;
            cin >> input1;
            cout << "Enter the date you want to end with(Enter in MMDDYYYY format):" << endl;
            cin >> input2;
            choice5(stations, data, ROWS, COL, extra_string, input1, input2);
        }
    }
    

    system("pause");
    system("cls");
    return 0;
}

//infile.seekg(0, std::ios::beg); keep fpr later


void initialize(float array[][COL], int rows, int col)
{
unsigned int i, j;
for (i = 0; i < rows; i++)
{
    
    getline(infile, dataline);

    prcp_s = dataline.substr(pos_prcp, 5);
    tmax_s = dataline.substr(pos_tmax, 5);
    tmin_s = dataline.substr(pos_tmin, 5);
    extra_string = dataline.substr(pos_date, 8);
    
    //fix date format
    date_s = extra_string.substr(5, 4);
    extra_string.erase(4, 4);
    date_s.append(extra_string);
    

    prcp = stof(prcp_s);
    tmax = stof(tmax_s);
    tmin = stof(tmin_s);
    date = stof(date_s);

    array[i][0] = date;
    array[i][1] = prcp;
    array[i][2] = tmax;
    array[i][3] = tmin;
}
return;
}

void stringarray(string array[ROWS], int rows, int col)
{
	infile.clear();
	infile.seekg(0, std::ios::beg);
    getline(infile, dataline);

    unsigned int i, j;
    for (i = 0; i < rows; i++)
    {

        getline(infile, dataline);
        extra_string = dataline.substr(0, 50);

        array[i] = extra_string;

    }


}

//Different choices


//------------------Choice 1------------------
void choice1(float array[][COL], int rows, int col, int find)
{

unsigned int i, j;
for (i = 0; i < rows; i++)
{
   if (array[i][0] == find)
   {
       prcp = prcp + array[i][1];
   }
   
}



cout << "The total precipitation for this date is " << prcp << " inches." << endl;

}


//------------------Choice 2------------------
void choice2(float array[][COL], int rows, int col, int find1, int find2)
{

unsigned int i, j;
for (i = 0; i < rows; i++)
{
   if (array[i][0] >= find1 && array[i][0] <= find2)
   {
       prcp = prcp + array[i][1];
   }
   
}



cout << "The total precipitation for this range is " << prcp << " inches." << endl;

}


//------------------Choice 3------------------
void choice3(string str_array[ROWS], float array[][COL], int rows, int col, string find)
{

prcp = 0;

unsigned int i, j;
for (i = 0; i < rows; i++)
{
    dataline = str_array[i];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US")
    {
        prcp = prcp + array[i][1];
    }
   
}

if(prcp == 0 && dataline.find(find) == std::string::npos || find == "AL" || find == "NUMBER" || find == "2" || find == "US")
{
   cout << "Invalid input: Try again" << endl;
}
else{
   cout << "The total precipitation for this station(s) is " << prcp << " inches." << endl;
}


}


//------------------Choice 4------------------
void choice4(string str_array[ROWS], float array[][COL], int rows, int col, string find)
{
float lowest = 0, highest = 0;
tmax = 0;
tmin = 0;


//Finding the highest and lowest
unsigned int i, j;
for (j = 0; j < rows; j++)
{
    dataline = str_array[j];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US")
    {
        highest = array[j][2];
        lowest = array[j][3];
        break;
    }
   
}



for (i = 0; i < rows; i++)
{
    dataline = str_array[i];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US")
    {
		if (highest < array[i][2])
		{
			highest = array[i][2];
		}
		
		if (lowest > array[i][3])
		{
			lowest = array[i][3];
		}
    }
   
}

j = 0;

//calculating the averages
for (i = 0; i < rows; i++)
{
    dataline = str_array[i];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US")
    {
        tmax = tmax + array[i][2];
        tmin = tmin + array[i][3];
        j++;
    }
   
}


tmax = tmax / j;
tmin = tmin / j;


//printing out stuff
cout << "Highest temperature: " << highest << endl;
cout << "Lowest temperature: " << lowest << endl;
cout << "Average high temperatures: " << tmax << endl;
cout << "Average low temperature: " << tmin << endl;
cout << "Number of records: " << j << endl;
}


//------------------Choice 5------------------
void choice5(string str_array[ROWS], float array[][COL], int rows, int col, string find, int date1, int date2)
{
float lowest = 0, highest = 0;
tmax = 0;
tmin = 0;


//Finding the highest and lowest
unsigned int i, j;
for (j = 0; j < rows; j++)
{
    dataline = str_array[j];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US" && array[j][0] >= date1 && array[j][0] <= date2)
    {
        highest = array[j][2];
        lowest = array[j][3];
        break;
    }
   
}



for (i = 0; i < rows; i++)
{
    dataline = str_array[i];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US" && array[i][0] >= date1 && array[i][0] <= date2)
    {
		if (highest < array[i][2])
		{
			highest = array[i][2];
		}
		
		if (lowest > array[i][3])
		{
			lowest = array[i][3];
		}
    }
   
}

j = 0;

//calculating the averages
for (i = 0; i < rows; i++)
{
    dataline = str_array[i];


    if (dataline.find(find) != std::string::npos && find != "AL" && find != "NUMBER" && find != "2" && find != "US" && array[i][0] >= date1 && array[i][0] <= date2)
    {
        tmax = tmax + array[i][2];
        tmin = tmin + array[i][3];
        j++;
    }
   
}


tmax = tmax / j;
tmin = tmin / j;


//printing out stuff
cout << "Highest temperature: " << highest << endl;
cout << "Lowest temperature: " << lowest << endl;
cout << "Average high temperatures: " << tmax << endl;
cout << "Average low temperature: " << tmin << endl;
cout << "Number of records: " << j << endl;
}