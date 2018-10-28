#include "Date.h"

int Date::Getmonthday(int year, int month)
{
	const int day[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	return day[month];
}

Date::Date(int year, int month, int day)
{
	if (year > 0
		&& month > 0 && month < 13
		&& day > 0 && day <= Getmonthday(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else{
		std::cout << "error" << std::endl;
	}
}
bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& d)const
{
	if (_year == d._year
		&& _month == d._month
		&& _day == d._day)
	{
		return true;
	}
	return false;
}

bool Date::operator<=(const Date& d)const
{
	return!(*this > d);
}

bool Date::operator>=(const Date& d)const
{
	return (*this > d || *this == d);
}

bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

void Date::print()
{
	std::cout << _year << "-" << _month << "-" << _day << std::endl;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int days)
{
	if (days < 0)
	{
		*this -= -days;
	}
	_day = _day + days;
	while (_day>Getmonthday(_year, _month))
	{
		_day = _day - Getmonthday(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int days)
{
	Date ret(*this);
	ret += days;
	return ret;
}

Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		*this += -days;
	}
	_day = _day - days;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_day = _day + Getmonthday(_year, 12);
		}
		else{
			_day = _day + Getmonthday(_year, _month - 1);
		}
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
	}
	return *this;
}

Date Date::operator-(int days)
{
	Date ret(*this);
	ret -= days;
	return ret;

}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date ret = *this;
	ret += 1;
	return ret;
}

Date& Date::operator--()//pos--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)//last--
{
	Date ret = *this;
	ret -= 1;
	return ret;
}
