#define _CRT_SECURE_NO_WARNINGS 
// RAII(Resource Acquisition Is Initialization)：一种资源管理类的设计思想
// 

#include <iostream>
#include <memory>
using namespace std;

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}
	~SmartPtr()
	{
		cout << "delete[] " << _ptr << endl;
		delete[] _ptr;
	}

	// 重载运算符，模拟指针的行为，方便访问资源
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator[](size_t i)
	{
		return _ptr[i];
	}
private:
	T* _ptr;
};

double Divide(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Divide by zero condition!";
	}
	else
	{

		return (double)a / (double)b;
	}
}

void Func()
{
	// 使用RAII的智能指针类管理new出来的数组以后，程序简单多了
	SmartPtr<int> sp1 = new int[10];
	SmartPtr<int> sp2 = new int[10];
	for (size_t i = 0; i < 10; i++)
	{
		sp1[i] = sp2[i] = i;
	}
	int len, time;
	cin >> len >> time;
	cout << Divide(len, time) << endl;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	return 0;
}
