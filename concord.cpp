#include "std_lib_facilities.h"

int main() {
	cout << "Enter words to be ordered with frequency:\n";

	vector < string > text;
	for (string word; cin >> word;)
		text.push_back(word);
	
	sort(text);

	int counter = 0;
	string curr = "";
	bool first = true;

	cout << endl;

	for (int i = 0; i < text.size(); i++) {
		if (text[i] != curr) {
			cout << text[i] << ": ";
			curr = text[i];
			counter = 1;
			if (i == text.size() || text[i + 1] != curr) {
				cout << counter << endl;
			}
		}
		else {
			counter++;
			if (i == text.size() - 1 || text[i + 1] != curr) {
				cout << counter << endl;
			}
		}		
	}

	cout << endl;

	keep_window_open();
	return 0;
}