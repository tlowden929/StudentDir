#include "pch.h"
#include "student.h"

//Empty constructor default values
Student::Student() {
	this->studentid = "";
	this->firstname = "";
	this->lastname = "";
	this->email = "";
	this->age = 0;
	this->daystocomplete = new int[daysCompleteArray];
	for (int i = 0; i < daysCompleteArray; ++i) this->daystocomplete[i] = 0;
	
}
//Full constructor
Student::Student(string studID, string fName, string lName, string emailAdd, int studAge, 
int daysComplete[], Degree program){
	this->studentid = studID;
	this->firstname = fName;
	this->lastname = lName;
	this->email = emailAdd;
	this->age = studAge;
	this->daystocomplete = new int[daysCompleteArray];
	for (int i = 0; i < daysCompleteArray; ++i) this->daystocomplete[i] = daystocomplete[i];
	
}

//Get
string Student::getstudID(){
	return studentid;
}
string Student::getfName() {
	return firstname;
}
string Student::getlName() {
	return lastname;
}
string Student::getemailAdd() {
	return email;
}
int Student::getstudAge() {
	return age;
}
int* Student::getdaysComplete() {
	return daystocomplete;
}

//Set
void Student::setstudID(string studID) {
	studentid = studID;
}
void Student::setfName(string fName) {
	firstname = fName;
}
void Student::setlName(string lName) {
	lastname = lName;
}
void Student::setEmail(string emailAdd) {
	email = emailAdd;
}
void Student::setstudAge(int studAge) {
	age = studAge;
}
void Student::setdaysComplete(int daystocomplete[]) {
	
	this->daystocomplete = new int[daysCompleteArray];
	for(int i = 0; i < 3; ++i)
		this->daystocomplete[i] = daystocomplete[i];
}
void Student::print() {
	cout << studentid << "\t";
	cout << "First Name: " << firstname << "\t";
	cout << "Last Name: " << lastname << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: {" << daystocomplete[0] << "," << daystocomplete[1] << "," << daystocomplete[2] << "}\t";
}
Student::~Student() {
	delete daystocomplete;
}
