#include "pch.h"
#include "SecurityStudent.h"


SecurityStudent::SecurityStudent() {
	setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string studentid, string firstname, string lastname, string email,
	int age, int* daystocomplete, Degree program) {
	setDegree(SECURITY);
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;
}

void SecurityStudent::setDegree(Degree d) {
	this->program = SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
}


SecurityStudent::~SecurityStudent(){
	Student::~Student();
	delete this;
}
