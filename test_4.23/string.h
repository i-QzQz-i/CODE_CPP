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
		string()
			:_str(new char('\0'))
			, _size(0)
			, _capacity(0)
		{
			//_str = new char[1] {'\0'};
		}

		string(const char* str)
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
			_size = 0;
			_capacity = 0;
		}

		/*void Print()
		{
			std::cout << _str << std::endl;
		}*/

		const char* c_str() const
		{
			return _str;
		}



	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	void test1();
}
