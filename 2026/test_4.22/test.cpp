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
void using_strng2()
{
	string str("hello world");
	string s("0");

	// 串的最大长度
	size_t x = str.max_size();
	cout << x << endl;
	cout << s.max_size() << endl;
	
	// 
	cout << str.npos << endl;
	cout << s.npos << endl;

	// 重新分配内存，可为新分配的内存一个初始赋值
	/*str.resize(5);
	str.resize(10, '+');
	cout << str << endl;*/

	// 在pos位置插入字符串
	str.insert(0, "123");
	cout << str << endl;

	// 从pos位置开始清除字符串（左闭右闭区间）
	// str.erase(0, str.npos);
	str.erase(1, 2);
	cout << str << endl;

	/*str.pop_back();
	cout << str << endl;*/

	// 替换字符串的值（左闭右开）
	str.replace(0, 1, "xxx");
	cout << str << endl;
	cout << s << endl;

	// 交换两个字符串（其实是交换指针，所以性能消耗小）
	/*str.swap(s);
	cout << "str: " << str << endl;
	cout << "s: " << s << endl;*/

	// 返回c形式的常量字符串
	const char* p = str.c_str();
	cout << p << endl;
	cout << str << endl;

	// 正向查找字符、字符串
	size_t pos1 = str.find('o', 0);
	cout << pos1 << endl;
	size_t pos5 = str.find('o', 8);
	cout << pos5 << endl;
	size_t pos2 = str.find("ll", 0);
	cout << pos2 << endl;

	// 反向查找字符、字符串
	size_t pos3 = str.rfind('o', str.npos);
	cout << pos3 << endl;
	size_t pos4 = str.rfind("ll", str.size());
	cout << pos4 << endl;

	//cout << str.find_first_of("adoo", 0) << endl;

	// 从pos位置开始截取n个数据并返回（左闭右开）
	string sx = str.substr(0,13);
	cout << sx << endl;
}

int main()
{
	//Auto::using_auto();

	//For::using_for();

	//using_strng1();
	using_strng2();

	return 0;
}