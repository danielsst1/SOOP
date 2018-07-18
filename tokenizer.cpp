#include "std_lib_facilities.h"

const vector <char> symbols{ ';', 'q', '-', '+', '*', '/', '(', ')', '%' };

class Token {
public:
	char kind;
	double value;

};

Token get_token() {
	char ch;
	cin >> ch;

	switch (ch) {

	case ';':
	case 'q':
	case '-':
	case '+':
	case '*':
	case '/':
	case '(':
	case')':
	case '%':
		return Token{ ch };

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		return Token{ ch };
	}
}

void print_token(Token t) {
		if (t.kind == '8') {
			cout << "A number token with val = " << t.value << endl;
		}
		else if (find(symbols.begin(), symbols.end(), t.kind) != symbols.end()) {
			cout << "A token of kind " << t.kind << endl;
		}
		else if (t.kind == 'q' || t.kind == ';') {
			//intentional blank
		}
		else {
			cout << "We received an invalid token of value " << t.kind << endl;
		}
	}

vector<Token> tokens;

int main() {
	cout << "Enter an expression (+=/%*) :\n> ";
	while (cin) {
		try {
			Token t = get_token();

			if (t.kind == 'q') return 0;
			print_token(t);
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
	}
}