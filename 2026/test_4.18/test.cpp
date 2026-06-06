#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
using namespace std;

// auto(自动识别类型)
namespace Auto
{
	// 传参不能使用auto
	//void func1(auto x)
	//{
	//	;
	//}

	// 谨慎使用auto作返回值
	auto func(char x)
	{
		if (x >= 'a' && x <= 'z')
			return x;
		else
			return (x += 1);
	}

	void using_auto()
	{
		char a = '1';
		auto a1 = a;
		auto a2 = a1 + 1;

		cout << "a=" << a << " a1=" << a1 << " a2=" << a2 << endl;
		//cout << func(a1) << endl;


		int x = 0;
		cout << "int x = " << x << " :" << &x << endl;
		auto& _x = x;
		cout << "auto& _x = " << _x << " :" << &_x << endl;
		auto* px = &x;
		cout << px << endl;


		int y = 1;
		// 连续声明变量时不能为不同的类型
		//auto i = x, j = a;
		auto i = x, j = y;
		cout << i << "  " << j << endl;

		// 不能 直接 用来声明数组
		//auto arr[] = { a , a1, a2 };
	}
}


// 范围for(遍历容器)
namespace For
{
	void using_for()
	{
		int array[] = { 1, 2, 3, 4 };
			// 正常遍历
		for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
			cout << (array[i] *= 2) << " ";

		cout << endl;

			// 用范围for遍历
		for (auto x : array)
			cout << (x *= 2) << " ";

		cout << endl;

		// 可见改变范围for不会改变原数组
		for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
			cout << array[i] << " ";

		cout << endl << endl;

		//char str[] = "hello world";
		string str("hello world");

		//cout << str.length() << " " << str.size() << endl;

			// 正常遍历
		for (int i = 0; i < str.size(); i++)
			cout << str[i];

		cout << endl;

			// 用范围for遍历
		for (char x : str)
			cout << (x += 1);
		cout << endl;
		for (int i = 0; i < str.size(); i++)
			cout << str[i];

		cout << endl;

			// 用迭代器遍历
		string::iterator it = str.begin();
		while (it != str.end())
		{
			cout << (*it += 1);
			++it;
		}

		cout << endl;

		for (int i = 0; i < str.size(); i++)
			cout << str[i];
			
	}
}

// 探索string
void using_strng()
{
	string str("hello world");
	string s("");
	//string str("hello");
	str += "!";
	cout << str << endl;
	// 均不包含'\0'
	cout << str.length() << " " << str.size() << endl;
	cout << str.capacity() << endl;

	// 查看扩容
	/*int capacity = str.capacity();
	for (int i = 0; i < 100; i++)
	{
		str += "x";
		if (str.capacity() != capacity)
		{
			capacity = str.capacity();
			cout << capacity << endl;
		}
	}*/

	// 判空
	/*if (!str.empty())
		cout << str << endl;
	else
		cout << "empty" << endl;

	if (!s.empty())
		cout << s << endl;
	else
		cout << "empty" << endl;

	str.clear();

	if (!str.empty())
		cout << str << endl;
	else
		cout << "empty" << endl;*/

	// 预留空间
	/*str.reserve(100);
	cout << str.capacity() << endl;*/

	// 调整大小
	/*str.resize(11);
	cout << str << endl;
	cout << str.capacity() << endl;

	s.resize(20, 'x');
	cout << s << endl;
	cout << s.capacity() << endl;*/

	// 尾插字符（串）(是+=不好用吗)
	str.push_back('!');
	cout << str << endl;
	str += '!';
	cout << str << endl;

	str.append("xxx");
	cout << str << endl;
	str += "666";
	cout << str << endl;

	//cin << s;
	s += ('1' - '0');
	cout << (int)s[0] << endl;

	string sum = { "" };
	cout << sum << endl;
}

int main()
{
	//Auto::using_auto();

	//For::using_for();

	using_strng();

	return 0;
}