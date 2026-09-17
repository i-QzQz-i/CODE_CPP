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

		typedef RBTree<K, pair<K, V>, MapKeyOfT>* iterator;

		map()
		{ 
			_root = new RBTree<K, pair<K, V>, MapKeyOfT>();
		}

		map(const pair<K, V>& kv)
		{
			_root = new RBTree<K, pair<K, V>, MapKeyOfT>(kv);
		}

		pair<pair<K, V>, bool> insert(const pair<K, V>& kv)
		{
			return _root->Insert(kv);
		}

	private:
		//RBTree<K, pair<K, V>, MapKeyOfT>* _root;
		RBTree<K, pair<K, V>, MapKeyOfT>* _root;
	};
}








