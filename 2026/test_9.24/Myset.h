#pragma once

#include "RBTree.h"

namespace QzQz
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k) const
			{
				return k;
			}
		};

	public:
		//因为不知道 RBTree<>::Iterator 是变量还是类型，需加typename表明他是类型
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator; 
		typedef typename RBTree<K, const K, SetKeyOfT>::Const_Iterator const_iterator;

		set()
			:_t()
		{ }

		set(const pair<K, K>& kv)
			:_t(kv)
		{ }

		/*pair<iterator, bool> insert(const K& v)
		{
			return _t.Insert(v);
		}*/

		pair<iterator, bool> insert(const K& v)
		{
			return _t.Insert(v);
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

	private:
		//RBTree<K, const K, SetKeyOfT>* _root;
		RBTree<K, const K, SetKeyOfT> _t;
		// 因为_t与红黑树生命周期完全绑定，直接对象可以自动构造析构，所以没有必要使用指针
	};
}








