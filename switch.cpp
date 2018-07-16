#include "std_lib_facilities.h"

int main() {
	cout << "To calculate your luck, enter the last digit of your phone number:\n";
	int num;
	cin >> num;

	switch (num){
	case 1: case 9:
		cout << "You will have bad luck today\n";
		break;
	case 2: case 8:
		cout << "You will have moderately bad luck today\n";
		break;
	case 3: case 7:
		cout << "You will have moderately good luck today\n";
		break;
	case 4: case 6:
		cout << "You will have good luck today\n";
		break;
	case 5: case 0:
		cout << "You will have neutral luck today\n";
		break;
	}
}