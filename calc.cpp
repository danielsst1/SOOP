#include "std_lib_facilities.h"

int main() {
	cout << "Enter an expression (+-):\n";
	int lval = 0;
	int rval;
	char op;
	int res;

	cin >> lval >> op >> rval;

	if (op == '+') {
		res = lval + rval;
	}
	else if (op == '-') {
		res = lval - rval;
	}

	cout << '=' << res << endl;
}