//
// Introduction to Linked Lists
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct date
{
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

struct student_record
{
	string firstname;
	string lastname;
	date birthdate;
	unsigned int age;
	string major;
	student_record *link;
};

void enter_data(student_record &student);
void print_data(student_record &student);

int main(void)
{


	// Declare some pointers to student_record types

	student_record* Person1 = new student_record;
	student_record* Person2 = new student_record;

	student_record student;

	cout << "Enter data for Person1." << endl;
	enter_data(*Person1);
	Person1->link = NULL;
	cout << endl;

	cout << "Enter data for Person2." << endl;
	enter_data(*Person2);
	Person2->link = NULL;
	cout << endl;

	// Link Person1's record to Person2

	Person1->link = Person2;

	cout << Person1->firstname << " " << Person1->lastname << endl;
	cout << Person2->firstname << " " << Person2->lastname << endl;

	// Print Person2's data using Person1's link
	cout << Person1->link->firstname << " " << Person1->link->lastname << endl;

	//
	// Create a linked list
	// General instructions
	//

	unsigned int nodes_in_list = 3, k = 0;

	// 1. Three pointers are required for the linked list.
	// Declare them first.

	student_record *root, *current_node, *new_node;

	// 2. Prepare the first node of the list

	current_node = new student_record; // Create the node
	enter_data(*current_node); // Populate the node with data
	current_node->link = NULL; // Initialize the link field
    
	// 3. Set the root pointer to this node. 

	root = current_node;

	// 4. Enter a loop to complete the linked list.

	k = 1;
	while ( k <= nodes_in_list)
	{
		cout << "Adding node " << k + 1 << endl;
		// 5. Dynamically create a new node

		new_node = new student_record;

		// 6. Populate the node with data

		enter_data(*new_node);

		// 7. Set the link to NULL

		new_node->link = NULL;

		// 8. Connect the previous node to this one

		current_node->link = new_node;

		// 9. Move the current node pointer to the new node

		current_node = new_node;

		k++;
	}

	cout << endl << endl;
	// Print out the data on the linked list.
	// Start at the first (root) node

	current_node = root;
	while (current_node->link != NULL)
	{
		cout << "STUDENT RECORD" << endl << endl;
		current_node = current_node->link;
		print_data(*current_node);
	}
 

	system("pause");
	return 0;
}

// Functions

void enter_data(student_record &student)
{
	cout << "Enter first and last name." << endl;
	cin >> student.firstname >> student.lastname;
	cout << "Enter date of birth as MM DD YYYY." << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	cout << "Enter age." << endl;
	cin >> student.age;
	cout << "Enter major (e.g. CS)." << endl;
	cin >> student.major;

	return;
}

void print_data(student_record &student)
{

	cout << "Name:      " << student.firstname << " " << student.lastname << endl;
	cout << "Birthdate: " << student.birthdate.month << setw(3) << student.birthdate.day
		 << setw(5) << student.birthdate.year << endl;
	cout << "Age:       " << student.age << endl;
	cout << "Major:     " << student.major << endl;

	return;
}