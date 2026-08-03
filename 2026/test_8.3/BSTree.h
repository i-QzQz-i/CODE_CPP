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
		//delete _left;
		//delete _right;

		_left = nullptr;
		_right = nullptr;
	}

//private:
	T _date;
	BSNode<T>* _left;
	BSNode<T>* _right;
};

template<class K>
class BSTree
{
public:
	using BSNode = BSNode<K>;

	BSTree()
		:_root(nullptr)
	{ }

	BSTree(const K& val)
		
	{ 
		_root = new BSNode(val);
	}

	~BSTree() { }

	void Insert(const K& val)
	{
		if (_root == nullptr)
		{
			_root = new BSNode(val);
			return;
		}

		BSNode* prev = _root;
		BSNode* pcur = _root;

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

		pcur = new BSNode(val);
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

	void Get_InOrder(BSNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Get_InOrder(root->_left);
		cout << root->_date << ' ';
		Get_InOrder(root->_right);
	}

	BSNode* Find(const K& val)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}

		//BSNode<T>* prev = _root;
		BSNode* pcur = _root;

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
				//return true;
				return pcur;
			}
		}

		//return false;
		return nullptr;
	}

	void Erase(const K& val)
	{
		if (_root == nullptr)
		{
			return;
		}

		// 找到val
		//BSNode* pcur = Find(val);
		BSNode* pcur = _root;
		BSNode* parent = pcur;

		while (pcur != nullptr)
		{
			if (pcur->_date > val)
			{
				parent = pcur;
				pcur = pcur->_left;
			}
			else if (pcur->_date < val)
			{
				parent = pcur;
				pcur = pcur->_right;
			}
			else
			{
				break;
			}

		}

		if (parent != nullptr)
		{
			if (pcur->_left == nullptr)  // N = 0 / 1
			{
				if (parent->_left == pcur)
				{
					parent->_left = pcur->_right;
					delete pcur;
				}
				else
				{
					parent->_right = pcur->_right;
					delete pcur;
				}
			}
			else if (pcur->_right == nullptr)
			{
				if (parent->_left == pcur)
				{
					parent->_left = pcur->_left;
					delete pcur;
				}
				else
				{
					parent->_right = pcur->_left;
					delete pcur;
				}
			}
			else  // N = 2
			{
				cout << "暂未实现" << endl;
				return;
			}
		}
	}

private:
	BSNode* _root = nullptr;
};