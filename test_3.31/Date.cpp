#define _CRT_SECURE_NO_WARNINGS 

#include "Date.h"
//using namespace DA;

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& date)
{
	_year = date._year;
	_month = date._month;
	_day = date._day;
}

Date::~Date()
{
	std::cout << "~Date" << std::endl;
}

void Date::Print()
{
	std::cout << this->_year << "/" << _month << "/" << _day << std::endl;
}

int Date::GetMonth()
{
	static int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
	{
		return 29;
	}

	return Month[_month];
}

//赋值运算符重载
Date& Date::operator=(const Date& date)
{
	if (this != &date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}

	return *this;
}

//重载 += 运算符
Date& Date::operator+=(int x)
{
	_day += x;
	while (_day > GetMonth())
	{
		_day -= GetMonth();
		if (_month != 12)
		{
			_month++;
		}
		else
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//重载 == 运算符
Date& Date::operator==(int x)
{
	return *this;
}