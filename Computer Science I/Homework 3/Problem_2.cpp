#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Variables

	string dataline = "";
	string date_s = "", prcp_s = "", tmax_s = "", tmin_s = "";

	unsigned int pos_date = 0, pos_mdpr = 0, pos_station = 0, pos_prcp = 0, pos_tmax = 0, pos_tmin = 0;

	float date = 0, prcp = 0, tmax = 0, tmin = 0; // Real types for temps

	ifstream infile; // Input file pointer
	ofstream outfile; // Output file pointer

	cout << "WEATHER STATION DATA" << endl;
	cout << "Open the data file." << endl;
	infile.open("Filtered_AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
	}
		cout << "Weather data file opened." << endl;

	cout << "Open the filtered data file." << endl;
	outfile.open("Fixed_AL_Weather_station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		system("pause");
		return 2;
	}
	cout << "Copy of output file opened." << endl;

	getline(infile, dataline);

	//Find where the date ends for later
	pos_mdpr = dataline.find("MDPR");

	// Use firest line of file (header) to find max and min temp columns

	

	pos_prcp = dataline.find("PRCP");
	if (pos_prcp <= dataline.length())
	{
		cout << "PRCP begins at column: " << pos_prcp << endl;
	}
	else
	{
		cout << "PRCP was not found - terminating." << endl;
		system("pause");
		return 3;
	}

	pos_tmax = dataline.find("TMAX");
	if (pos_tmax <= dataline.length())
	{
		cout << "TMAX begins at column: " << pos_tmax << endl;
	}
	else
	{
		cout << "TMAX was not found - terminating." << endl;
		system("pause");
		return 3;
	}

    pos_tmin = dataline.find("TMIN");
	if (pos_tmin <= dataline.length())
	{
		cout << "TMIN begins at column: " << pos_tmin << endl;
	}
	else
	{
		cout << "TMIN was not found - terminating." << endl;
		system("pause");
		return 4;
	}

    //remove station number
	pos_date = dataline.find("DATE");
    pos_station = dataline.find("STATION_NAME");
    dataline.erase(0, pos_station);

    outfile << fixed << left << setprecision(2) << setw(55) << "STATION_NAME" << setw(15) << "DATE" << setw(10) << "PRCP" << setw(10) << "TMAX" << setw(10) << "TMIN" << endl;

	getline(infile, dataline);


	// Read the remaining lines with data
	while (!infile.eof())
	{
		


		getline(infile, dataline);
		
		date_s = dataline.substr(pos_date, 8);
		prcp_s = dataline.substr(pos_prcp, 5);
		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);

		dataline.erase(pos_date, 60000);
		dataline.erase(0, pos_station);

		
		char ch1 = dataline[0];
		while (isspace(ch1))
		{
			dataline.erase(0, 1);
			ch1 = dataline[0];
		}


		
		

		
		date = stof(date_s);
        prcp = stof(prcp_s);
		tmax = stof(tmax_s);
		tmin = stof(tmin_s);

		for (int i = 0; i < 100; i++)
		{
			dataline.append(" ");
		}
		
	

		tmax = tmax / 10;
		tmax = (tmax * 1.8) + 32;
		tmin = tmin / 10;
		tmin = (tmin * 1.8) + 32;

		stringstream max, min;

		max << tmax;
		tmax_s = max.str();

		min << tmin;
		tmin_s = min.str();


		dataline.insert(55, date_s);
		dataline.insert(70, prcp_s);
		dataline.insert(80, tmax_s);
		dataline.insert(90, tmin_s);

		

		outfile << fixed << dataline << endl;

	}
	cout << "Filtered data file created. " << endl;

	// Close the files
	infile.close();
	outfile.close();

	
	system("pause");
	return 0;
}