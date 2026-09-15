#pragma once
// 红黑树特性：
// 1.节点非黑即红  2.根节点为黑  3.不会存在两个红节点相连  4.最长的路径最多是最短路径的两倍

#include <iostream>
#include <cassert>	//#include <assert.h>
#include <map>
#include <set>

using namespace std;

namespace QzQz
{
	enum Colour
	{
		Red,   // 0
		Black  // 1
	};

	template<class date>
	struct RBTreeNode
	{
		date _date;

		RBTreeNode* _parent;
		RBTreeNode* _left;
		RBTreeNode* _right;

		Colour _col;
		//int col = 0
		RBTreeNode(const date& d, Colour col = Red)
			: _date(d)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(col)
		{ }
	};

	template<class K, class V, class KeyOfT>
	class RBTree
	{
		template<class T1, class T2>
		struct Compare
		{
			T1& operator<(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
			{
				return p1.first < p2.first;
			}
		};

	public:
		//typedef RBTreeNode<V> Node;
		using Node = RBTreeNode<V>;	// C++11

		RBTree()
		{ }

		RBTree(const V& v)
		{
			_root = new Node(v);
		}

		pair<bool, V> Insert(const V& v)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv, Black);
				return pair<bool, V>(bool, v);
			}

			Node* tmp = _root;
			Node* newnode = new Node(v);
			//Node* ret = newnode;

			// 判断插入的位置
			while (tmp)
			{
				if (tmp->_left != nullptr && KeyOfT(v) < KeyOfT(tmp->_date))
				{
					tmp = tmp->_left;
				}
				else if (tmp->_right != nullptr && KeyOfT(tmp->_date) < KeyOfT(v))
				{
					tmp = tmp->_right;
				}
				else
				{
					break;
				}
			}

			// 开始插入
			if (KeyOfT(v) < KeyOfT(tmp->_date))
			{
				tmp->_left = newnode;
			}
			else if (KeyOfT(tmp->_date) < KeyOfT(v))
			{
				tmp->_right = newnode;
			}
			else
			{
				return false;
			}
			newnode->_parent = tmp;

			// 检查是否需要变色/旋转
			// 当两个红节点相连
			while (tmp != nullptr && tmp->_col == Red)
			{
				Node* grand = tmp->_parent;
				Node* uncle;
				int flag;

				if (grand->_left == tmp)
				{
					uncle = grand->_right;
					flag = 0;
				}
				else
				{
					uncle = grand->_left;
					flag = 1;
				}

				if (uncle != nullptr && uncle->_col == Red) // 仅变色
				{
					tmp->_col = uncle->_col = Black;
					if (grand != _root)
						grand->_col = Red;

					newnode = tmp->_parent;
					if (tmp == _root)
						break;
					else
						tmp = tmp->_parent->_parent;

				}
				else if (uncle == nullptr || uncle->_col == Black) // 旋转 + 变色
				{
					//判断单双旋
					if ((tmp->_left == newnode && flag == 0) // 单旋
						|| (tmp->_right == newnode && flag == 1))
					{
						if (flag == 0) // 右单旋
						{
							RotateR(grand);
						}
						else // 左单旋
						{
							RotateL(grand);
						}

						tmp->_col = Black;
						grand->_col = Red;

						newnode = tmp->_parent;
						if (tmp == _root)
							break;
						else
							tmp = tmp->_parent->_parent;
					}
					else // 双旋
					{
						if (flag == 0)
						{
							RotateLR(grand); // 左右双旋
						}
						else
						{
							RotateRL(grand); // 右左双旋
						}

						newnode->_col = Black;
						grand->_col = Red;

						newnode = tmp->_parent;
						if (tmp == _root)
							break;
						else
							tmp = tmp->_parent->_parent;
					}

					//break;
				}
				else
				{
					assert(false);
				}

			}

			_root->_col = Black;

			IsBalanceTree();
			return pair<bool, V>(true, v);
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
			return _IsbalanceTree();
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
		}

		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			RotateR(subR);
			RotateL(parent);

		}

		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

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

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int left = _Height(root->_left);
			int right = _Height(root->_right);

			return left > right ? left + 1 : right + 1;
		}

		bool Check(Node* root, int blackNum, const int refNum)
		{
			if (root == nullptr)
			{
				// 前序遍历走到空时，意味着一条路径走完了
				//cout << blackNum << endl;
				if (refNum != blackNum)
				{
					cout << "存在黑色结点的数量不相等的路径" << endl;
					return false;
				}
				return true;
			}
			// 检查孩子不太方便，因为孩子有两个，且不一定存在，反过来检查父亲就方便多了
			if (root->_col == Red && root->_parent->_col == Red)
			{
				cout << root->_kv.first << "存在连续的红色结点" << endl;
				return false;
			}

			if (root->_col == Black)
			{
				blackNum++;
			}

			return Check(root->_left, blackNum, refNum)
				&& Check(root->_right, blackNum, refNum);
		}

		bool _IsbalanceTree()
		{
			if (_root == nullptr)
				return true;

			if (_root->_col == Red)
				return false;

			// 参考值
			int refNum = 0;
			Node* cur = _root;
			// 走完一条路的黑色节点
			while (cur)
			{
				if (cur->_col == Black)
				{
					++refNum;
				}
				cur = cur->_left;
			}

			return Check(_root, 0, refNum);
		}

	private:
		Node* _root = nullptr;
	};

}







