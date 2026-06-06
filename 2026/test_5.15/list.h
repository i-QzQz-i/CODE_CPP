#pragma once

#include <iostream>
#include <list>
#include <assert.h>

namespace QzQz
{
	template<class T>
	struct list_node
	{
		typedef list_node<T> Node;
		T _data;
		Node* _next;
		Node* _prev;

		list_node(const T& x = T()) : _data(x){ }
	};

	template<class T>
	struct list_iterator
	{
		typedef list_iterator<T>* iterator;
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T>* iterator;

		list()
		{
			Node* tmp = new Node;
			_head = tmp;
			_head->_next = _head->_prev = _head;
		}

		void push_back(const T& x)
		{
			Node* tmp = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;

			++_size;
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size = 0;
	};


	void test_list1()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		std::cout << lt.size() << std::endl;
	}

}