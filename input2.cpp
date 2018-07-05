#include "std_lib_facilities.h"

int main() {
	cout << "Please enter your name:\n";
	string first_name; // variable of type string
	cin >> first_name; // read characters into first name
	cout << "Please enter your age; \n";
	int age;
	cin >> age;
	cout << "Hello " << first_name << " " << age << endl;
}