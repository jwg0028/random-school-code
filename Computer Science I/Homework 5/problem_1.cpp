#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int count = 1;
ofstream outfile;


struct name
{
    string fname, lname;
};

struct info
{
    string Birth, tall, weight, eyes, hair, address;
};

struct ID
{
    name name;

    info info;

    string issued, expire;
};

ID initialize(ID x);
ID print(ID x);

int main(void)
{
outfile.open("records_data.txt");
ID id1, id2, id3, id4, id5;
char input;

cout << "Would you like to" << endl << "(a) Make a new index" << endl;
cin >> input;
if(input == 'a')
{
    id1 = initialize(id1);
    count++;
    id2 = initialize(id2);
    count++;
    id3 = initialize(id3);
    count++;
    id4 = initialize(id4);
    count++;
    id5 = initialize(id5);

    outfile.close();
}

system("cls");
count = 1;

id1 = print(id1);
count++;
id2 = print(id2);
count++;
id3 = print(id3);
count++;
id4 = print(id4);
count++;
id5 = print(id5);

system("pause");

return 0;
}



ID initialize(ID x)
{


outfile << "ID " << count << endl;

cout << "Enter the first name: ";
cin >> x.name.fname;



cout << "Enter the last name: ";
cin >> x.name.lname;

outfile << "Name: " << x.name.lname << ", " << x.name.fname << endl;

cout << "Enter the date of birth (MM/DD/YYYY):";
cin >> x.info.Birth;

outfile << "Date of Birth: " << x.info.Birth << endl;

cout << "Enter the height: ";
cin >> x.info.tall;

outfile << "Height: " << x.info.tall << endl;

cout << "Enter the weight: ";
cin >> x.info.weight;

outfile << "Weight: " << x.info.weight << endl;

cout << "Enter the eye color: ";
cin >> x.info.eyes;

outfile << "Eye Color: " << x.info.eyes << endl;

cout << "Enter the hair color: ";
cin >> x.info.hair;

outfile << "Hair Color: " << x.info.hair << endl;

cout << "Enter the home address: ";
cin.clear();
cin.sync();
getline(cin, x.info.address);


outfile << "Home Address: " << x.info.address << endl;

cout << "Enter the date the ID was issued (MM/DD/YYYY): ";
cin >> x.issued;

outfile << "Date Issued: " << x.issued << endl;

cout << "Enter the date the ID expires (MM/DD/YYYY): ";
cin >> x.expire;

outfile << "Date of Expiration: " << x.expire << endl;


if(count == 5)
{
    outfile.close();
}

return x;
}

ID print(ID x)
{

cout << "ID: " << count << endl;

cout << "Name: " << x.name.lname << ", " << x.name.fname << endl;
cout << "Date of Birth: " << x.info.Birth << endl;
cout << "Height: " << x.info.tall << endl;
cout << "Weight: " << x.info.weight << endl;
cout << "Eye Color: " << x.info.eyes << endl;
cout << "Hair Color: " << x.info.hair << endl;
cout << "Home Address: " << x.info.address << endl;
cout << "Date Issued: " << x.issued << endl;
cout << "Date of Expiration: " << x.expire << endl;


return x;
}