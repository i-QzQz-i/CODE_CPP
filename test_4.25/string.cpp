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

	char& string::operator[](size_t x)
	{
		assert(x < _size);
		return *(_str + x);
	}

	void string::push_back(char c)
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
		const char* tmp = s;
		for (size_t i = len; i > 0; i--)
		{
			_str[_size] = *tmp;
			++tmp;
			++_size;
		}
	}

	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}

	string& string::operator+=(const char* s)
	{
		append(s);
		return *this;
	}

	void string::insert(size_t pos, const char c)
	{
		assert(pos <= _size);
		if(_size + 1 > _capacity)
			_size != 0 ? reserve(2 * _size) : reserve(4);

		for (size_t i = _size; i > pos; i--)
		{
			_str[i] = _str[i - 1];
		}

		++_size;
		_str[pos] = c;
	}

	void string::insert(size_t pos, const char* s)
	{
		assert(pos <= _size);
		size_t len = strlen(s);
		if (_size + len > _capacity)
			_size != 0 ? reserve(2 * (_size + len)) : reserve(_size + len);

		for (size_t i = _size + len - 1; i > pos; i--)
		{
			_str[i] = _str[i - len];
		}

		const char* tmp = s;
		size_t pos_t = pos;
		while (pos_t < pos + len)
		{
			_str[pos_t++] = *tmp;
			++tmp;
		}
		_size += len;
	}

	void string::clear()
	{
		delete[] _str;
		_str = new char[1] {'\0'};
		_size = _capacity = 0;
	}

	void string::erase(size_t pos, size_t end)
	{
		assert(pos < _size && pos <= end);
		if (end >= _size)
			end = _size - 1;

		size_t len = end - pos + 1;
		size_t pos_t = pos;
		_size -= len;
		while (pos_t < _size + len && end != _size)
		{
			_str[pos_t] = _str[pos_t + len];
			pos_t++;
		}

		_str[pos_t] = '\0';
	}
}







