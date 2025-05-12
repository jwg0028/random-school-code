#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define SKIP2 cout << endl << endl;

using namespace std;


string dataline = "", extra = "";
int k;

struct date
{
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

struct tyme //If I spell time correctly it doesn't recognize teh struct as a type later on
{
	unsigned int hour;
	unsigned int sec;
	unsigned int min;
};

struct location
{
	double latitude;
	double longitude;
	double altitude;
};

struct weather
{
	double prcp;
	double temp;
	float press;
	float wind;
};

struct records
{
	string ID;
	tyme period;
	string lastname;
	date dayof;
	location locale;

	records *link;
};


int main(void)
{

	ifstream infile;
	infile.open("portable_weather_station_data.txt");

    cout << "how many things do you want" << endl;
    cin >> k;


    getline(infile, dataline);

    int pos_lat = dataline.find("LATITUDE");
    int pos_long = dataline.find("LONGITUDE");
    int pos_alt = dataline.find("ALTITUDE");
    int pos_month = dataline.find("MM");
    int pos_day = dataline.find("DD");
    int pos_year = dataline.find("YYYY");
    int pos_hour = dataline.find("HH");
    int pos_min = dataline.find("MM");
    int pos_sec = dataline.find("SS");
    int pos_temp = dataline.find("TEMP");
    int pos_prcp = dataline.find("PRCP");
    int pos_wind = dataline.find("WIND");
    int pos_press = dataline.find("PRESS");

    cout << pos_lat << endl;

    records station_records[k];

    for(int i = 0; i < k; i++)
    {
        getline(infile, dataline);
        dataline.insert(pos_hour, extra);
        station_records[i].period.hour = std::stoul(extra);
    }









	return 0;
}