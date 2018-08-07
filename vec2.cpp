#define _SCL_SECURE_NO_WARNINGS

#include "std_lib_facilities.h"

//using namespace std;

class vect {
public:
	vect(int s) : sz{ s }, elem{ new double[s] } {}

	vect(const vect& arg)
		// allocate space, then initialize via copy
		:sz{ arg.sz }, elem{ new double[arg.sz] }
	{
		copy(arg.elem, arg.elem + arg.sz, elem);  // from std lib
	}

	~vect() { delete[] elem; }

	double& operator[](int n) { return elem[n]; }

	//double get(int i) { return elem[i]; }
	//void set(int i, double d) { elem[i] = d; }
private:
	int sz;
	double* elem;
};

void f(int n) {
	vect v(3);
	v[2] = 2.2;//v.set(2, 2.2);
	vect v2 = v;
	v[2] = 9.9;//v.set(1, 9.9);
	v2[0] = 8.8;//v2.set(0, 8.8);
	cout << v[0] << ' ' << v2[1];
	//cout << v.get(0) << ' ' << v2.get(1);
}

int main() {
	int i = 0;
	while (i < 10000) {
		f(10);
		i++;
	}
}