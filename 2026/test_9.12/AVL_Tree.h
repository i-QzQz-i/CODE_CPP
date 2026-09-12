#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <time.h>

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
public:
	typedef AVLTreeNode<K, V> Node;

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
		while (tmp)
		{
			if (tmp->_left != nullptr && kv.first < tmp->_kv.first)
			{
				tmp = tmp->_left;
			}
			else if (tmp->_right != nullptr && kv.first > tmp->_kv.first)
			{
				tmp = tmp->_right;
			}
			else
			{
				break;
			}
		}

		// 开始插入
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
		newnode->_parent = tmp;

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

	Node* Find(const K& key)
	{	 
		Node* tmp = _root;
		while (tmp)
		{
			if (key < tmp->_kv.first)
			{
				tmp = tmp->_left;
			}
			else if (key > tmp->_kv.first)
			{
				tmp = tmp->_right;
			}
			else 
			{
				return tmp;
			}
		}

		return nullptr;
	}

	int Height()
	{
		return _Height(_root);
	}

	bool IsBalanceTree()
	{
		return _IsbalanceTree(_root);
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

		parent->_right = subRL;
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
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if(bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void Get_InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		Get_InOrder(root->_left);
		cout << root->_kv.first << endl;
		Get_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int left = _Height(root->_left);
		int right = _Height(root->_right);

		return left > right ? left+1 : right+1;
	}

	bool _IsbalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int LHight = _Height(root->_left);
		int RHight = _Height(root->_right);
		int diff = RHight - LHight;

		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}

		if(root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return _IsbalanceTree(root->_left) && _IsbalanceTree(root->_right);
	}
private:
	Node* _root = nullptr;
};