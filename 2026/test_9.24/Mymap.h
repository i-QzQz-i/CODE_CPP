#pragma once

#include "RBTree.h"

namespace QzQz
{
	// map比set多实现一个[]
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv) const
			{
				return kv.first;
			}
		};

		struct Compare
		{
			bool operator() (const pair<const K, V>& kv1, const pair<const K, V>& kv2)  const
			{
				return kv1.first < kv2.first;
			}

			bool operator() (const K& k1, const K& k2)  const
			{
				return k1 < k2;
			}
		};

	public:
		//因为不知道 RBTree<>::Iterator 是变量还是类型，需加typename表明他是类型
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator; //RBTreeNode<V>*
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Const_Iterator const_iterator;


		/*map()
		{ 
			RBTree<K, pair<const K, V>, MapKeyOfT> _t();
		}

		map(const pair<K, V>& kv)
		{
			RBTree<K, pair<const K, V>, MapKeyOfT> _t(kv);
		}*/

		map()
			:_t()
		{ }

		map(const pair<K, V>& kv)
			:_t(kv)
		{ }

		/*pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}*/

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& k)
		{
			return _t.Find(k);
		}

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		void Print()
		{
			_t.InOrder();
		}

		/*iterator operator[](pair<const K, V>& kv)
		{
			iterator it = find(kv);
			if (!(it->first))
			{
				insert(it._node);
			}
			
			return it;
		}*/

		V& operator[](const K& k)
		{
			iterator it = find(k);
			if (it == end())
			{
				auto ret = insert(pair<const K, V>(k, V()));
				it = ret.first;
			}
			                    // Node* data
			return it->second; // (&_node->_data)->second

		}

	private:
		//RBTree<K, pair<const K, V>, MapKeyOfT>* _root;
		RBTree<K, pair<const K, V>, MapKeyOfT, Compare> _t;
		// 因为_t与红黑树生命周期完全绑定，直接对象可以自动构造析构，所以没有必要使用指针
	};
}








