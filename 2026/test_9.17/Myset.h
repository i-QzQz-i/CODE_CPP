#pragma once

#include "RBTree.h"

namespace QzQz
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

	public:

		typedef RBTree<K, K, SetKeyOfT>* iterator;

		set()
		{ 
			_root = new RBTree<K, K, SetKeyOfT>();
		}

		set(const pair<K, K>& kv)
		{
			_root = new RBTree<K, K, SetKeyOfT>(kv);
		}

		pair<bool, K> insert(const K& v)
		{
			return _root->Insert(v);
		}

		iterator begin()
		{

		}

		iterator end()
		{

		}

	private:
		RBTree<K, K, SetKeyOfT>* _root;
	};
}








