#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

class A
{
public:
	A(int a, int* p)
		:_a1(a)
		, pa(p)
	{
		// cout << "A(int a, int* p)" << endl;
		printf("A(int %d,int* %p)\n", a, p);
	}

	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		delete[] pa;
		cout << "~A()" << endl;
	}

private:
	int _a1 = 0;
	int* pa = nullptr;
};



int main()
{
	int* p1 = nullptr;
	cout << p1 << endl;
	p1 = new int(10);
	cout << p1 << endl;
	cout << *p1 << endl << endl;

	char* p2 = new char[12] {"hello world"};
	cout << p2 << endl << endl;

	// A a(1, p1);
	A a(0, nullptr);
	//A* ptr_a = new A(1,p1);
	A* ptr_arr = new A[10];


	delete p1;
	delete[] p2;
	//delete ptr_a;
	delete[] ptr_arr;

	//int* p1 = nullptr;
	//cout << p1 << endl;

	//// operator new 与 malloc 用法相同，其实底层就是调用malloc
	//p1 = (int*)operator new(sizeof(int));
	////p1 = (int*)operator new(1);
	//*p1 = 123456789;
	//cout << p1 << endl;
	//cout << *p1 << endl;

	//// 底层是free
	//operator delete(p1);

	return 0;
}