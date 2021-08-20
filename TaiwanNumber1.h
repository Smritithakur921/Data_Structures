//#pragma once


#include "Student.h"
#include <string>
#include<iostream>
using namespace std;

class TaiwanNumber1 : public Student {
public:
	TaiwanNumber1(string _ID, int _score, int _money, float _background) {
		_ID = ID;
		_score = score;
		_money = money;
		_background = background;
	}

	void ShowSchool() {
		cout << "Student’s school is TaiwanNumber1.";
	}
};
#endif