#pragma once

#include "RBTree.h"

namespace QzQz
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator; //RBTreeNode<V>*
		//因为不知道 RBTree<>::Iterator 是变量还是类型，需加typename表明他是类型		
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
		{
		}

		map(const pair<K, V>& kv)
			:_t(kv)
		{
		}

		/*pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}*/

		pair<pair<const K, V>, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
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

	private:
		//RBTree<K, pair<const K, V>, MapKeyOfT>* _root;
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
		// 因为_t与红黑树生命周期完全绑定，直接对象可以自动构造析构
	};
}








