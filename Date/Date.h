#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
  Date(int year = 1900,int month = 1,int day = 1);
  bool operator>(const Date& d)const;
  bool operator<(const Date& d)const;
  bool operator>=(const Date& d)const;
  bool operator<=(const Date& d)const;
  bool operator==(const Date& d)const;
  bool operator!=(const Date& d)const;
  int Getmonthday(int year,int month);
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
  friend istream& operator>>(istream &is,Date &d);
  friend ostream& operator<<(ostream &os,Date &d);
private:
  int _year;
  int _month;
  int _day;
};
