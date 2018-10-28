#pragma once

#include <iostream>

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	bool operator>(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	int Getmonthday(int year, int month);
	void print();
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	Date& operator+=(int days);
	Date& operator-=(int days);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};