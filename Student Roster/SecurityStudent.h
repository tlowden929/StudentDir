#pragma once
#include "student.h"
#include "degree.h"

class SecurityStudent :
	public Student {

public:
	SecurityStudent();
	SecurityStudent(string studentid, string firstname, string lastname, string email, 
	int age, int* daystocomplete, Degree program);

	Degree getDegreeProgram();
	void setDegree(Degree d);
	void print();

	~SecurityStudent();
};

