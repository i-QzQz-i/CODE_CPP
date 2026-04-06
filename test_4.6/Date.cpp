#define _CRT_SECURE_NO_WARNINGS 

#include "Date.h"
//using namespace DA;

void Date::CheckDate(const Date& date) const
{
	if ((_month > 12 || _month < 1) || (_day > 31 || _day < 1))
	{
		cout << "日期非法 >>> ";
		date.Print();
	}
}


Date::Date(int year, int month, int day)
	: _year(year)
	, _month(month)
	, _day(day)
{
	/*_year = year;
	_month = month;
	_day = day;*/

	CheckDate(*this);
}

Date::Date(const Date& date)
	:_year(date._year)
	,_month(date._month)
	,_day(date._day)
{
	/*_year = date._year;
	_month = date._month;
	_day = date._day;*/

	CheckDate(*this);
}

Date::~Date()
{
	//std::cout << "~Date" << std::endl;
	;
}

void Date::Print() const
{
	std::cout << this->_year << "/" << _month << "/" << _day << std::endl;
}

int Date::GetMonth() const
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
	if (x < 0)
	{
		return *this -= -x;
	}

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

//重载 + 运算符
Date Date::operator+(int x) const
{
	Date tmp = *this;
	tmp += x;

	return tmp;
}

//重载 -= 运算符
Date& Date::operator-=(int x)
{
	if (x < 0)
	{
		return *this += -x;
	}

	_day -= x;
	while (_day <= 0)
	{
		if (_month != 1)
		{
			--_month;
		}
		else
		{
			--_year;
			_month = 12;
		}
		_day += GetMonth();
	}

	return *this;
}

//重载 - 运算符
Date Date::operator-(int x) const
{
	Date tmp = *this;
	tmp -= x;

	return tmp;
}

//重载 ++d
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

//重载 d++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

//重载 --d
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

//重载 d--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if(_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::operator<=(const Date& d) const
{
	return ((*this < d) || (*this == d));
}

bool Date::operator==(const Date& d) const
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator>(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator>=(const Date& d) const
{
	return ((*this > d) || (*this == d));
}

// d1 - d2
int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int size = 0;
	while (min != max)
	{
		++min;
		++size;
	}

	return size * flag;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年份：";
	cin >> d._year;
	cout << "请输入月份："; 
	cin >> d._month;
	cout << "请输入日期：";
	cin >> d._day;
	d.CheckDate(d);
	return in;
}

ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << std::endl;
	return out;
}




