#pragma once

#include <iostream>

#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{ }
};

template<class K, typename V> 
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	AVLTree()
	{ }

	AVLTree(const pair<K, V>& kv)
	{ 
		//_root = new AVLTreeNode(const pair<k, v>&kv);
		_root = new Node(kv);
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* tmp = _root;
		Node* newnode = new Node(kv);

		// 判断插入的位置
		while (tmp->_left != nullptr && tmp->_right != nullptr)
		{
			if (kv.first < tmp->_kv.first)
			{
				tmp = tmp->_left;
			}
			else if (kv.first > tmp->_kv.first)
			{
				tmp = tmp->_right;
			}
			else
			{
				return false;
			}
		}

		if (kv.first < tmp->_kv.first)
		{
			tmp->_left = newnode;
			tmp->_bf--;
		}
		else if (kv.first > tmp->_kv.first)
		{
			tmp->_right = newnode;
			tmp->_bf++;
		}
		else
		{
			return false;
		}

		// 不论是否旋转，先正常更新平衡因子
		while (tmp->_bf != 0 && tmp != _root)
		{
			Node* next = tmp;
			int bf = tmp->_bf;

			if (tmp->_parent->_left == tmp)
			{
				tmp->_parent->_bf--;
			}
			else
			{
				tmp->_parent->_bf++;
			}

			tmp = tmp->_parent;

			// 判断是否需要旋转
			if (tmp->_bf == 2 || tmp->_bf == -2)
			{
				
				if (tmp->_left == next)
				{
					// 右单旋
					if (next->_bf == -1)
					{
						RotateR(tmp);
					}
					else // 右左双旋
					{
						RotateRL(tmp);
					}
				}
				else if(tmp->_right == next)
				{
					// 左单旋
					if (next->_bf == 1)
					{
						RotateL(tmp);
					}
					else // 左右双旋
					{
						RotateLR(tmp);
					}
				}
				else
				{
					assert("Insert error!");
				}

				break;
			}
		}

		return true;
	}


private:
	void RotateR(Node* parent)
	{
		Node* kid = parent->_left;
		if (parent == _root)
		{
			_root = kid;
		}
		else if (parent->_parent->_left == parent)
		{
			parent->_parent->_left = kid;
		}
		else
		{
			parent->_parent->_right = kid;
		}
		kid->_parent = parent->_parent;

		if (kid->_right == nullptr)
		{
			kid->_right = parent;
			parent->_parent = kid;
			kid->_bf = parent->_bf = 0;
		}
		else
		{
			kid->_right->_right = parent;
			parent->_parent = kid->_right;
		}
	}

	void RotateL(Node* parent)
	{
		Node* kid = parent->_right;
		if (parent == _root)
		{
			_root = kid;
		}
		else if (parent->_parent->_left == parent)
		{
			parent->_parent->_left = kid;
		}
		else
		{
			parent->_parent->_right = kid;
		}
		kid->_parent = parent->_parent;

		if (kid->_right == nullptr)
		{
			kid->_left = parent;
			parent->_parent = kid;
			kid->_bf = parent->_bf = 0;
		}
		else
		{
			kid->_left->_left = parent;
			parent->_parent = kid->_left;
		}
	}

	void RotateRL(Node* parent)
	{
		Node* tmp = parent->_left;
		RotateR(parent);
		RotateL(tmp);
	}

	void RotateLR(Node* parent)
	{
		Node* tmp = parent->_right;
		RotateR(parent);
		RotateL(tmp);
	}

private:
	Node* _root = nullptr;
};