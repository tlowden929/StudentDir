#pragma once
#include "student.h"
#include "degree.h"

class SoftwareStudent :
	public Student {

public:
	SoftwareStudent();
	SoftwareStudent(string studID, string fName, string lName, string emailAdd,
		int studAge, int* daysComplete[], Degree program);

	Degree getDegreeProgram();
	void setDegree(Degree d);
	void print();

	~SoftwareStudent();
};