#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

class position {
public:
	int x = 10;
	int y = 20;

	position operator + (position p)
	{
		position new_p;
		new_p.x = x + p.x;
		new_p.y = y + p.y;
		return new_p;
	}
};

int main()
{
	//operater overloading //
	position p1, p2;
	position p3 = p1 + p2;
	cout << p3.x << " " << p3.y;
	system("pause");

	return 0;
}