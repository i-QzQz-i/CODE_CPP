#pragma once

#include "RBTree.h"

namespace QzQz
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		map()
		{ }

		map(const pair<K, V>& kv)
		{
			_root = new RBTree<K, V>(kv);
		}

		pair<K, V> insert(const pair<K, V>& kv)
		{
			return _root->Insert(kv);
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT>* _root;
	};
}








