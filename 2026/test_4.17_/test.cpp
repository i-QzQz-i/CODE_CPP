#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
using namespace std;

// 模版函数（模版是主体）
// 可以推导或是显示实例化
//template<class T>
template<typename T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

// 模版类
// 必须显示实例化
template<typename T>
class A
{
public:
	A(T a, T* pa)
		:_a(a)
		,_pa(pa)
	{ }

	void Print()
	{
		cout << ' ' << ' ' << _a << ' ' << _pa << endl << endl;
	}

private:
	T* _pa = nullptr;
	T _a = 0;
};


int main()
{
	int x1 = 1, y1 = 2;
	double x2 = 1.11, y2 = 2.22;
	char x3 = 'X', y3 = 'Y';
	cout << x1 << ' ' << y1 << "-> ";
	Swap(x1, y1);
	cout << x1 << ' ' << y1 << endl;

	cout << x2 << ' ' << y2 << "-> ";
	Swap(x2, y2);
	cout << x2 << ' ' << y2 << endl;

	cout << x3 << ' ' << y3 << "-> ";
	Swap(x3, y3);
	cout << x3 << ' ' << y3 << endl;
	Swap<char>(x3, y3);
	cout << x3 << ' ' << y3 << endl;

	cout << endl;

	A<int> a1(123, &x1);
	a1.Print();

	A<double> a2(0.1, &x2);
	a2.Print();

	A<char> a3('0', &x3);
	a3.Print();

	cout << endl;

	string s("1324");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}