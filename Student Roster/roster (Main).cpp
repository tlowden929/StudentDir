// roster (Main).cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include "student.h"
#include "SecurityStudent.h"
#include "NetworkingStudent.h"
#include "SoftwareStudent.h"
#include "roster.h"

using namespace std;

//Empty constructor default values
Roster::Roster() {
	this->maxList = 0;
	this->lastEntry = -1;
	this->classRosterArray = nullptr;
}
//Full constructor
Roster::Roster(int maxList) {
	this->maxList = maxList;
	this->lastEntry = -1;
	this->classRosterArray = new Student*[maxList];
}
//Parsing studentData
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, string program) {
	if (lastEntry < MAX_STUDENTS) {
		++lastEntry;
		//Set Array for Days to Complete
		int daysArray[Student::daysCompleteArray];
		//Sorting entries by Degree Program
		
		if (program == "SECURITY") {
			this->classRosterArray[lastEntry] = new SecurityStudent();
			classRosterArray[lastEntry]->setDegree(SECURITY);
		}
		else if (program == "NETWORK") {
			this->classRosterArray[lastEntry] = new NetworkingStudent();
			classRosterArray[lastEntry]->setDegree(NETWORKING);
		}
		else if (program == "SOFTWARE") {
			this->classRosterArray[lastEntry] = new SoftwareStudent();
			classRosterArray[lastEntry]->setDegree(SOFTWARE);
		}
		else {
				cout << "Error: Student Missing Degree Program!" << endl;
		}
		
		//Student ID
		classRosterArray[lastEntry]->setstudID(studentID);

		//First Name
		classRosterArray[lastEntry]->setfName(firstName);

		//Last Name
		classRosterArray[lastEntry]->setlName(lastName);

		//Email
		classRosterArray[lastEntry]->setEmail(emailAddress);

		//Age
		classRosterArray[lastEntry]->setstudAge(age);

		//Start Array of Days to Complete Course
		daysArray[0] = daysInCourse1;
		daysArray[1] = daysInCourse2;
		daysArray[2] = daysInCourse3;

		//total Array
		classRosterArray[lastEntry]->setdaysComplete(daysArray);
	}
	else {
		cout << "Maximum Entries Reached" << endl;
	}
}

//Remove student by student ID and reduce roster entries
void Roster::remove(string studID) {
	bool foundStudent = false;
	for (int i = 0; i <= lastEntry; ++i) {
		if (this->classRosterArray[i]->getstudID() == studID) {
			foundStudent = true;
			cout << "Removing Student " << studID << endl;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = classRosterArray[lastEntry];
			--lastEntry;
		}
	}
	if (!foundStudent) {
		cout << "Student ID: " << studID << " not found" << endl;
	}
}
	
//Print Functions
//Average Days In Course by student ID (adds array of days complete in course divided by 3)
void Roster::printAverageDaysInCourse() {
	for (int i = 0; i <= lastEntry; ++i) {
		int* daysArray = classRosterArray[i]->getdaysComplete();
		cout << "Average Days in Course for Student ID: " << classRosterArray[i]->getstudID() << " is " << (daysArray[0] + daysArray[1] + daysArray[2]) / 3 << endl;
	}
}
	
//Invalid Emails by student ID (looks for "@"/"."/" ")
void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastEntry; ++i) {
		size_t at = classRosterArray[i]->getemailAdd().find('@');
		if (at == string::npos) {
			
			cout << "Student ID: " << classRosterArray[i]->getstudID() << " has an invalid email." << endl;
			cout << classRosterArray[i]->getemailAdd() << endl;
		}
		size_t dot = classRosterArray[i]->getemailAdd().find('.');
		if (dot == string::npos) {
		
			cout << "Student ID: " << classRosterArray[i]->getstudID() << " has an invalid email." << endl;
			cout << classRosterArray[i]->getemailAdd() << endl;
		}
		size_t space = classRosterArray[i]->getemailAdd().find(' ');
		if (space != string::npos) {
			
			cout << "Student ID: " << classRosterArray[i]->getstudID() << " has an invalid email." << endl;
			cout << classRosterArray[i]->getemailAdd() << endl;
		}
		
		
	}
}

//Students by Degree Program
void Roster::printByDegreeProgram(Degree d) {
	cout << "Students in " << degreeProgram[d] << " program:" << endl;
	for (int i = 0; i <= lastEntry; ++i) {
		if(this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
		
	}
}

//Student Roster (All)
void Roster::printAll() {
	for (int i = 0; i <= this->lastEntry; ++i) (this->classRosterArray[i]->print());
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < lastEntry; ++i) {
		delete this->classRosterArray[i];
	}
	delete this;
}

int main()
{	
	cout << "Course: Scripting and Programming - Applications" << endl;
	cout << "Written in C++ by Tenay Lowden" << endl << endl;

	Roster classRoster(MAX_STUDENTS);

	//Student info to parse
	const string studentData[MAX_STUDENTS] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Tenay,Lowden,tlowden929@gmail.com,32,30,35,50,SOFTWARE" };

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); ++i) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string newData[9];

		int j = 0;
		while (getline(ss, token, ',')) {
			newData[j] = token;
			j += 1;
		}
		classRoster.add(newData[0], newData[1], newData[2], newData[3], stoi(newData[4]), stoi(newData[5]), 
			stoi(newData[6]), stoi(newData[7]), newData[8]);
	}

	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	classRoster.printAverageDaysInCourse();
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	classRoster.remove("A3");

	classRoster.~Roster();
	
	return 0;
}
