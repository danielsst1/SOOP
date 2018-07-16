#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;

};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	Token buffer;
	bool full = false;
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;

	switch (ch) {
	case ';': case 'q': case '-': case '+': case '*': case '/': case '(': case')':
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
	if (t.kind == '8'){
		cout << "A number token with val = " << t.value << endl;
	}
	else if (t.kind == '(' || t.kind == ')' || t.kind == '+' || t.kind == '-' || t.kind == '*' || t.kind == '/') {
		cout << "A token of kind " << t.kind << endl;
	}
	else if (t.kind == 'q' || t.kind == ';') {
		//intentional blank
	}
	else {
		cout << "We received an invalid token of value " << t.kind << endl;
	}
}

//token stream
Token_stream ts;

//function declarations
double term();
double expression();

double primary() {
	Token t = ts.get();
	print_token(t);
	switch (t.kind) {
	case '(': // handle expression
	{
		double d = expression();
		t = ts.get();
		//print_token(t);
		if (t.kind != ')') error(" ')' expected");
		return d;
	}
	case '8': // 8 represents number
		return t.value;
	default:
		error("Primary expected");
	}
	return t.value;
}

double term() {
	return primary();
}

//controls function of operations
double expression() {
	double left = term();
	Token t = ts.get();
	print_token(t);
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			print_token(t);
			break;
		case '-':
			left -= term();
			t = ts.get();
			print_token(t);
			break;
		case '*':
			left *= term();
			t = ts.get();
			print_token(t);
			break;
		case '/':
			left /= term();
			t = ts.get();
			print_token(t);
			break;

		default:
			ts.putback(t);
			return left;
		}
	}
}

int main() {
	double val = 0.0;
	while (cin) {
	    cout << "Enter an expression (+=*/) :\n";
		Token t = ts.get();
		if (t.kind == 'q') break;
		if (t.kind == ';') cout << " = " << val << endl;
		else ts.putback(t);
		val = expression();
	}
}