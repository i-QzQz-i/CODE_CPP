#pragma once

#include <iostream>
using namespace std;

//namespace DA
//{
//	
//};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);

	Date(const Date& date);

	~Date();

	//检测日期合法性
	void CheckDate(const Date& date) const;

	// void Date::Print(const Date* const this);
	void Print() const;

	int GetMonth() const;

	//赋值运算符重载
	Date& operator=(const Date& date);

	// //重载 == 运算符
	//Date& operator==(int x) const;

	//重载 += 运算符
	Date& operator+=(int x);

	//重载 + 运算符
	Date operator+(int x) const;

	//重载 -= 运算符
	Date& operator-=(int x);

	//重载 - 运算符
	Date operator-(int x) const;

	//重载 ++d
	Date& operator++();

	//重载 d++
	Date operator++(int);

	//重载 --d
	Date& operator--();

	//重载 d--
	Date operator--(int);

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d ) const;

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	//友元声明
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);

	// d1 - d2
	int operator-(const Date& d) const;

private:
	int _year = 2;
	int _month = 2;
	int _day = 2;
};

//重载输入输出
istream& operator>>(istream& in, Date& d);
ostream& operator<<(ostream& out, const Date& d);