#pragma once
#include <iostream>
#include <string>
#include <assert.h>

namespace QzQz
{
	class string
	{
	public:
		// 声明与定义需分离，但一些短小函数直接实现在声明类中，inline内联使用

		//string()
		//	:_str(new char[1] {'\0'})
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	//_str = new char[1] {'\0'};
		//	//_str = new char('\0')
		//}

		string(const char* str = "") // 常量字符串后默认有 '\0'
		{
			size_t x = strlen(str);
			_str = new char[x + 1];
			memcpy(_str, str, x + 1);
			// 指向'\0'的位置
			_size = x;
			_capacity = x;	
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		/*void Print()
		{
			std::cout << _str << std::endl;
		}*/

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			/*if (_size == 0)
				return true;
			else
				return false;*/

			//return _size == 0 ? true : false;

			return _size == 0;
		}

		// 天然(原生指针)迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// 扩容
		void reserve(size_t x);

		char& operator[](size_t x);


		// 尾插
		void push_back(char c);

		void append(const char* s);

		string& operator+=(char c);
		string& operator+=(const char* s);

		// 在pos位置插入
		void insert(size_t pos, const char c);
		void insert(size_t pos, const char* s);

		// 清理字符串
		void clear();
		void erase(size_t pos, size_t end = npos);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	//public:
		// 可以在声明处定义，但最好不要这样做，因为只有整形可以（被特殊处理了），其他类型不行
		//const static size_t npos = -1;
		const static size_t npos;
	};

	// 不能在这定义
	//const size_t string::npos = -1;

	void test1();

	void test2();
}


