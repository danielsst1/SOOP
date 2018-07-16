#include "std_lib_facilities.h"
// Daniel Tse
// 7/9/18
// unsafeConversions.cpp


int main() {
	//double to int conversion
	cout << "Double to Int:\n";
	double x = 1.2;
	cout << "double x = " << x << endl << endl;

	cout << "int y = int(x)\n";
	int y = int(x);
	cout << "int y = " << y << endl << endl;
	
	cout << "double x = y\n";
	x = y;
	cout << "x = " << x << endl << endl;

	//double to char conversion
	cout << "Double to Char:\n";
	x = 1.2;
	cout << "double x = " << x << endl << endl;

	cout << "char z = char(x)\n";
	char z = char(x);
	cout << "char z = " << z << endl << endl;

	cout << "double x = z\n";
	x = z;
	cout << "x = " << x << endl << endl;

	//double to bool conversion
	cout << "Double to Bool:\n";
	x = 1.2;
	cout << "double x = " << x << endl << endl;

	cout << "bool a = bool(x)\n";
	bool a = bool(x);
	cout << "bool a = " << a << endl << endl;

	cout << "double x = a\n";
	x = a;
	cout << "x = " << x << endl << endl;

	//int to char conversion
	cout << "Int to Char:\n";
	y = 3;
	cout << "int y = " << y << endl << endl;

	cout << "char z = char(y)\n";
	z = char(y);
	cout << "char z = " << z << endl << endl;

	cout << "int y = z\n";
	y = z;
	cout << "y = " << y << endl << endl;

	//int to bool conversion
	cout << "Int to Bool:\n";
	y = 5;
	cout << "int y = " << y << endl << endl;

	cout << "bool a = bool(y)\n";
	a = bool(y);
	cout << "bool a = " << a << endl << endl;

	cout << "int y = a\n";
	y = a;
	cout << "y = " << y << endl << endl;

	//char to bool conversion
	cout << "Char to Bool:\n";
	z = 'h';
	cout << "char z = " << z << endl << endl;

	cout << "bool a = bool(z)\n";
	a = bool(z);
	cout << "bool a = " << a << endl << endl;

	cout << "bool z = a\n";
	z = a;
	cout << "z = " << z << endl << endl;
}