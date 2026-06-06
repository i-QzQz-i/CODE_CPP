#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

namespace QzQz
{
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector() {}
		vector(int size, T type)
		{
			T* tmp = new T[size]{ type };
			_start = tmp;
			_finish = _end_of_storage = _start + size;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		T& operator[](int pos)
		{
			assert(pos >= 0 && pos < size());
			return *(_start + pos);
		}

		iterator& begin()
		{
			return _start;
		}

		iterator& end()
		{
			return _finish;
		}

		const_iterator& begin() const
		{
			return _start;
		}

		const_iterator& end() const
		{
			return _finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	void test1()
	{
		/*vector<int> v1();
		std::cout << v1.size() << " " << std::endl;*/

		vector<int> v2(3, 0);
		std::cout << v2.size() << " " << v2.capacity() << std::endl;
		//std::cout << v2[1] << std::endl;

		for (size_t i = 0; i < v2.size(); i++)
		{
			std::cout << v2[i] << " " ;
		}

		std::cout << std::endl;

		for (auto x : v2)
		{
			std::cout << x << " ";
		}

		std::cout << std::endl;

		vector<int>::iterator it = v2.begin();
		while (it != v2.end())
		{
			std::cout << *it << " ";
			it++;
		}
	}
}