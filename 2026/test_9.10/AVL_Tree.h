#pragma once

#include <iostream>
#include <vector>
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
					else // 左右双旋
					{
						RotateLR(tmp);
					}
				}
				else if(tmp->_right == next)
				{
					// 左单旋
					if (next->_bf == 1)
					{
						RotateL(tmp);
					}
					else // 右左双旋
					{
						RotateRL(tmp);
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

	void InOrder()
	{
		Get_InOrder(_root);
	}


private:
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent == _root)
		{
			_root = subL;
		}
		else if (parent->_parent->_left == parent)
		{
			parent->_parent->_left = subL;
		}
		else
		{
			parent->_parent->_right = subL;
		}
		subL->_parent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_left = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (parent == _root)
		{
			_root = subR;
		}
		else if (parent->_parent->_left == parent)
		{
			parent->_parent->_left = subR;
		}
		else
		{
			parent->_parent->_right = subR;
		}
		subR->_parent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		RotateR(subR);
		RotateL(parent);
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		RotateL(subL);
		RotateR(parent);
	}

	void Get_InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		Get_InOrder(root->_left);
		cout << root->_kv.first << endl;
		Get_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};