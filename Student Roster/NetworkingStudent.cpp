#include "pch.h"
#include "NetworkingStudent.h"

NetworkingStudent::NetworkingStudent() {
	setDegree(NETWORKING);
}

NetworkingStudent::NetworkingStudent(string studID, string fName, string lName, string emailAdd,
	int studAge, int* daysComplete[], Degree program) {
	setDegree(NETWORKING);
}

Degree NetworkingStudent::getDegreeProgram() {
	return NETWORKING;
}

void NetworkingStudent::setDegree(Degree d) {
	this->program = NETWORKING;
}

void NetworkingStudent::print() {
	this->Student::print();
	cout << "NETWORKING" << endl;
}


NetworkingStudent::~NetworkingStudent() {
	delete this;
}