#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class Roll_Call_System {

private:
	vector<string> studentNames{};
	vector<string> pickedStudentNames{};
	int seed;
	int a;
	int c;
	int m;

public:
	fstream fin;

	void OpenFile() {
		//TODO: open the file
		 //Prompt user to enter name of input file and amount of shift
		char filename[50];
		string line;
		cout << "Please enter the name of the input file." << endl;
		cout << "Filename: ";
		cin >> filename;
		int l = 0;
		//Open file name
		int k = 0; int number;
		ifstream myfile(filename);
		vector<int> commandvect;

		if (myfile.is_open())
		{
			//cout << "The file is open...";
			while (getline(myfile, line))
			{
				stringstream ss(line);
				string num1, num2, num3, num4, num5, num6;

				std::getline(ss, num1, ' '); //std::cout << num1 << " \n"; 
				//std::getline(ss, num2, ' '); std::cout << num2 << " \n";
				//int k = 0;
				if (k == 0) {
					number = stoi(num1);
					k = k + 1;
					//cout << number << "\n";
				}
				else if (k < number + 1) {
					AddNames(num1, number);
					k = k + 1;
					//cout << number <<  "\t" << k;
					std::cout << num1 << " \n";
				}
				else {
					//cout << k;
					// << "here are the commands ";
					//cout << line << "\n";
					stringstream ss(line);
					if (l == 0) {

						string kk = num2; //cout << "the integer value is:" << kk << endl;  // kk is the n value
						l = l + 1;
					}
					else if (l <= 3) {

						//cout << "value of string" << "\n";

						std::getline(ss, num1, ' ');// std::cout << num1 << " ";
						//cout <<  num1 << " ";
						int v1 = stoi(num1);
						std::getline(ss, num2, ' '); //std::cout << num2 << " ";
						int v2 = stoi(num2);
						std::getline(ss, num3, ' '); //std::cout << num3 << " ";
						int v3 = stoi(num3);
						std::getline(ss, num4, ' '); //std::cout << num4 << " ";
						int v4 = stoi(num4);
						std::getline(ss, num5, ' '); //std::cout << num5 << " ";
						int v5 = stoi(num5);
						l = l + 1;
						commandvect.push_back(v1);
						commandvect.push_back(v2);
						commandvect.push_back(v3);
						commandvect.push_back(v4);
						commandvect.push_back(v5);
					}
				}
			}
			//PrintPickedStudentNames(commandvect);
			GenerateRandomNumber(commandvect);
			myfile.close();
		}
		else {
			cout << "There exist no such file";
		}
	}


	void AddNames(string num1, int number) {
		//TODO : add name to studentName vector
		//int number = 40;
		// studentNames.push_back(num2);
		// cout << number;
		if (number + 1 >= studentNames.size()) {
			studentNames.push_back(num1);
		}

		//for (int i = 0; i < studentNames.size(); i++)
		//{
			//std::cout << studentNames[i] << std::endl;

		//	//***** alternate method *******
		//	//std::cout << myVector.at(i) << std::endl;		
		//}
		//studentNames.push_back(num2);
	}



	void GenerateRandomNumber(vector<int> commandvect) {
		//TODO: implement linear random number generator
		int cc = commandvect.size();
		
		int x0,x;
		
		for (int j = 0; j < cc; j = j+5) {
			
			seed = commandvect[j];
			a = commandvect[j+1];
			c = commandvect[j+2];
			m = commandvect[j+3];
			x = commandvect[j+4];
			    
		//	cout << seed <<" : " << a << " : " << c <<   ": " << m << " : " << x << endl;
			x0 = seed; 
			vector<int> bb;
		
			for (int i = 0; i < x; i++) {
				x0 = ((a * x0) + c) % m;
				//cout << "the value is here: " << x0 << "\n";
				bb.push_back(x0);
			}
			cout << "Picked names: \n" ;
			PickNames(bb);
			//cout << "POP these names now :";
			while (!bb.empty())
			{
				//cout <<"removed" ;
				bb.pop_back();
				pickedStudentNames.pop_back();
			}

			// bb.push_back(x0);
			//cout << "\ninside random vector " << x0;
			
		}
		cout << "  \n" ;
		
		//return a;
	}






	void PrintPickedStudentNames() {
		//TODO: randomly pick name form studentName vector
		//		and add them to pickedStudentName vector

		for (int j = 0; j < pickedStudentNames.size(); j++) {

			std::cout <<  pickedStudentNames[j] << std::endl;
			
		}

	}



	void PickNames(vector<int> bb) {

		//TODO: print all picked name form studentName vector
		//for (int i = 0; i < studentNames.size(); i++) {
	
		for (int j = 0; j < bb.size(); j++) {

			//cout << "The value is here: " << bb[j] << " : ";
			int value = bb[j];
			pickedStudentNames.push_back(studentNames[value]);

		}
		PrintPickedStudentNames();
		CaculateAlphabets();
     }


	void CaculateAlphabets() {
		//TODO: calculate how many diffetent alphabets are used and print it
		string final; 
		string total = "";
		int mm = pickedStudentNames.size();
		/// to do so I use hash table ///
		/// 
		/// 
		for (int j = 0; j < pickedStudentNames.size(); j++) {

			final = pickedStudentNames[j] + final;
		}
		//cout << final << final.length();
		int hash[2000] = { 0 };

			for (int i = 0; i < final.length(); i++) {
				if (hash[final[i]] == 0)
				{
					hash[final[i]] = 1;
					total = total + final[i];
					//cout << "total" << total;
				}
				
			}		
		cout << "Total alphabets: " << total.length() <<  endl;
		cout << endl;
		
	}

};

int main() {
	string num1;
	Roll_Call_System rcs;
	rcs.OpenFile();
	//rcs.AddNames(num1);
	//vector<int> commandvect;
	int times;
	//rcs.fin >> times;
	//while (times--) {
	//	//rcs.PickNames();
	//	//rcs.PrintPickedStudentNames(commandvect);
	//	//rcs.CaculateAlphabets();
	//}
	
	system("PAUSE");
	return 0;

}