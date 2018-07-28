#include "std_lib_facilities.h"
#include "date.h"

const Month mDefault = Month(12);
const int dDefault = 30;
const int yDefault = 1998;

Vector <int> lastDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Vector <int> lastDayLeap = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Vector <string> names = { "", "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };

Date::Date(int y, Month m, int d) :y(y), m(m), d(d) {
	if (!isValid(*this)) {
		throw Invalid{};
	}
}

Date::Date(): y(yDefault), m(mDefault), d(dDefault){}

void Date::add_day(int n) {
	for (int i = 0; i < n; i++)	++*this;
	//check if day is not in month
}

void Date::add_month(int n) {
	int mth = int(m) + n;
	if (mth > 12) {
		int yrs = int(mth / 12); //yrs to add
		y += yrs;
		mth = mth % 12;
	}
	m = (Month(mth));
	//check if last day is beyond new month
	if (d > lastDay[int(m)]) d = lastDay[int(m)];
}

void Date::add_year(int n) {
	y+= n;
	//check for leap year day
	if (int(m) == 2 && d == 29) {
		if (isLeapYear(y)) d = lastDayLeap[int(m)];
		else d = lastDay[int(m)];
	}
}

int Date::year() const {return y;}

//Month Date::month(){
int Date::month() const{return int(m);}

int Date::day() const{return d;}

//bool Date::isValid() {
bool isValid(const Date& curr) {
	//invalid month
	if (int(curr.month()) < 1 || int(curr.month()) > 12) return false;
	//day is less than 1
	if (curr.day() < 1) return false;
	//day is greater than month allows
	if (isLeapYear(curr.year())) { if (curr.day() > lastDayLeap[int(curr.month())]) return false; }
	else { if (curr.day() > lastDay[int(curr.month())]) return false; }
	return true;
}

//bool Date::isLeapYear() const
bool isLeapYear(int y){
	if ((y % 4 == 0) && (y % 100) != 0 || (y % 400) == 0) return true;
	return false;
}

Date& Date::operator++() //pre
{
	d++;
	//check if day is not in month
	if (!isValid(*this)) {
		//check if last day of dec
		if (int(m) == 12) {
			m = Month::jan;
			d = 1;
			y++;
		}
		else {
			int next = int(m) + 1;
			m = (Month(next));
			d = 1;
		}
	}
	return *this;
}

Date Date::operator++(int)//post
{
	Date day = *this;
	++*this;
	return day;
}

Date& Date::operator--() //pre
{
	d--;
	//check if day is not in month
	if (!isValid(*this)) {
		//check if first day of jan
		if (int(m) == 1) {
			m = Month::dec;
			//d = 
			y--;
		}
		else {
			int next = int(m) + 1;
			//if (next > 12) next = 1;
			m = (Month(next));
		}
	}
	return *this;

	int next = int(m) - 1;
	if (next > 12) next = 1;
	m = (Month(next));
	return *this;
}

Date Date::operator--(int)//post
{
	Date day = *this;
	--*this;
	return day;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << names[d.month()] << " " << d.day() << ", " << d.year();
}

istream& operator>>(istream& is, Date& dd){
	//is >> d.m >> d.d >> d.y;
	int y, m, d;
	is >> m >> d >> y;
	dd = Date(y, Month(m), d);
	return is;
}

istream& operator>>(istream& is, Month& m){
	int val;

	if (is >> val) {
		switch (val) {
		case 1: case 2: case 3: case 4: case 5: case 6: 
		case 7: case 8: case 9: case 10: case 11: case 12:
			m = Month(val); break;
		default:
			throw out_of_range("Invalid value for Month");
		}
	}
	return is;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	if (lhs.year() == rhs.year() && lhs.month() == rhs.month() && lhs.day() == rhs.day()) {
		return true;
	}
	return false;
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}