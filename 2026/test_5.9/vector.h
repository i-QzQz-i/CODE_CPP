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

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < size());
			return *(_start + pos);
		}

		bool empty() const
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

		void Print(); //iterator first = begin(), iterator last = end()

		void reserve(size_t x);

		iterator insert(iterator pos, const T& val);

		void resize(size_t x, const T val = T());

		void push_back(const T& val)
		{
			if (_end_of_storage == _finish)
			{
				empty() ? reserve(4) : reserve(2 * size());
			}

			//_start[size()] = val;
			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		/*void erase(iterator first, iterator last)
		{
			assert(first >= begin() && first < end());
			assert(last > first && last <= end());

			iterator pcur = last;
			iterator prv = first;
			while (pcur != end());
			{
				*prv = *pcur;
				++prv, ++pcur;
			}

			_finish -= (last - first);
		}*/

		void clear()
		{
			_finish = _start;
		}

		void swap(vector<T>& tmp)
		{
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_end_of_storage, tmp._end_of_storage);
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	// 较长的函数，在类里面声明，类外面实现，但是声明实现需要在同一个文件中，不然会链接错误
	template<class T>
	void vector<T>::reserve(size_t x)
	{
		assert(x >= 0 && x < 1000000);
		if (x > capacity())
		{
			size_t old_size = size();
			T* tmp = new T[x];
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

	template<typename T>
	typename vector<T>::iterator vector<T>::insert(iterator pos, const T& val)
	{
		assert(pos >= begin() && pos <= end());
		if (_end_of_storage == _finish)
		{
			empty() ? reserve(4) : reserve(2 * size());
		}

		vector<T>::iterator it = end();
		while (it != pos)
		{
			
			*it = *(it - 1);
			--it;
		}

		*it = val;
		++_finish;
		return (it + 1);
	}

	template<class T>
	void vector<T>::resize(size_t x, T val)
	{
		assert(x >= 0 && x < 1000000);
		if (x > size())
		{
			reserve(x);
			for (size_t i = size(); i < x; i++)
			{
				push_back(val);
			}
		}
		else
		{
			_finish -= (size() - x);
		}
	}

	template<typename T>
	void vector<T>::Print()//iterator first, iterator last
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

	template<class T>
	void Printf(vector<T>& v)
	{
		for (auto x : v)
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

		//std::cout << v1[0] << std::endl;
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;

		v1.clear();
		v1.Print();
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;

		v2.Print();
		std::cout << "v2.size:" << v2.size() << "  " << "v2.capacity:" << v2.capacity() << std::endl;

		v1.swap(v2);
		v1.Print();
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;

		v2.Print();
		std::cout << "v2.size:" << v2.size() << "  " << "v2.capacity:" << v2.capacity() << std::endl;
	}

	void test_vector3()
	{
		vector<int> v1(4,1);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		
		v1.reserve(1);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;

		v1.reserve(6);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;

		v1.Print();

		//typename vector<int>::iterator pos = v1.insert(v1.begin() + 2, 0);
		auto pos = v1.insert(v1.begin() + 2, 0);
		v1.insert(v1.end() - 1, 0);
		v1.Print();

		std::cout << pos << std::endl;
		//Printf(v1);

	}

	void test_vector4()
	{
		vector<char> v1(5, 'x');

		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		v1.Print();

		v1.resize(10);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		v1.Print();

		v1.resize(15, 'y');
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		v1.Print();

		/*v1.resize(3);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		v1.Print();*/

		//v1.erase(v1.begin(),v1.begin() + 1);
		std::cout << "v1.size:" << v1.size() << "  " << "v1.capacity:" << v1.capacity() << std::endl;
		v1.Print();
	}
}