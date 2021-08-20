//#pragma once


#ifndef BIGLEAF_H
#define BIGLEAF_H

#include "Student.h"
#include <string>
#include<iostream>
using namespace std;

class BigLeaf : public Student{
public:
	BigLeaf(string _ID, int _score, int _money, float _background) {
		_ID = ID;
		_score = score;
		_money = money;
		_background = background;
	}

	void ShowSchool() {
		cout << "Student’s school is BigLeaf.";
	}
};

#endif