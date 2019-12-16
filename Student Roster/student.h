#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
using namespace std;

class Student {
public:
	const static int daysCompleteArray = 3;
	//Empty constructor
	Student();
	//Full constructor
	Student(string studID, string fName, string lName, string emailAdd, int studAge,
	int daysComplete[], Degree program);

	//Get
	string getstudID();
	string getfName();
	string getlName();
	string getemailAdd();
	int getstudAge();
	int* getdaysComplete();

	//Overridden by each degree program student
	virtual Degree getDegreeProgram() = 0;

	//Set
	void setstudID(string studID);
	void setfName(string fName);
	void setlName(string lName);
	void setEmail(string emailAdd);
	void setstudAge(int studAge);
	void setdaysComplete(int daysComplete[]);
	virtual void setDegree(Degree d) = 0;
	virtual void print() = 0;

	//Destructor
	~Student();

protected:
	string studentid;
	string firstname;
	string lastname;
	string email;
	int age;
	int* daystocomplete; //Array
	Degree program;
	
};
#endif
