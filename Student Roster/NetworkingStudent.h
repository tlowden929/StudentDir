#pragma once
#include "student.h"
#include "degree.h"

class NetworkingStudent :
	public Student {

public:
	NetworkingStudent();
	NetworkingStudent(string studID, string fName, string lName, string emailAdd,
		int studAge, int* daysComplete[], Degree program);

	Degree getDegreeProgram();
	void setDegree(Degree d);
	void print();

	~NetworkingStudent();
};
