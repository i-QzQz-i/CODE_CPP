#pragma once

#include <iostream>

using namespace std;

// 若不为空，根节点大（于）左小右
template<class T>
struct BSNode
{
public:
	BSNode(const T& date)
		:_date(date)
		,_left(nullptr)
		,_right(nullptr)
	{ }

	~BSNode()
	{
		/*delete _left;
		delete _right;

		_left = nullptr;
		_right = nullptr;*/
	}

//private:
	T _date;
	BSNode<T>* _left;
	BSNode<T>* _right;
};

template<class T>
class BSTree
{
public:
	BSTree()
		:_root(nullptr)
	{ }

	BSTree(const T& val)
		
	{ 
		_root = new BSNode<T>(val);
	}

	~BSTree() { }

	void Insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new BSNode<T>(val);
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

		pcur = new BSNode<T>(val);
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
		Get_InOrder(_root);
		cout << endl;
	}

	void Get_InOrder(BSNode<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Get_InOrder(root->_left);
		cout << root->_date << ' ';
		Get_InOrder(root->_right);
	}

	bool Find(const T& val)
	{
		if (_root == nullptr)
		{
			return false;
		}

		//BSNode<T>* prev = _root;
		BSNode<T>* pcur = _root;

		while (pcur)
		{
			//prev = pcur;

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
				return true;
			}
		}

		return false;
	}

	void Erase()
	{

	}

private:
	BSNode<T>* _root = nullptr;
};