#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>

using namespace std;

namespace QzQz
{
	template<class T>
	class base
	{
	public:
		base()
		{
			cout << "base()" << " " << endl;
		}

		void print()
		{
			cout << x << endl;
		}

	protected:
		T x = 1;
	};

	// 普通类继承类模版，须指定模版参数
	class A : public base<int>
	{
	public:
		A()
		{
			cout << "A()" << endl;
		}

		void print()
		{
			//base<int>::print();
			base<int>::print();
		}
	};

	// 类模版继承
	template<typename T>
	class B : public base<T>
	{
	public:
		B()
		{
			cout << "B()" << endl;
		}

		void print()
		{
			base<T>::print();
		}

		void func()
		{
			//cout << this->x << endl;
			cout << base<T>::x << endl;
		}
	};

}

using namespace QzQz;

int main()
{
	A a;
	B<double> b;

	a.print();

	b.print();

	b.func();

	return 0;
}








