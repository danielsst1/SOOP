#include "std_lib_facilities.h"

const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';
const char invalid = 'i';
const char power = '^';
const char mod = '%';
const char quad = 'w';

const vector <char> symbols{ print, quit, quad, '-', '+', '*', '/', '(', ')', '%' };

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind{ ch } {}
	Token(char ch, double val) :kind{ ch }, value{ val } {}
	Token(char ch, string n) :kind{ ch }, name{ n } {}
};

class Token_stream {
public:
	Token get();
	Token get(char ch);
	void putback(Token t);
	Token popback();
	void ignore(char c);
private:
	vector<Token> buffer;
};