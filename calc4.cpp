#include "std_lib_facilities.h"

const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';

const string prompt = "> ";
const string result = "= ";

const vector <char> symbols { print, quit,'-', '+', '*', '/', '(', ')', '%' };

class Token {
public:
	char kind;
	double value;

};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
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

	case print: 
	case quit: 
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
		return Token{ number, val };
	}
	default:
		return Token{ ch };
	}
}

void Token_stream::ignore(char c) {
	// c is token kind to look for
	//first check buffer:
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	//now search input:
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

void print_token(Token t) {
	if (t.kind == number){
		cout << "A number token with val = " << t.value << endl;
	}
	else if (find(symbols.begin(), symbols.end(), t.kind) != symbols.end()) {
		cout << "A token of kind " << t.kind << endl;
	}
	//else if (t.kind == '(' || t.kind == ')' || t.kind == '+' || t.kind == '-' || t.kind == '*' || t.kind == '/' || t.kind == '%') {
	//	cout << "A token of kind " << t.kind << endl;
	//}
	else if (t.kind == quit || t.kind == print) {
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
	case number: // 8 represents number
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
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
	//double right = term();
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
			//double d = term();
			//if (right == 0) error("divide by zero");
			left /= term();
			t = ts.get();
			print_token(t);
			break;
		case '%':
			left = fmod(left, term());
			t = ts.get();
			print_token(t);
			break;
		/*case '%':
			double d = primary();
			if (d == 0) error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;*/
		default:
			ts.putback(t);
			return left;
		}
	}
}

void clean_up_mess() {
	ts.ignore(print);
	/*while (true) {
		Token t = ts.get();
		if (t.kind == print) return;
	}*/
}

void calculate() {
	cout << "Enter 'q' to quit\n";
	cout << "Enter an expression (+=/%*) followed by ';'\n";
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();

			while (t.kind == print)t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << expression() << '\n';
		}
		catch (exception& e) {
			cerr << e.what() << endl;
			clean_up_mess();
		}		
	}
}

int main() {
	calculate();
	/*double val = 0.0;
	cout << "Enter an expression (+=/*) :\n" << prompt;
	while (cin) {
		Token t = ts.get();
		//while (t.kind == print) t = ts.get();
		if (t.kind == quit) {
			return 0;
			//break;
		}
		else if (t.kind == print) {
			cout << result << val << "\n> ";
		}
		else {
			ts.putback(t);
		}
		val = expression();
		cout << "here";

	}*/
}