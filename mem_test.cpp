#include "std_lib_facilities.h"

int main() {
	int i = 0;
	while (true) {
		double* dptr = new double[1000];
		cout << "Loop " << i << endl;
		cout << "dptr[0] = " << dptr[0] << endl;
		i++;
	}
}
//Loop 252441
//dptr[0] = -6.27744e+66