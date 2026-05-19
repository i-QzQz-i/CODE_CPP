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

		list_node(const T& data = T())
			: _data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{ }
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node) : _node(node) {}
		/*list_iterator(Self& self)
		{
			_node = self._node;
		}*/

		Ref operator*() const
		{
			return _node->_data;
		}

		Ptr operator->() const
		{
			return &(_node->_data);
		}

		// Ç°ÖÃ++
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// ºóÖÃ++
		Self operator++(int)
		{
			Node* tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Node* tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

		void empty_init()
		{
			Node* tmp = new Node;
			_head = tmp;
			_head->_next = _head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(list& lt)
		{
			empty_init();

			for (auto x : lt)
			{
				push_back(x);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list& operator=(list tmp)
		{
			swap(tmp);
			return *this;
		}

		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next;
		}

		iterator end()
		{
			//return iterator(_head);
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			//return _head->_next = _head;
			return _size == 0;
		}

		void insert(iterator pos, const T& val)
		{
			//assert(pos);

			Node* prev = pos._node->_prev;
			Node* tmp = new Node(val);
			
			tmp->_next = pos._node;
			tmp->_prev = prev;
			prev->_next = tmp;
			pos._node->_prev = tmp;

			++_size;
		}

		void push_back(const T& x)
		{
			/*Node* tmp = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;

			++_size;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void erase(iterator first, iterator last)
		{
			//assert(_size > 0);

			Node* it = first._node;
			//Node* prev = first._node;
			//Node* next = last._node;

			first._node->_prev->_next = last._node;
			last._node->_prev = first._node->_prev;

			while (it != last._node)
			{
				Node* tmp = it;
				it = it->_next;
				delete tmp;
				--_size;
			}
		}

		void erase(iterator pos)
		{
			assert(pos != end());
			assert(_size > 0);

			--_size;

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
		}
		
		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(list& tmp)
		{
			std::swap(tmp._head, _head);
			std::swap(tmp._size, _size);
		}

	private:
		Node* _head;
		size_t _size = 0;
	};

	struct AA
	{
		int _a1 = 1;
		int _a2 = 1;
	};

	template<class Container>
	void print_container(const Container& lt)
	{
		for (const auto& x : lt)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	void test_list1()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_front(9);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << "  ";
			++it;
		}
		std::cout << std::endl;

		lt.insert(++lt.begin(), 0);
		lt.insert(--lt.end(), 0);

		for (int x : lt)
		{
			std::cout << x << "  ";
		}
		std::cout << std::endl;

	
		lt.pop_back();
		lt.pop_front();
		lt.pop_back();
		lt.pop_front();
		lt.erase(lt.begin(), lt.end());

		for (int x : lt)
		{
			std::cout << x << "  ";
		}
		std::cout << std::endl;

		std::cout << lt.size() << std::endl;
	}

	void test_list2()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << "  ";
			++it;
		}
		std::cout << std::endl;

		list<AA> lta;
		AA aa;
		lta.push_back(aa);
		lta.push_back(aa);
		lta.push_back(aa);
		lta.push_back(aa);
		lta.push_back(AA());

		list<AA>::iterator ita = lta.begin();
		while (ita != lta.end())
		{
			//std::cout << ita._node->_data._a1 << ":" << ita._node->_data._a2;
			std::cout << ita->_a1 << ":" << ita->_a2;
			++ita;
			std::cout << std::endl;
		}
		std::cout << std::endl;

		//print_container(lt);
	}

	void test_list3()
	{
		list<int> lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		std::cout << lt.size() << std::endl;
		print_container(lt);

		//lt.clear();

		list<int> lt1(lt);
		std::cout << lt1.size() << std::endl;
		print_container(lt1);

		list<int> lt2;
		for (int i = 10; i > 0; --i)
		{
			lt2.push_back(i);
		}
		std::cout << lt2.size() << std::endl;
		print_container(lt2);

		lt1 = lt2;
		std::cout << lt1.size() << std::endl;
		print_container(lt1);
		std::cout << lt2.size() << std::endl;
		print_container(lt2);

		std::cout << std::endl;

		lt.swap(lt2);
		std::cout << lt.size() << std::endl;
		print_container(lt);
		std::cout << lt2.size() << std::endl;
		print_container(lt2);
	}
}