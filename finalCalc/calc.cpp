#include "var.h"
#include "token.h"
#include "std_lib_facilities.h"

const string prompt = "> ";
const string result = "= ";

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

void solveQuad() {
	int a, b, c;
	cout << "Quadratic equation form:\n" << "ax^2 + bx + c\n"
		<< "Enter a\n" << prompt;
	cin >> a;
	cout << "Enter b\n" << prompt;
	cin >> b;
	cout << "Enter c\n" << prompt;
	cin >> c;

	double discrim = (pow(b, 2) - (4 * a * c));
	if (discrim < 0) {
		cout << "No solution\n";
		cout << "Exiting quadratic solver.\n";
		return;
	}
	else {
		double ans1 = (-b + pow(discrim, 0.5)) / (2 * a);
		double ans2 = (-b - pow(discrim, 0.5)) / (2 * a);
		cout << "The solutions are:\n" << ans1 << endl << ans2 << endl;
		cout << "Exiting quadratic solver.\n";
		return;
	}
}

void calculate(Token_stream& ts) {
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();

			while (t.kind == print)t = ts.get();
			if (t.kind == quit) return;

			if (t.kind == quad) solveQuad();
			else {
				ts.putback(t);
				cout << setprecision(8) << result << statement(ts) << endl;
			}
		}
		catch (exception& e) {
			cerr << e.what() << endl;
			clean_up_mess(ts);
		}
	}
}

void fileio() {
	cout << "Given input file is 'comma2.txt'\n";
	cout << "Given output file is 'output.txt'\n";
	cout << "Enter the input file name: ";
	string iFile;// = "comma2.txt";
	cin >> iFile;
	ifstream ist{ iFile };
	if (!ist) error("can't open input file");

	cout << "Enter the output file name: ";
	string oFile;// = "output.txt";
	cin >> oFile;
	ofstream ost{ oFile };
	if (!ost) error("can't open output file");

	vector <string> text;
	int hour;
	char sep1;
	double temp;
	char sep2;
	double pressure;

	while (ist >> hour >> sep1 >> temp >> sep2 >> pressure) {
		//text.push_back(words);
		cout << hour << " " << temp << " " << pressure << endl;
		ost << hour << "\t" << temp << "\t" << pressure << endl;
	}
}

int main() {
	Token_stream ts;
	try {
		cout << "Enter 'q' to quit\n";
		cout << "Enter 'w' to use quadratic solver or\n";
		cout << "Enter an expression (=+-/%*^) followed by ';'\n";
		calculate(ts);
		return 0;
	}
	catch (...) {
		cerr << "unkown exception \n";
		return 2;
	}
}