#include "std_lib_facilities.h"

int main() {
	cout << "Enter the name of the person you want to write to:\n";
	string first_name; // variable of type string
	cin >> first_name; // read characters into first name

	cout << "Enter the name of a mutual friend:\n";
	string friend_name;
	cin >> friend_name;

	cout << "Enter age of recipient:\n";
	int age;
	cin >> age;


	cout << "Dear, " << first_name << "\nI hope you are well."
		<< " Have you seen " << friend_name << " recently? I've been "
		<< "meaning to catch\nup with " << friend_name << ", but can't contact"
		<< " them. Anyway, I heard you recently turned " << age << "!\n";

	if (age < 0 || age > 110)
		simple_error("impossible age");

	else if (age < 17)
		cout << "You are young to be at NYU!\n";

	else if (age > 65)
		cout << "It's great to see senior students around campus!\n";

}