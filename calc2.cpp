#include "std_lib_facilities.h"

int main() {
	cout << "Enter an expression (+-*):\n";
	int lval = 0;
	int rval;
	char op;
	int res;

	cin >> lval >> op >> rval;

	switch (op) {
	case '+':
		res = lval + rval;
		break;
	case '-':
		res = lval - rval;
		break;
	case '*':
		res = lval * rval;
		break;
	}

	cout << '=' << res << endl;
}