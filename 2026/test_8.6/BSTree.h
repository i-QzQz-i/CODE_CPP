#pragma once

#include <iostream>

using namespace std;

namespace Key
{
	// 若不为空，根节点大（于）左小右
	template<class T>
	struct BSNode
	{
	public:
		BSNode(const T& date)
			:_date(date)
			, _left(nullptr)
			, _right(nullptr)
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

		BSTree(const BSTree& x)
		{
			//_root = x._root;
			_root = Get_Node(x._root);
		}

		BSNode* Get_Node(BSNode* x)
		{
			if (x == nullptr)
			{
				return nullptr;
			}

			BSNode* r = new BSNode(x->_date);

			r->_left = Get_Node(x->_left);
			r->_right = Get_Node(x->_right);

			return r;
		}

		~BSTree() // 后序遍历释放
		{
			Free_Node(_root);
			_root = nullptr;
		}

		void Free_Node(BSNode* x)
		{
			if (x == nullptr)
			{
				return;
			}

			Free_Node(x->_left);
			Free_Node(x->_right);
			delete x;
		}

		BSTree& operator=(BSTree x)
		{
			swap(_root, x._root);
			
			return *this;
		}

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

		bool Erase(const K& val)
		{
			/*if (_root == nullptr)
			{
				return;
			}*/

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

			// 开始删除
			if (pcur != nullptr)
			{
				if (pcur->_left == nullptr)  // N = 0 / 1
				{
					if (parent->_left == pcur)
					{
						parent->_left = pcur->_right;
					}
					else if (parent->_right == pcur)
					{
						parent->_right = pcur->_right;
					}
					else // pcur == _root
					{
						_root = pcur->_right;
					}

					delete pcur;
					return true;
				}
				else if (pcur->_right == nullptr)
				{
					if (parent->_left == pcur)
					{
						parent->_left = pcur->_left;
					}
					else if (parent->_right == pcur)
					{
						parent->_right = pcur->_left;
					}
					else // pcur == _root
					{
						_root = pcur->_left;
					}

					delete pcur;
					return true;
				}
				else  // N = 2（找到删除节点左子树后的最大值(一直往右)，或右子树后的最小值(一直往左)）
				{
					// 选择找右实现
					BSNode* tmp_p = pcur;
					BSNode* tmp = pcur->_right;

					while (tmp->_left)
					{
						tmp_p = tmp;
						tmp = tmp->_left;
					}

					pcur->_date = tmp->_date;
					if (tmp_p->_right == tmp)
					{
						tmp_p->_right = tmp->_right;
					}
					else
					{
						tmp_p->_left = tmp->_right;
					}

					delete tmp;
					return true;
				}
			}

			return false;
		}

	private:
		BSNode* _root = nullptr;
	};
}

namespace KeyValue
{
	// 若不为空，根节点大（于）左小右
	template<class K, class V>
	struct BSNode
	{
	public:
		BSNode(const K& date, const V& val)
			:_date(date)
			,_value(val)
			, _left(nullptr)
			, _right(nullptr)
		{ }

		~BSNode()
		{
			//delete _left;
			//delete _right;

			_left = nullptr;
			_right = nullptr;
		}

		//private:
		K _date;
		V _value;
		BSNode<K, V>* _left;
		BSNode<K, V>* _right;
	};

	template<class K, class V>
	class BSTree
	{
	public:
		using BSNode = BSNode<K, V>;

		//BSTree() = default;

		BSTree()
			:_root(nullptr)
		{ }

		BSTree(const K& key, const V& value)
		{
			_root = new BSNode(key, value);
		}

		BSTree(const BSTree& x)
		{
			//_root = x._root;
			_root = Get_Node(x._root);
		}

		BSNode* Get_Node(BSNode* x)
		{
			if (x == nullptr)
			{
				return nullptr;
			}

			BSNode* r = new BSNode(x->_date, x->_value);

			r->_left = Get_Node(x->_left);
			r->_right = Get_Node(x->_right);

			return r;
		}

		~BSTree() // 后序遍历释放
		{
			Free_Node(_root);
			_root = nullptr;
		}

		void Free_Node(BSNode* x)
		{
			if (x == nullptr)
			{
				return;
			}

			Free_Node(x->_left);
			Free_Node(x->_right);
			delete x;
		}

		BSTree& operator=(BSTree x)
		{
			swap(_root, x._root);

			return *this;
		}

		void Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new BSNode(key, value);
				return;
			}

			BSNode* prev = _root;
			BSNode* pcur = _root;

			while (pcur)
			{
				prev = pcur;

				if (pcur->_date > key)
				{
					pcur = pcur->_left;
				}
				else if (pcur->_date < key)
				{
					pcur = pcur->_right;
				}
				else
				{
					return;
				}
			}

			pcur = new BSNode(key, value);
			if (prev->_date > key)
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
			cout << root->_date << ":" << root->_value << " ";
			Get_InOrder(root->_right);
		}

		BSNode* Find(const K& key)
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

				if (pcur->_date > key)
				{
					pcur = pcur->_left;
				}
				else if (pcur->_date < key)
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

		bool Erase(const K& key)
		{
			/*if (_root == nullptr)
			{
				return;
			}*/

			// 找到val
			//BSNode* pcur = Find(val);
			BSNode* pcur = _root;
			BSNode* parent = pcur;

			while (pcur != nullptr)
			{
				if (pcur->_date > key)
				{
					parent = pcur;
					pcur = pcur->_left;
				}
				else if (pcur->_date < key)
				{
					parent = pcur;
					pcur = pcur->_right;
				}
				else
				{
					break;
				}
			}

			// 开始删除
			if (pcur != nullptr)
			{
				if (pcur->_left == nullptr)  // N = 0 / 1
				{
					if (parent->_left == pcur)
					{
						parent->_left = pcur->_right;
					}
					else if (parent->_right == pcur)
					{
						parent->_right = pcur->_right;
					}
					else // pcur == _root
					{
						_root = pcur->_right;
					}

					delete pcur;
					return true;
				}
				else if (pcur->_right == nullptr)
				{
					if (parent->_left == pcur)
					{
						parent->_left = pcur->_left;
					}
					else if (parent->_right == pcur)
					{
						parent->_right = pcur->_left;
					}
					else // pcur == _root
					{
						_root = pcur->_left;
					}

					delete pcur;
					return true;
				}
				else  // N = 2（找到删除节点左子树后的最大值(一直往右)，或右子树后的最小值(一直往左)）
				{
					// 选择找右实现
					BSNode* tmp_p = pcur;
					BSNode* tmp = pcur->_right;

					while (tmp->_left)
					{
						tmp_p = tmp;
						tmp = tmp->_left;
					}

					pcur->_date = tmp->_date;
					if (tmp_p->_right == tmp)
					{
						tmp_p->_right = tmp->_right;
					}
					else
					{
						tmp_p->_left = tmp->_right;
					}

					delete tmp;
					return true;
				}
			}

			return false;
		}

	private:
		BSNode* _root = nullptr;
	};
}
