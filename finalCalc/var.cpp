#include "var.h"
#include "std_lib_facilities.h"

//const char invalid = 'i';
//const char name = 'a';
//const char number = '8';
//const char quit = 'q';
//const char print = ';';
//const int digits = 8; //precision of output
//
//const string prompt = "> ";
//const string result = "= ";
//
//const vector <char> symbols{ invalid, name, print, quit,'-', '+', '*', '/', '(', ')', '%' };

vector <Variable> var_table;

double get_value(string s) {
	for (Variable var : var_table)
		if (var.name == s) return var.value;
	return 0.0;
}

void set_value(string s, double d) {
	for (Variable& var : var_table)
		if (var.name == s) {
			var.value = d;
			return;
		}
	var_table.push_back(Variable{ s, d });
}