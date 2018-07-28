#pragma once
#include "std_lib_facilities.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
	class Invalid {};

	Date(int y, Month m, int d);
	Date();
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
	int year() const;
	int month() const;
	int day() const;

	//bool isLeapYear() const;

	friend ostream& operator<<(ostream& os, const Date& d);
	friend istream& operator>>(istream& is, Date& d);

	Date& operator++();   //pre
	Date operator++(int); //post

	Date& operator--();   //pre
	Date operator--(int); //post
private:
	//bool isValid();
	int y, d;
	Month m;
};

bool isLeapYear(int y);
bool isValid(const Date& curr);

istream& operator>>(istream& is, Month& m);
//ostream& operator<<(ostream& os, const Date& d);
//istream& operator>>(istream& is, const Date& d);

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
