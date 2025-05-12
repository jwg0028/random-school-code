#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


unsigned int pos_name = 0, pos_size = 0, pos_date = 0, pos_time = 0, pos_phone = 0, pos_email = 0, pos_credit = 0, pos_expire = 0;
string month_s = "", dataline = "";
int month, day, year;
ifstream infile;


int rday, rmonth, ryear;


struct reserve
{
    string name, size, date, time, phone, email, credit, expire;
};



int main(void)
{

reserve customer[6];

infile.open("dinner_reservations.txt");
getline(infile, dataline);

pos_name = dataline.find("NAME");
pos_size = dataline.find("SIZE");
pos_date = dataline.find("DATE");
pos_time = dataline.find("TIME");
pos_phone = dataline.find("PHONE");
pos_email = dataline.find("EMAIL");
pos_credit = dataline.find("CREDIT");
pos_expire = dataline.find("EXPIRE");



for(int i = 0; i < 6; i++)
{
    getline(infile, dataline);

    cout << dataline << endl;
    customer[i] = {dataline.substr(pos_name, 10),
    dataline.substr(pos_size, 1),
    dataline.substr(pos_date-1, 10),
    dataline.substr(pos_time-1, 5),
    dataline.substr(pos_phone-1, 15),
    dataline.substr(pos_email-1, 14),
    dataline.substr(pos_credit-1, 15),
    dataline.substr(pos_expire-1, 10)
                           };
}


cout << "Enter a date to check" << endl;
cin >> month_s;
cin >> day;
cin >> dataline;
cin >> year;

if (month_s == "January" || month_s == "january")
{
    month = 1;
}
if (month_s == "February" || month_s == "february")
{
    month = 2;
}
if (month_s == "March" || month_s == "march")
{
    month = 3;
}
if (month_s == "April" || month_s == "april")
{
    month = 4;
}
if (month_s == "May" || month_s == "may")
{
    month = 5;
}
if (month_s == "June" || month_s == "june")
{
    month = 6;
}
if (month_s == "July" || month_s == "july")
{
    month = 7;
}
if (month_s == "August" || month_s == "august")
{
    month = 8;
}
if (month_s == "September" || month_s == "september")
{
    month = 9;
}
if (month_s == "October" || month_s == "october")
{
    month = 10;
}
if (month_s == "November" || month_s == "november")
{
    month = 11;
}
if (month_s == "December" || month_s == "december")
{
    month = 12;
}

for (int i = 0; i < 6; i++)
{
    dataline = customer[i].date;
    //getline(customer[i].date, dataline);
    month_s = dataline.substr(0, 2);
    rmonth = stoi(month_s);

    month_s = dataline.substr(2, 3);
    rday = stoi(month_s);


    if (rday == day && rmonth == month)
    {
        cout << customer[i].name << "  ";
        cout << customer[i].size << "  ";
        cout << customer[i].date << "  ";
        cout << customer[i].time << "  ";
        cout << customer[i].phone << "  ";
        cout << customer[i].email << "  ";
        cout << customer[i].credit << "  ";
        cout << customer[i].expire << endl;
        
    }
    

}





system("pause");
return 0;
}
