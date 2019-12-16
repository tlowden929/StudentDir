#pragma once
#include "student.h"

const int MAX_STUDENTS = 5;

//Student info to parse
const string studentData[MAX_STUDENTS] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Tenay,Lowden,tlowden929@gmail.com,32,30,35,50,SOFTWARE" };



class Roster {

public:
	Student **classRosterArray;
	int lastEntry;
	int maxList;
	
	//Empty Constructor
	Roster();
	//Full Constructor
	Roster(int maxList);
	//Add and Remove
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
		int daysInCourse2, int daysInCourse3, string program);
	void remove(string studID);
	//Print Functions
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(Degree d);
	void printAll();

	//Destructor
	~Roster();
};

