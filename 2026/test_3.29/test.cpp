#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;
namespace QzQz
{
	int Q = 6;
}

class Capacity
{
public:
	inline void Add(int a = 1, int b = -1)
	{
		cout << a << "     " << b << endl;
	}

	void Add(double a, double b = 2.2)
	{
		cout << a << "     " << b << endl;
	}

	void Add(int a, double b)
	{
		cout << a << "     " << b << endl;
	}

	Capacity(int year = 1, int month = 1, int day = 1, char p = 'm')
	{
		_year = year;
		_month = month;
		_day = day;
		_p = (char*)malloc(sizeof(char*));
		*_p = p;
	}

	/*Capacity()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}*/

	~Capacity()
	{
		free(_p);
		_p = nullptr;
	}

	void Print()
	{
		cout << this->_year << "/" << _month << "/" << _day << endl;
		//cin >> i;
		//cout << i << endl;
	}


private:
	double _i;
	int _year;
	int _month;
	int _day;
	char* _p;

//protected:
};


int main()
{
	//cout << "hello world" << endl;
	//std::cout << "hello world!!!" << std::endl;
	
	int a = 0;
	int b = 1;
	//char Q = 'Q';
	//double c = 6.6;
	////cin >> a >> b >> c;
	//cout << a << " " << Q << "  " << c << "\n";

	//cout << QzQz::Q << endl;

	//Add();
	
	//Add(a, c);
	//Add(3.3, 9.9);

	//int& ra = a;
	//cout << ra << endl;

	//ra = 5;
	//cout << ra << endl;
	//cout << a << endl;

	//const int& cra = a;
	//cout << cra << endl;
	//a = 8;
	//cout << cra << endl;

	//const int cc = 10;
	////int& rcc = cc;
	//const int& crcc = cc;
	//cout << cc << endl;
	//cout << crcc << endl;

	//cin >> ra;
	//cout << a << endl;

	/*Capacity op1;
	Capacity op2;

	op1.Add(1.1);
	op1.DateInis(2026, 3, 28);
	op2.DateInis(2026, 3, 33);

	op1.Print();
	op2.Print();

	cout << sizeof(op1) << endl;*/

	//char* p = NULL;
	//char* pi = nullptr;

	///*int* tmp = p;
	//int* tmpi = pi;*/

	//char* tmp = (char*)p;
	//char* tmpi = (char*)pi;

	//cout << &p << "  " << &pi << endl;

	Capacity op1(2, 2, 2, 'a');
	Capacity op2;

	op1.Add(1.1);
	//op1.DateInis(2026, 3, 28);
	//op2.DateInis(2026, 3, 33);

	op1.Print();
	op2.Print();

	cout << sizeof(op1) << endl;

	int m = 0;
	int& rm = m;

	return 0;
}