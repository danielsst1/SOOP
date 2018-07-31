#include "vars.h"
#include "tokens.h"
#include "std_lib_facilities.h"

const string prompt = "> ";
const string result = "= ";

//const vector <char> symbols{ invalid, name, print, quit,'-', '+', '*', '/', '(', ')', '%' };

double expression(Token_stream& ts);
double term(Token_stream& ts);
double expon(Token_stream& ts);
double primary(Token_stream& ts);
//tester:
void print_token(const Token& t);

double statement(Token_stream& ts) {
	Token t = ts.get();
	if (t.kind == name) {
		Token var = t;

		t = ts.get();
		if (t.kind == '=') {
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}
		else if (t.kind == print) {
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression(ts);
	}
	ts.putback(t);
	return expression(ts);
}

//controls function of operations
double expression(Token_stream& ts) {
	double left = term(ts);
	//double right = term();
	Token t = ts.get();

	print_token(t);
	while (true) {
		switch (t.kind) {
		case '+':
			left += term(ts);
			t = ts.get();
			print_token(t);
			break;
		case '-':
			left -= term(ts);
			t = ts.get();
			print_token(t);
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term(Token_stream& ts) {
	double left = expon(ts);
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= expon(ts);
			t = ts.get();
			break;
		case '/':
		{
			double d = expon(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = expon(ts);
			if (d == 0) error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

double expon(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();
	if (t.kind == power) {
		double d = primary(ts);
		return pow(left, d);
	}
	else {
		ts.putback(t);     // put t back into the token stream
		return left;
	}
}

double primary(Token_stream& ts) {
	Token t = ts.get();
	print_token(t);
	switch (t.kind) {
	case '(': // handle expression
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error(" ')' expected");
		return d;
	}
	case number:
		return t.value; // return value of num
	case '-':
		return -primary(ts);
	case '+':
		return primary(ts);
	case name:
		return get_value(t.name);
	default:
		error("Primary expected");
	}
	return 0.0;
}

//uncomment to test
void print_token(const Token& t) {
	//if (t.kind == number) {
	//	cout << "A number token with val = " << t.value << endl;
	//}
	//else if (find(symbols.begin(), symbols.end(), t.kind) != symbols.end()) {
	//	cout << "A token of kind " << t.kind << endl;
	//}
	//else if (t.kind == quit || t.kind == print) {
	//	//intentional blank
	//}
	//else {
	//	cout << "We received an invalid token of kind " << t.kind << endl;
	//}
}

void clean_up_mess(Token_stream& ts) {
	ts.ignore(print);
}

void calculate(Token_stream& ts) {
	cout << "Enter 'q' to quit\n";
	cout << "Enter an expression (=+-/%*^) followed by ';'\n";
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();

			while (t.kind == print)t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << setprecision(8) << result << statement(ts) << endl;
		}
		catch (exception& e) {
			cerr << e.what() << endl;
			clean_up_mess(ts);
		}
	}
}

int main() {
	Token_stream ts;
	try {
		calculate(ts);
		return 0;
	}
	catch (...) {
		cerr << "unkown exception \n";
		return 2;
	}
}