#include "std_lib_facilities.h"
#include "date.h"

int main() {
	Date today1;
	while (true) {
		try {
			cout << "Enter date separated by spaces (mm dd yyyy): ";
			cin >> today1;
			break;
		}
		catch (...) {
			cout << "Invalid date input\n";
		}
	}

	Date today2(2017, Month(12), 20);
	Date today3(2017, Month(12), 20);
	Date today4(2020, Month(2), 29);

	/*cout << "Enter date separated by spaces (mm dd yyyy): ";
	cin >> today1;*/

	cout << "\nYour date:\n";
	cout << "Date1: " << today1 << endl;
	cout << "\nGenerated dates:\n";
	cout << "Date2: " << today2 << endl;
	cout << "Date3: " << today3 << endl;
	cout << "Date4: " << today4 << endl;

	cout << "\nTesting '=='\n";
	if (today1 == today2) { cout << "Date1 and Date2 are equal\n"; }
	else { cout << "Date1 and Date2 are not equal\n"; }

	if (today2 == today3) { cout << "Date2 and Date3 are equal\n"; }
	else { cout << "Date2 and Date3 are not equal\n"; }

	cout << "\nTesting 'isLeapYear()'\n";
	if (isLeapYear(today1.year())) { cout << today1 << " is a leap year\n"; }
	else { cout << today1 << " is not a leap year\n"; }

	cout << "\nTesting 'add_year()'\n"
		<< "Enter a number of years to add: ";
	int yrs;
	cin >> yrs;
	today1.add_year(yrs);
	cout << "Date1: " << today1 << endl;

	cout << "\nTesting 'add_day()'\n"
		 << "Enter a number of days to add: ";	     
	int dys;
	cin >> dys;
	today1.add_day(dys);
	cout << "Date1: " << today1 << endl;

	cout << "\nTesting 'add_month()'\n"
		 << "Enter a number of months to add: ";
	int mth;
	cin >> mth;
	today1.add_month(mth);
	cout << "Date1: " << today1 << endl;

	cout << endl;
	return 0;
}