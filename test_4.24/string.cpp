#define _CRT_SECURE_NO_WARNINGS 

#include "string.h"
	
namespace QzQz
{
	const size_t string::npos = -1;

	/*void test1()
	{
		string s1("123");
		string s2;
		std::cout << s2.c_str() << std::endl;
		std::cout << s1.c_str() << std::endl;

		std::cout << s1.size() << "  " << s1.capacity() << std::endl;
	}*/

	void test2()
	{
		string s1("123");
		string::iterator it = s1.begin();
		string::iterator end = s1.end();
		std::cout << *it << "  " << *(end - 1) << std::endl;
		std::cout << std::endl;

		while (it < end)
		{
			std::cout << *it << " ";
			++it;
		}

		std::cout << std::endl;

		// 实现迭代器就能使用范围for，侧面证明范围for底层就是迭代器
		for (auto x : s1)
		{
			std::cout << x << " ";
			++x;
		}

	}

	void string::reserve(size_t x)
	{
		if (x <= _capacity)
			return;

		char* tmp = new char[x + 1] {'\0'};
		memcpy(tmp, _str, _size + 1);
		delete[] _str;
		_str = tmp;

		_capacity = x;
	}

	char string::operator[](size_t x)
	{
		assert(x < _size);
		return *(_str + x);
	}

	void string::push_back(const char c)
	{
		if (_size + 1 > _capacity)
			_size != 0 ? reserve(2 * _size) : reserve(4);

		_str[_size] = c;
		++_size;
	}

	void string::append(const char* s)
	{
		size_t len = strlen(s);
		if (_size + len > _capacity)
			_size != 0 ? reserve(2 * (_size + len)) : reserve(_size + len);

		//strcat(_str, s);
		for (int i = len + 1; i > 0; i--)
		{
			_str[_size] = *s;
			++s;
			++_size;
		}
		_size += len;
	}

	void string::operator+=(const char c)
	{
		push_back(c);
	}

	void string::operator+=(const char* s)
	{
		append(s);
	}

	void string::insert(size_t pos, const char c)
	{
		assert(pos < _size);
		
	}

	void string::insert(size_t pos, const char* s)
	{
		assert(pos < _size);

	}
}







