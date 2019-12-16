#include "pch.h"
#include "SoftwareStudent.h"


SoftwareStudent::SoftwareStudent() {
	setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studID, string fName, string lName, string emailAdd,
	int studAge, int* daysComplete[], Degree program) {
	setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::setDegree(Degree d) {
	this->program = SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << endl;
}


SoftwareStudent::~SoftwareStudent() {
	delete this;
}
