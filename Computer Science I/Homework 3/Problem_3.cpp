#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

int num = 1;

int main(void)
{	
	system("cls");

	// Initializing variables
	char highest_c[50], lowest_c[50];

	string dataline = "";
	string tmax_s = "", tmin_s = "";

	unsigned int pos_tmax = 0, pos_tmin = 0;

	float highest = 0, lowest = 0, tmax = 0, tmin = 0;


	ifstream infile;

	cout << "WEATHER STATION HIGHEST AND LOWEST VALUES" << endl;
	cout << "Opening Input File..." << endl;
    //need to change this address if your going to run the code
	infile.open("Fixed_AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
	}
	cout << "Weather data file opened." << endl;

    
	getline(infile, dataline);

	pos_tmax = dataline.find("TMAX");
    pos_tmin = dataline.find("TMIN");


	getline(infile, dataline);

	tmax_s = dataline.substr(pos_tmax, 5);
	tmax = stof(tmax_s);
	highest = tmax;

	tmin_s = dataline.substr(pos_tmin, 5);
	tmin = stof(tmin_s);
	lowest = tmin;

    
	while (getline(infile, dataline))
	{

		getline(infile, dataline);

		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);
		
		tmax = stof(tmax_s);
		tmin = stof(tmin_s);

		
		if (highest < tmax)
		{
			memset(highest_c, 0, 50);
			dataline.copy(highest_c, 40);
			highest = tmax;
		}
		
		if (lowest > tmin)
		{
			memset(lowest_c, 0, 50);
			dataline.copy(lowest_c, 40);
			lowest = tmin;
		}



	}


	infile.clear();
	infile.seekg(0, std::ios::beg);

	cout << "HIGHEST VALUES" << endl;
	//run through again to check repeat values
	while (getline(infile, dataline))
	{
		getline(infile, dataline);

		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);
		
		tmax = stof(tmax_s);
		tmin = stof(tmin_s);

		
		if (highest == tmax)
		{
			memset(highest_c, 0, 50);
			dataline.copy(highest_c, 40);
			highest = tmax;
			cout << left << setprecision(2) << setw(55) << fixed << highest_c << highest << endl;
		}

	}


	infile.clear();
	infile.seekg(0, std::ios::beg);

	cout << "LOWEST VALUES" << endl;
	//run through again to check repeat values
	while (getline(infile, dataline))
	{
		getline(infile, dataline);

		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);
		
		tmax = stof(tmax_s);
		tmin = stof(tmin_s);

			
		if (lowest == tmin)
		{
			memset(lowest_c, 0, 50);
			dataline.copy(lowest_c, 40);
			lowest = tmin;
			cout << left << setprecision(2) << setw(55) << lowest_c << lowest << endl;
		}
	}


	
    infile.close();
	system("pause");
	return 0;
}