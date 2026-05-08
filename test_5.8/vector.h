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
		vector(int size, const T& data = T())
		{
			T* tmp = new T[size];
			//memset(tmp, data, size * sizeof(T));
			for (size_t i = 0; i < size; i++)
			{
				tmp[i] = data;
			}
			_start = tmp;
			_finish = _end_of_storage = _start + size;
		}

		/*~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}*/

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](int pos)
		{
			assert(pos >= 0 && pos < size());
			return *(_start + pos);
		}

		bool empty()
		{
			return _start  == _finish;
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

		void Print();

		void reserve(int x);

		void push_back(const T& val)
		{
			if (_end_of_storage == _finish)
			{
				empty() ? reserve(4 * sizeof(T)) : reserve(2 * size());
			}

			_start[size()] = val;
			++_finish;
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		void erase(iterator first = begin(), iterator last = end())
		{
			assert(first >= begin() && first < end());
			assert(last > first && last <= end());

			while (first != last)
			{
				/**last = *first;
				++first;*/
			}
		}

		void clear()
		{
			_finish = _start;
		}

		void swap(vector<T>& tmp)
		{
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_end_of_storage, tmp.__end_of_storage);
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	// 较长的函数，在类里面声明，类外面实现，但是声明实现需要在同一个文件中，不然会链接错误
	template<class T>
	void vector<T>::reserve(int x)
	{
		if (x > size())
		{
			size_t old_size = size();
			T* tmp = new T(x);
			//memcpy(tmp, _start, old_size * sizeof(T));
			for (size_t i = 0; i < old_size; i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;

			_start = tmp;
			_finish = _start + old_size;
			_end_of_storage = _start + x;
		}
	}

	template<class T>
	void vector<T>::Print()
	{
		for (size_t i = 0; i < size(); i++)
		{
			std::cout << _start[i] << " ";
		}

		std::cout << std::endl;

		for (auto x : *this)
		{
			std::cout << x << " ";
		}

		std::cout << std::endl;
	}

	void test_vector1()
	{
		/*vector<int> v1();
		std::cout << v1.size() << " " << std::endl;*/

		vector<int> v2(3, 3);
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

	void test_vector2()
	{
		vector<int> v1(6, 1);
		vector<int> v2(6);
		v1.Print();

		v1.push_back(2);
		v1.push_back(2);
		//v1.push_back(2);
		//v1.push_back(2);
		//v1.push_back(2);
		v1.Print();

		v1.pop_back();
		v1.Print();

		std::cout << v1[0] << std::endl;
		std::cout << v1.size() << " " << v1.capacity() << std::endl;

		v1.clear();
		v1.Print();
		std::cout << v1.size() << " " << v1.capacity() << std::endl;

	}
}