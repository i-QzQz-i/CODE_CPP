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
		T _data = 0;
		Node* _next;
		Node* _prev;

		list_node() { }
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		list()
		{
			Node* tmp = new Node;
			_head = tmp;
			_head->_next = _head->_prev = _head;
		}

		void push_back(T& x)
		{
			;
		}

	private:
		Node* _head;
	};


	void test_list1()
	{
		list<int> lt;
	}

}