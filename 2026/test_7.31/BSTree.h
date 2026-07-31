#pragma once

#include <iostream>

using namespace std;

// 若不为空，根节点大（于）左小右
template<class T>
struct BSNode
{
	BSNode(const T& date)
		:_date(date);
		,_left(nullptr)
		,_right(nullptr)
	{ }

	~BSNode()
	{
		delete _left;
		delete _right;
	}

public:
	T _date;
	BSNode<T>* _left;
	BSNode<T>* _right;
};

template<class T>
class BSTree
{
private:
	//BSTree()

	BSTree(const T& val)
		//:_root(nullptr)
	{ 
		_root = new BSNode<T>*(val);
	}

	~BSTree() { }

	void Insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new BSNode<T>*(val);
			return;
		}

		BSNode<T>* prev = _root;
		BSNode<T>* pcur = _root;

		while (pcur)
		{
			prev = pcur;

			if (pcur->_date > val)
			{
				pcur = pcur->_left;
			}
			else if (pcur->_date < val)
			{
				pcur = pcur->_right;
			}
			else
			{
				return;
			}
		}

		pcur = new BSNode<T>*(val);
		if (prev->_date > val)
		{
			prev->_left = pcur;
		}
		else
		{
			prev->_right = pcur;
		}

		return;
	}

	void InOrder()
	{

	}

	bool Find()
	{
		if(_root)


		while ()
		{
			BSTree* cur = _root;
			if ()
			{

			}

		}
	}

public:
	BSNode<T>* _root = nullptr;
};