#include "std_lib_facilities.h"

int main() {
	cout << "Enter the input file name: ";
	string iFile;// = "comma2.txt";
	cin >> iFile;
	ifstream ist{ iFile };
	if (!ist) error("can't open input file");

	cout << "Enter the output file name: ";
	string oFile;// = "output.txt";
	cin >> oFile;
	ofstream ost{ oFile };
	if (!ost) error("can't open output file");
	
	vector <string> text;
	int hour;
	char sep1;
	double temp;
	char sep2;
	double pressure;

	while (ist >> hour >> sep1 >> temp >> sep2 >> pressure) {
		//text.push_back(words);
		cout << hour << " " << temp << " " << pressure << endl;
		ost << hour << "\t" << temp << "\t" << pressure << endl;
	}
}