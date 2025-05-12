//I pretty much just used your code but modified it to fit the requirements. 
//Not sure if that was okay or not.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Initializing variables

	string dataline = "";
	string prcp_s = "", tmax_s = "", tmin_s = "";

	unsigned int pos_prcp = 0, pos_tmax = 0, pos_tmin = 0;

	float prcp = 0, tmax = 0, tmin = 0;
	int bad_records = 0;

	ifstream infile;
	ofstream outfile; 

	cout << "WEATHER STATION DATA" << endl;
	cout << "Open the data file." << endl;

	infile.open("AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
	}
		cout << "Weather data file opened." << endl;

	cout << "Open the filtered data file." << endl;
	outfile.open("Filtered_AL_Weather_station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		system("pause");
		return 2;
	}
	cout << "Copy of output file opened." << endl;

	cout << "Use the first line of the file to find the column positions. " << endl;
	getline(infile, dataline);
	outfile << dataline << endl;

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


	cout << "Read the second line from the file - dashes. " << endl;
    getline(infile, dataline);
	outfile << dataline << endl;

	while (!infile.eof())
	{
		getline(infile, dataline);


		prcp_s = dataline.substr(pos_prcp, 5);
		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);




        prcp = stof(prcp_s);
		tmax = stof(tmax_s);
		tmin = stof(tmin_s);

		

		if (prcp != -9999 && tmax != -9999 && tmin != -9999)
        {
			outfile << dataline << endl;
        }
		else{
			bad_records++;
        }

	}
	cout << "Filtered data file created. " << endl;


	infile.close();
	outfile.close();

	cout << "There were " << bad_records << " bad records for tmax and tmin." << endl;

	cout << "\n\n";
	system("pause");
	return 0;
}