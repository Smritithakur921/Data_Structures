#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>



using namespace std;

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;

public:
	PrimeFactorization() {
		//TO_DO: initial constructor
		int num1, num2;
	}
	PrimeFactorization(int _a, int _b) {

	}
	void Get_Prime_Factorization(int num1, int num2)
	{
		if (num1 < 2)
			int h;
		// Save the numbers divided by 2.
		else
		{
			while (num1 % 2 == 0)
			{
				num1_factor.push_back(2);
				num1 = num1 / 2;

			}

			// now we just have odd numbers so find the factors.
			for (int i = 3; i <= sqrt(num1); i = i + 2)
			{
				// While i divides n, save the value of i and divide the num by i
				while (num1 % i == 0)
				{
					num1_factor.push_back(i);
					num1 = num1 / i;
				}
			}
			// at the end we have to push the num  in the value.
			if (num1 > 2)
				num1_factor.push_back(num1);
		}
		// if the number is less then 2


		///////////////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////
		if (num2 < 2)
			int h;
		else {
			while (num2 % 2 == 0)
			{
				num2_factor.push_back(2);
				num2 = num2 / 2;
			}

			// n must be odd at this point. So we can skip
			// one element (Note i = i +2)
			for (int i = 3; i <= sqrt(num2); i = i + 2)
			{
				// While i divides n, print i and divide n
				while (num2 % i == 0)
				{
					num2_factor.push_back(i);
					num2 = num2 / i;
				}
			}

			if (num2 > 2)
				num2_factor.push_back(num2);
			// if the number is less then 2
		}

	}


	void Print_Prime_Factorization() {
		//TO_DO: Print num1_factor and num2_factor.
		std::stringstream ss, sss;
		cout << "num1_Prime_factor : ";
		for (int j = 0; j < num1_factor.size(); ++j) {
			//std::cout << num1_factor[j] << " ";

			ss << num1_factor[j];
			ss << " ";
		}
		std::string s = ss.str();
		cout << "\" " << s << "\"";
		cout << endl;
		cout << "num2_Prime_factor : ";
		for (int j = 0; j < num2_factor.size(); ++j) {
			//std::cout << num2_factor[j] << " ";
			sss << num2_factor[j];
			sss << " ";
		}
		std::string s1 = sss.str();
		cout << "\" " << s1 << "\"";
		cout << endl;
	}


	void Print_GCD(int num1, int num2) {
		int gcd1 = 1; int count;
		if (num1 == 0)
			cout << "GCD :" << num2;
		else if (num2 == 0)
			cout << "GCD :" << num1;


		else if (num1 == num2)
			cout << "GCD :" << num1;



		else {
			for (int i = 0; i < num1_factor.size(); ++i) {
				count = 0;
				for (int j = 0; j < num2_factor.size(); ++j) {
					if (count == 0) {
						if (num1_factor[i] == num2_factor[j]) {
							gcd1 = gcd1 * num2_factor[j];
							num2_factor[j] = 1;
							count = 1;
							j = num2_factor.size();
						}
					}
				}
			}

			cout << "GCD : " << gcd1 << endl;
		}


	}

};

int main() {
	int result;
	string line; int numberArray[16];
	int i = 0;

	ifstream myfile("Lab2_test_data.txt");  // read the file //
	//ofstream myfileo("new.txt"); // write the file //

	//int num; 
	//cin >> num;
	//int num1, num2;
	//
	//myfileo << num << endl;
	//for (int i = 0; i < num; i++) {
	//	cin >> num1 >> num2;
	//	myfileo << num1 << ' ' << num2 << endl;
	//}
	vector<int> v; int k = 0;
	///////////////read file ////////////////////////
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			stringstream ss(line);
			string num1, num2;

			std::getline(ss, num1, ' '); std::cout << num1 << " ";
			std::getline(ss, num2, ' '); std::cout << num2 << " ";
			k = k + 1;
			if (k == 1) {

				int kk = stoi(num1); //cout << "the integer value is:" << kk << endl;  // kk is the n value
				k = k + 2; v.push_back(kk);
			}
			else {
				int aa = stoi(num1); int bb = stoi(num2);
				//cout << "here is yout integer value" << aa << "," << bb << endl;
				//cout << line << '\n';
				v.push_back(aa);
				v.push_back(bb);
			}
		}
		myfile.close();
	}

	else cout << "Unable to open file";


	/// <summary>
	/// //////////////////////////////////////////////////////////////////////
	//int length = (v[0] * 2) + 1;
	//if (length == v.size()) {
	//	int a, b;
	//	for (int i = 2; i < v.size(); i = i + 2) {
	//		a = v[i - 1];
	//		b = v[i];
	//		cout << "num1 = " << a << endl;
	//		cout << "num2 = " << b << endl;
	//		PrimeFactorization PF(a, b);
	//		PF.Get_Prime_Factorization(a, b);

	//		PF.Print_Prime_Factorization();
	//		PF.Print_GCD(a,b);
	//		//cout << "GCD : " << gcd;
	//		cout << "\n";
	//		cout << endl;
	//	}
	//}
	//else
	//	cout << "put proper value";

	system("PAUSE");
	return 0;
}

