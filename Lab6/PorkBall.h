//#pragma once
//**************************Casting is a technique by which one data type to another data type.*******************************
#ifndef PORKBALL_H

#include "/C++/course/Lab_Exercise/Lab_Exercise/Lab6/Project6/Student.h"
#include <string>
#include<iostream>
using namespace std;

class PorkBall {
public:
	PorkBall(string name, float speed) {}

	bool canRide(Student* student) {
		// use isTraffic to check whether the student can ride the porkball.
		return true;
	}

private:
	string name;
	float speed;
	bool isTraffic(Student* student) {
		// use dynamic casting to check whether the student is a Traffic student.
		return true;
	}
};
#endif
