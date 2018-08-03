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

	double get(int i) { return elem[i]; }
	void set(int i, double d) { elem[i] = d; }

	/*vect& operator=(const vect& a) {
		double* p = new double[a.sz];
		copy(a.elem, a.elem + a.sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}*/
private:
	int sz;
	double* elem;
};

//vect::vect(const vect& arg)
//// allocate space, then initialize via copy
//	:sz{ arg.sz }, elem{ new double[arg.sz] }
//{
//	copy(arg.elem, arg.elem + arg.sz, elem);  // from std lib
//}
//
//vect& vect::operator=(const vect& a) {
//	double* p = new double[a.sz];
//	copy(a.elem, a.elem + a.sz, p);
//	delete[] elem;
//	elem = p;
//	sz = a.sz;
//	return *this;
//}

void f(int n) {
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	cout << v.get(0) << ' ' << v2.get(1);
}

int main() {
	//while (true) f(10);
	int i;
	while (i < 10000) {
		f(10);
		i++;
	}
}