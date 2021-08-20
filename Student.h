//#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "TaiwanNumber1.h"
#include "BigLeaf.h"
#include "Traffic.h"
#include <string>
#include<iostream>
using namespace std;

class Student {
public :
	string ID;
	int score;
	int money;
	float background;

	void PrintAllInfo() {
		std::cout << "ID : " << ID << "\n" << "score : " << score <<"\n" ;
		std::cout << "money : " << money <<"\n" <<  "Background : " << background <<"\n";
	}

	virtual void ShowSchool() {
		
	}

	string getID() {
		std::cin >> ID;
		return ID;
	}

};

#endif