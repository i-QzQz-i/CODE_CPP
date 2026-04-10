#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

class A
{
public:
	A(int a1, int a2) 
		: _a1(a1)
		, _a2(a2)
	{
		size++;
		cout << "A(int a1, int a2)" << endl;
	}

	A(int a1)
		: _a1(a1)
		//, _a2(a2)
	{
		size++;
		cout << "A(int a1)" << endl;
	}

	A()
	{
		size++;
		cout << "A()" << endl;
	}

	A(A& a)
		: _a1(a._a1)
		, _a2(a._a2)
	{
		//size += (size + 1);
		cout << "A(A& a)" << endl;
	}

	~A()
	{
		cout << "~A" << endl;
	}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}

	int Get_a()
	{
		return _a1 + _a2;
	}
	
	static int size;
private:
	int _a1 = 0;
	int _a2 = 0;
	
};
int A::size = 0;

class B
{
public:
	B(A& a)
		: _b(Creat_b(a))
	{
		A::size++;
		cout << "b(int b)" << endl;
	}

	~B()
	{
		cout << "~B" << endl;
	}

	int Creat_b(A& a)
	{
		return a.Get_a() * 2;
	}

	void Print()
	{
		cout << _b << endl;
	}

private:
	int _b = 0;
	
};

class C
{
public:
	C(int c)
		:_c(c)
	{
	}

	void Print(int x)
	{
		cout << _c << endl;
		cout << x << endl;
	}

	int Get()
	{
		return _c;
	}

	class D
	{
	public:
		D(int d)
			:_d(d)
		{}

		void Ddd(C& c)
		{
			c.Print(_d);
			cout << c._c + 100 << endl;
		}

		
	private:
		int _d;
	
	};

private:
	int _c = 0;

};

int main()
{
	/*A a(2);
	a.Print();
	A aa = {3, 3};
	aa.Print();

	B b(a);
	b.Print();*/

	//cout << endl << A::size << endl;
	/*cout << endl << a.size << endl;*/
	//cout << endl << A().size << endl;

	C c(1);
	c.Print(c.Get());
	cout << endl;

	c.Print(6);
	cout << endl;

	C::D d(9);
	d.Ddd(c);
	cout << endl;

	cout << sizeof(C) << endl;
	cout << sizeof(C::D) << endl;

	return 0;
}
