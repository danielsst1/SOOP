#include "std_lib_facilities.h"

int main()
{
	cout << "Enter an expression (+-*):\n";
	int lval = 0;
	int rval;
	char op;
	int res;

	cin >> lval;
	if (!cin) error(" ");
	for (char op; cin >> op;) {
		if (op != 'x') {
			cin >> rval;
			if (!cin) error(" ");
		}
		else {
			break;
		}


		switch (op) {
		case '+':
			lval += rval;
			//res = lval + rval;
			break;
		case '-':
			lval -= rval;
			//res = lval - rval;
			break;
		case '*':
			lval *= rval;
			//res = lval * rval;
			break;
		}
	}

	cout << '=' << lval << endl;

}