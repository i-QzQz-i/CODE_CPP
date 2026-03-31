#pragma once

#include <iostream>
//using namespace std;

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

	void Print();

	int GetMonth();

	//赋值运算符重载
	Date& operator=(const Date& date);

	//重载 += 运算符
	Date& operator+=(int x);

	//重载 == 运算符
	Date& operator==(int x);

	//重载 + 运算符


private:
	int _year;
	int _month;
	int _day;
};
