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
		set()
		{ }

		set(const pair<K, K>& kv)
		{
			_root = new RBTree<K, K>(kv);
		}

		pair<K, V> insert(const pair<K, K>& kv)
		{
			return _root->Insert(kv);
		}

	private:
		RBTree<K, K, SetKeyOfT>* _root;
	};
}








